#!/bin/bash

	NARGS=$#
	SERV=true
	ID=1
	CONTAINER_VLC_PATH=/home/jcarrera/Documents/vlc
	INTEGER='^[0-9]+$'

	clientbridge=clientbridge$ID
	clienttap=clienttap$ID
	serverbridge=serverbridge$ID
	servertap=servertap$ID
	servername=server$ID
	clientname=client$ID
	source dirs.cfg

	############################################################
	# Create and start bridges/taps for server and main client #
	############################################################

	# Create configuration files	
	./confscript $ID "$VLC_PATH"

	# SERVER
	if [ "$SERV" == true ] ; then
		brctl addbr $serverbridge
		tunctl -t $servertap
		ifconfig $servertap 0.0.0.0 promisc up
		brctl addif $serverbridge $servertap
		ifconfig $serverbridge up
	fi

	# main CLIENT
	brctl addbr $clientbridge
	tunctl -t $clienttap
	ifconfig $clienttap 0.0.0.0 promisc up
	brctl addif $clientbridge $clienttap
	ifconfig $clientbridge up

	####
	# OLD SERVER
	if [ "$SERV" == true ] ; then
		brctl addbr br-serverZ
		tunctl -t tap-serverZ
		ifconfig tap-serverZ 0.0.0.0 promisc up
		brctl addif br-serverZ tap-serverZ
		ifconfig br-serverZ up
	fi

	# main CLIENT
	brctl addbr br-z-c
	tunctl -t tap-scz
	ifconfig tap-scz 0.0.0.0 promisc up
	brctl addif br-z-c tap-scz
	ifconfig br-z-c up


	############################################################
	# Create and start bridges/taps for server and main client #
	############################################################

	CONTAINER_VLC_PATH=/home/jcarrera/Documents/vlc
	clientsname=extraclient
	bridgename=extrabridge
	tapname=extratap
	source dirs.cfg

	./extraconf "$VLC_PATH" $clientsname $bridgename

	# Create and start bridges/taps
	for (( i=0; i < 10; i++ ))
	do
		brctl addbr $bridgename${i}
		tunctl -t $tapname${i}
		ifconfig $tapname${i} 0.0.0.0 promisc up
		brctl addif $bridgename${i} $tapname${i}
		ifconfig $bridgename${i} up
	done
	
	# Show existing bridges
	brctl show &&
	sleep 1
	

