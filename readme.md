# Boxing Experience

Boxing Experience is a modular framework to study the relation between QoS and QoE metrics for multimedia transmissions following the same separation of concerns as the Internet protocol suite. 
This framework relies on open-source software:
1. ns-3 for network simulation.
2. VLC for multimedia transmission.
3. Linux containers to run applications on ns-3 nodes. Although its usage is not strictly necessary, it has the following advantages: first, we can easily change the application running inside the containers, so Boxing Experience will also work with applications that cannot be connected directly to ns-3. Secondly, LXCs enable to monitor the resource usage (for instance CPU or memory) independently for each container.

Boxing Experience provides a set of tests that allows the simulation of a variety of network topologies and server/client applications. Although each test has a fixed topology, some variables can be controlled through command line parameters or configuration files, in order to study how different input values affect QoS. On each simulation, some QoS statistics are computed and saved as plain text files.

**Requirements**

1. brctl ($ sudo apt-get install bridge-utils)
2. tunctl ($ sudo apt-get install uml-utilities)
3. ns-3.19 or newer
4. lxc (designed for version 0.7.5)

*NOTE:* Some libraries might be required to make vlc work. If you find any problems, try installing vlc ($ sudo apt-get install vlc) and running the modified version of vlc included in this package.

**Instructions**

I. ns-3 installation and configuration:

1. 	On this folder, create a new folder named "ns-3.19".

2. 	Download ns-3.19 and install it on the aforementioned folder. More information is available at "http://www.nsnam.org/wiki/Installation". Once ns-3 dependencies are installed, a quick way to install is to download the source code on the "ns-3.19" folder you created before and then running.
	
3. 	Execute the following command on the ns-3.19 folder. This step IS required for ns-3 to work correctly.
		$ ./waf configure

II. VLC 

- Add the videos you want to stream in the "vlc" folder. Don't forget to set the video name in the configuration files of BoxingExperience predetermined tests.
