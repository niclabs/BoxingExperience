# TEST 2: Client-server topology with competing flows

## Test description

This test consists of the simulation of a client-server topology where one of its links that is shared between a video streaming connection and a sink-source routine, generating competing flows between the two applications. 

A more detailed description is presented as follows (the node id numbers are those shown in **Topology**):

* Video streaming: node 2 (server) transmits video and node 3 (client) is connected to it.

* Sink-source routine: nodes 4 (source) sends packets to node 5 (sink) at a fixed datarate. These packets contain no meaningful information, as this application is thought as a means of generating additional traffic on the shared link.

* Shared link: given the topology, packets from both applications are transmitted on the link formed by node 0 and node 1.

*NOTE*: this test is an extension to the version of BoxingExperience presented in [3].

**Objetive** 

The aim of this test is to evaluate how competing flows affects the QoS/QoE indicators of the client: FPS, jitter, delay, etc.

**Implementation details**

- The video server and the client that receives the frames run on separate linux containers. These containers use tap-bridge interfaces to connect to ns-3.

- The streaming tool used here is the modified version of VLC developed in [2], that implements the algorithms proposed in [1]. It is used within each container --the server uses vlc to transmit video and the client uses vlc to connect to the server.

- The test relies on the program *NewTopology.cc*, that uses ns-3 libraries to simulate a particular network topology.

- The sink-source application is implemented within ns-3, it **doesn't** run on linux containers.

**Topology**

An ASCII representation of the *NewTopology* topology is presented as follows:

```
             n5               n4
              \               /
               \             /
                \           /
     n2 - - - - n0 - - - - n1 - - - - n3
                
```
Being:

- n0: router 1
- n1: router 2
- n2: server
- n3: client
- n4: source
- n5: sink

These node identification numbers are consistent with the program code.

##Files

This folder contains the following files:

1. create_containers_2

2. destroy_containers_2

3. run_test_2

4. make_sc_conf.c

5. NewTopology.cc

6. conf_params.cfg

##Instructions

1. Copy *NewTopology.cc* to "ns-3.19/scratch" folder. This code implements the ns-3 topology presented above.

2. Add the video you want to stream in the "vlc" folder, and change the video name in conf_params.cfg (VIDNAME variable).

3. Create and configure the linux containers using the included *create_containers_2* script.

    Usage: 	```$ ./create_containers_2```

4. Once the containers are created, it's possible to execute the script *run_test_2*, an implementation of the test introduced in **Description**.

    Usage:    ```$ ./run_test_2 <n_clnts> <client_runtime> <start_traffic> <stop_traffic> <traffic_bitrate>```
    
    All time quantities are expressed in seconds.

    The script runs *n_clnts* consecutive clients and generates an output file with the average FPS of each one, as well as an information file containing encoding parameters, date, video name, etc.
    
    *start_traffic*: time at which the source starts sending packet to the sink.
    
    *stop_traffic*: time at which the source-sink traffic stops.
     
    *traffic_bitrate*: rate at which the source sends packets to the sink.
    
    In pseudo-code:        
        
            ns-3 topology simulation starts
        
            wait 5 seconds
        
            run server
            
            wait 5 seconds
        
            for ( i = 1 ; i == n_clients; i++ )
                run client for client_runtime seconds
                i-th client disconnects
                wait 5 seconds
            end
            
            wait 5 seconds  
            
            server disconnects
            
            wait 5 seconds  
            
            ns-3 topology simulation ends

    *Notes*: 
    
    * The reason why the server waits 5 seconds before starting is that ns-3 network simulations take some time to set up.
    
    * Given that linux containers take some time to close, there's a 5 seconds rest between clients, so that only one client can be connected at a time.
    
    Example: timeline for  ```$ ./run_test_2 2 25 15 38 60Mbps``` 
    
            [Time (s): 00]  ns-3 simulation starts
            [Time (s): 05]  Server starts
            [Time (s): 10]  Client 1 connects
            [Time (s): 15]  Source Node: Transmission starts
            [Time (s): 35]  Client 1 disconnects
            [Time (s): 38]  Source-sink traffic finishes
            [Time (s): 40]  Client 2 connects
            [Time (s): 65]  Client 2 disconnects
            [Time (s): 70]  *for* loop ends; server disconnects
            [Time (s): 75]  ns-3 simulation ends
            
5. Finally, if you need to destroy some existing containers, use *destroy_containers_2* script. 

    Usage:  ```$ ./destroy_containers_2```

##References

[1] Piquer, J. E., & Bustos-Jiménez, J. (2010). Frame Allocation Algorithms for Multi-threaded Network Cameras. Euro-Par 2010-Parallel Processing, 560-571.

[2] Ferrer, G. M., Méric, H., Piquer, J. M., & Bustos-Jiménez, J. Performance evaluation of streaming algorithms for network cameras.

[3] Bustos-Jiménez, J., Alonso, R., Faúndez, C., & Méric, H. BoxingExperience: Measuring QoS and QoE of Multimedia Streaming Using NS3, LXC and VLC.