# TEST 3: Displaying the video

## Test description

This test runs a simulation of the network topology shown below. A server broadcasts a video over the ns3-simulated network, and a certain number of clients connect to the server. A network interface is added between the main client (running on lxc) and the host system, enabling the host system to display the video stream that the main client receives through the ns-3 network simulation. Extra clients are intended to generate extra traffic in the n0-n1 link, reducing the available bandwith for the main client.

**Note 1:** Linux containers can't run graphic applications easily. That's the reason why the video is displayed in the host system.
**Note 2:** ffmpeg must be installed in the host system.

## Graphic explanation

An ASCII representation of this configuration is presented below:

``` 
                  _ _ _ _ _ _ _ _ _ _ _ _      _ _ _ _ _ _ _ _
                 |        (ns-3)         |    | extra clients |
                 |                       |    |     (lxc)     |
                 |                      _|_ _ |_ _ _ _ _ _ _ _| 
                 |                     / |                 _ _ _ _ _
     server      |                    /  |   main client  |(host)   |
     _ _ _ _     |                   /   |      _ _ _     |         |
    | n2 - -|- - |- - - n0 - - - - n1 - -|- - -|- n3 -|- -|-display |
    |(lxc)  |    |_ _ _ _ _ _ _ _ _ _ _ _|     | (lxc)|   |_ _ _ _ _|
    |_ _ _ _|                                  |_ _ _ |  
    
```
Being:

- n0: router 1
- n1: router 2
- n2: server
- n3: client

These node identification numbers are consistent with those used the program code.

##Files

This folder contains the following files:
1.  confscript
2.  create_containers_3
3.  create_n_containers
4.  destroy_containers_3
5.  destroy_n
6.  dirs.cfg
7.  extraconf
8.  recover.sh
9.  run_test.sh
10. stop_sc_test.sh
11. Topology.cc

##Instructions

1. Copy *Topology.cc* to "ns-3.19/scratch" folder. This code implements the ns-3 topology shown above.

2. $ ./create_containers_3

3. Once the containers are created, it's possible to execute the script *run_test.sh*.
            
4. Finally, if you need to destroy some existing containers, use *destroy_containers_3* script. 

    Usage:  ```$ ./destroy_containers_3```