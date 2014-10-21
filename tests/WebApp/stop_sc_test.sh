#!/bin/bash
NARGS=$#
SERV=true
EF=$1
ES=$2
INTEGER='^[0-9]+$'
N_EXTRA=10

stop_sc_test()
{

	for (( i=0; i < $N_EXTRA; i++ ))
	do
		lxc-stop -n extraclient${i}
	done

	lxc-stop -n serverZ
	lxc-stop -n client1

	killall "Topology"
	killall "vlc"
	killall "ffmpeg"

}

stop_sc_test

