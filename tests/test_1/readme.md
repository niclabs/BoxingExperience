**TEST 1: Clients-server topology in ns-3 for testing vlc video streaming**

**Description**

This test consists of the simulation of a video streaming service over ns-3, with increasing number of slow clients.

The aim of this test is twofold:

- Measuring how the number of slow clients affects the QoS/QoE of the fastest client.

- Evaluating how the algorithms proposed in [1] manage the requirements of the clients. 

Some implementation details:

- The server and each one of the clients run on separate linux containers.

- The streaming tool used here is the modified version of VLC developed in [2], that implements the algorithms proposed in [1]. It is used within each container --the server uses vlc to transmit video and the clients use vlc to connect to the server.

- The test relies on the program *CameraStreaming.cc*, that uses ns-3 libraries to simulate a particular network topology.

An ASCII representation of the *CameraStreaming* topology is presented as follows:

```
               _ _ _ _ fc-1
              /_ _ _ _ ...
             /_ _ _ _  fc-nf
            /      
  s0 - - - r0 - - - -  sc-1
            \ _ _ _ _  ...
             \ _ _ _ _ ...
              \_ _ _ _ sc-ns

```
Where s0 is the server, r0 a router, fc the fast clients and sc the slow clients. The bandwidth of each router-client link depends on the client, following the pattern presented in [3].

**Files**

This folder contains the following files:

1. create_containers

2. destroy_containers

3. run_simulation

4. run_test_1

5. CameraStreaming.cc

6. makeconf.c

7. encoding_params.cfg

**Instructions**

1. Copy *CameraStreaming.cc* to "ns-3.19/scratch" folder. This code implements the ns-3 topology presented above.

2. Add the video you want to stream in the "vlc" folder, and change the video name in encoding_params.cfg (VIDNAME variable).

3. Create and configure the linux containers using the included *create_containers* script.

    Usage: 	```$ ./create_containers <initialFastClientIndex> <finalFastClientIndex> <initialSlowClientIndex> <finalSlowClientIndex>```

    Examples:

    * To create 2 fast clients (indexes 0, 1)  and 20 slow clients (indexes 0, 1, ..., 19), execute: ```$ ./create_containers 0 2 0 20```

    * In order to add 22 slow clients, execute: ```$ ./create_containers 0 0 20 42```

4. Once the containers are created, two scripts can be executed:
    
    * *run_simulation*: this bash script is an individual realization of the basic test described next.
    
        On each execution a server transmits the video specified in encoding_params.cfg over the ns-3 simulated network, and each client connects to the server.
        
        The number of fast and slow clients, the replacement and allocation algorithms, the number of buffers and the transmission duration are specified as command line parameters, as in:
        
        ```$ ./run_simulation <numberOfFastClients> <numberOfSlowClients> <replacementAlg> <allocationAlg> <nBuffers> <runtime(seconds)>```
        
        When the simulation ends and the server and all clients are disconnected, this script writes a text file with the average FPS of each client measured by the server during the simulation. This record can be found on the server container directory (*/var/lib/lxc/buffer/rootfs*), with the name "test-```<numberOfFastClients>```-```<numberOfSlowClients>```-```<replacementAlg>```-```<allocationAlg>```-```<nBuffers>```.txt"

    * *run_test_1*: this bash script is a complete realization of the test introduced in **Description**.
    
        This test is intended to generate curves of *average FPS of the fastest client* against *Number of slow clients* under four different configurations:   
          
            - Replacement Algorithm = NF; Allocation Algorithm = NF ; #Buffers = 8
            - Replacement Algorithm = NF; Allocation Algorithm = OF ; #Buffers = 8
            - Replacement Algorithm = NF; Allocation Algorithm = NF ; #Buffers = 6
            - Replacement Algorithm = NF; Allocation Algorithm = OF ; #Buffers = 6
            
        In order to achieve that, for each configuration the script runs the basic test described above --*run_simulation*-- as many times as specified by the user, increasing the number of slow clients in the consecutive executions. The number of fast clients has a fixed value of 2. In pseudo-code:

            for each configuration
                for ( i = 1 ; i == N; i++ )
                    run_simulation with 2 fast clients and i slow clients
                end
            end
            
        Usage:    ```$ ./run_test_1 <InitialNumberOfSlowClients> <FinalNumberOfSlowClients> <Step>```
    
        Where *InitialNumberOfSlowClients* is the minimum number of slow clients, *FinalNumberOfSlowClients* is the maximum number of slow clients, and *Step* is the number of slow clients added on each iteration. 
        
        Example (with reasonable inputs): ```$ ./run_test_1 1 42 1```
        
        For each algorithms-n°buffers combination, the script generates an output file with the FPS data and an information file containing encoding parameters, date, video name, etc.

* Finally, if you need to destroy some existing containers, use *destroy_containers* script. 

    Usage:  ```$ ./destroy_containers <initialFastClientIndex> <finalFastClientIndex> <initialSlowClientIndex> <finalSlowClientIndex>```

**References**

[1] Piquer, J. E., & Bustos-Jiménez, J. (2010). Frame Allocation Algorithms for Multi-threaded Network Cameras. Euro-Par 2010-Parallel Processing, 560-571.

[2] Ferrer, G. M., Méric, H., Piquer, J. M., & Bustos-Jiménez, J. Performance evaluation of streaming algorithms for network cameras.

[3] Bustos-Jiménez, J., Alonso, R., Faúndez, C., & Méric, H. BoxingExperience: Measuring QoS and QoE of Multimedia Streaming Using NS3, LXC and VLC.