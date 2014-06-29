Clients-server topology in ns-3 for testing vlc video streaming


Requirements

brctl
tunctl
ns-3.19 or newer
lxc (designed for version 0.7.5)

Some libraries required to make vlc work might be required. If you find any
problems, try installing vlc.


Instructions

- On this folder, create a new folder named "ns-3.19".

- Download ns-3.19 and install it on the aforementioned folder. More information
is available at "http://www.nsnam.org/wiki/Installation". Once ns-3 dependencies
are installed, one quick way to install is to download the source code on the
"ns-3.19" folder you created before and then running.

$ ./waf configure

on the ns-3 folder. This step IS required for ns-3 to work correctly.

- Move "CameraStreaming.cc" into "ns-3.19/scratch" folder.

- Add the video you want to stream in the "vlc" folder, and change the video name
in start_basic_test script (line 60).

- Create the containers using the included create_containers script.

- Once the containers are created, run the tests using start_basic_test script.

- Once the required tests are done, run stop_basic_test script to stop the
ns-3 topology simulation and the containers linked to it.

- Finally, to destroy some existing containers, use destroy_containers script.

