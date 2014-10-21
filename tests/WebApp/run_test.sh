#!/bin/bash
# Note: All parameters are optional

##### PARAMETERS #####
cd /home/jcarrera/Desktop/BoxingExperience/WebApp
# iii. DIRECTORIES
#	1. NS3_PATH
# 2. VLC_PATH
# 3. LXC_PATH
source dirs.cfg

SERVER_BANDWIDTH=$1
SERVER_DELAY=$2"ms"
NODES_BANDWIDTH=$3
NODES_DELAY=$4"ms"
NODES_NUMBER=$5
CLIENT_BANDWIDTH=$6
CLIENT_DELAY=$7"ms"
CLIENT_NETWORK=$8
VIDNAME=$9
OUTPUTVIDEO=/home/jcarrera/boxingweb/media/${10}
VIDEO_RESOLUTION=${11}

#########

VCODEC="mjpg"
QMIN=10
QMAX=10
MUX="mpjpeg"
RepAlg=NF
AllocAlg=NF
nbuffers=8


#########

# iv. PROGRAM PARAMETERS
CLIENT_TIME=30
SERVER_RUNTIME=60
SIM_RUNTIME=1000

ID=1
#servername=server$ID
#clientname=client$ID
servername=serverZ
clientname=client1
extraname=extraclient


##### AUXILIARY FUNCTION #####
start_sc_test()
{

#####################################
# I. Create Scripts									#
#####################################

	# 1. Create script for server
	cat >$LXC_PATH/$servername/rootfs/server_script <<'EOF'
#!/bin/bash
VLC_PATH_=/home/jcarrera/Documents/vlc
export DISPLAY=
EOF

	chmod +x $LXC_PATH/$servername/rootfs/server_script

	echo "route add default gw 10.100.2.1 dev eth0"	>> $LXC_PATH/$servername/rootfs/server_script
	#echo 'sudo -u ubuntu timeout '${SERVER_RUNTIME}' $VLC_PATH/vlc -vvv $VLC_PATH/'$VIDNAME' --loop  --sout "#transcode{vcodec='$VCODEC',venc=ffmpeg{qmin='$QMIN',qmax='$QMAX'}}:standard{access=http{use-algorithms,allocation='$AllocAlg',replacement='$RepAlg',frame-buffers='$nbuffers'},mux='$MUX',dst=@:8080}" vlc://quit' >> $LXC_PATH/$servername/rootfs/server_script

	# cambié mux
	MUX=ts
	echo 'sudo -u ubuntu vlc -vvv -I dummy /home/ubuntu/vid/'$VIDNAME' --sout "#standard{access=http,mux='$MUX',dst=@:8080}"' >> $LXC_PATH/$servername/rootfs/server_script

	cat >$LXC_PATH/$clientname/rootfs/client_script <<'EOF'
#!/bin/bash
VLC_PATH_=/home/jcarrera/Documents/vlc
export DISPLAY=:0
EOF

	chmod +x $LXC_PATH/$clientname/rootfs/client_script

	echo "route add default gw 10.0.3.1 dev eth1" >> $LXC_PATH/$clientname/rootfs/client_script
	echo "route add -net 10.100.0.0 netmask 255.255.0.0 gw 10.100.3.1 dev eth0" >> $LXC_PATH/$clientname/rootfs/client_script
	echo "sysctl net.ipv4.ip_forward=1" >> $LXC_PATH/$clientname/rootfs/client_script
	echo "iptables -t nat -A PREROUTING -j DNAT -d 10.0.3.11 -p tcp --dport 8080 --to 10.100.2.2" >> $LXC_PATH/$clientname/rootfs/client_script
	echo "iptables -t nat -A POSTROUTING -j MASQUERADE" >> $LXC_PATH/$clientname/rootfs/client_script
	echo "sleep 1000" >> $LXC_PATH/$clientname/rootfs/client_script


	for (( i=0; i < $NODES_NUMBER; i++ ))
	do
		cat >$LXC_PATH/$extraname$i/rootfs/client_script <<'EOF'
#!/bin/bash
VLC_PATH_=/home/jcarrera/Documents/vlc
export DISPLAY=
EOF
		chmod +x $LXC_PATH/$extraname$i/rootfs/client_script

		echo "route add default gw 10.100.4$i.1 dev eth0" >> $LXC_PATH/$extraname$i/rootfs/client_script
		echo 'su - ubuntu -c "$VLC_PATH_/vlc "--avcodec-error-resilience=3" http://10.100.2.2:8080 vlc://quit"' >> $LXC_PATH/$extraname$i/rootfs/client_script
		echo "sleep 1" >> $LXC_PATH/$extraname${i}/rootfs/client_script

done


#####################################
# II. Open ns-3 and start topology  #
#####################################

cd $NS3_PATH
./waf build
./waf --run "scratch/Topology --duration=$SIM_RUNTIME --datarate01=$SERVER_BANDWIDTH --datarate13=$CLIENT_BANDWIDTH --nodesBW=$NODES_BANDWIDTH --serverdelay=$SERVER_DELAY --nodesdelay=$NODES_DELAY --clientdelay=$CLIENT_DELAY" &
sleep 3
cd - > /dev/null

############################
# III. Start containers		 #
############################

xterm -e lxc-start -n $servername ./server_script -c /dev/null &
#lxc-start -n $servername ./server_script &
sleep 1

xterm -e lxc-start -n $clientname ./client_script -c /dev/null &
sleep 1

	for (( i=0; i < $NODES_NUMBER; i++ ))
	do
		xterm -e lxc-start -n $extraname${i} ./client_script -c /dev/null &

		sleep 1
	done

	sleep 2

sleep 10

############################
# IV. Start containers		 #
############################

# Copy video stream to video file
# DISPLAY=:0.0

sudo -u jcarrera ffmpeg -re -i http://10.0.3.11:8080 -timelimit 60 -vsync 0 -c copy $OUTPUTVIDEO &

sleep 60
./stop_sc_test.sh

sleep 10
echo "Script finished"

}

start_sc_test
