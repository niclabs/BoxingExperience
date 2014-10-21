#include <fstream>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/tap-bridge-module.h"
#include "ns3/realtime-simulator-impl.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"


#define FRAME_KB 24
#define FRAME_BIT 1024*8*FRAME_KB

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Topology");

int
main (int argc, char *argv[])
{

		verbose = true;
		float stop = -1.0;
		std::string sTap = "servertap1";
		std::string cTap = "clienttap1";
		std::string datarate01 = "5Mbps";
		std::string datarate02 = "5Mbps";
		std::string datarate13 = "5Mbps";

    /* ********************* */
    /* COMMANDLINE VARIABLES */
    /* ********************* */

		CommandLine cmd;
		cmd.AddValue("verbose", "Show ", verbose);
		cmd.AddValue("duration", "Simulation length, in seconds", stop);
		cmd.AddValue("datarate01", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate01);
		cmd.AddValue("datarate02", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate02);
		cmd.AddValue("datarate13", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate13);
		cmd.Parse (argc, argv);

    /* ********************** */
    /* SETTING TIMERESOLUTION */
    /* ********************** */

		Time::SetResolution (Time::NS);
		GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));
		GlobalValue::Bind ("ChecksumEnabled", BooleanValue (true));

		// This will stop ns-3 if it can't keep up with the traffic to simulate.
		Config::SetDefault ("ns3::RealtimeSimulatorImpl::SynchronizationMode", StringValue("HardLimit"));
		// Default time difference is 100 ms
		Config::SetDefault ("ns3::RealtimeSimulatorImpl::HardLimit", TimeValue(Time("100ms")));


    /* ***************** */
    /* DEFINING TOPOLOGY */
    /* ***************** */

    /* CREATING NODES */

    NodeContainer c;
    c.Create (4);
    /* 0: ROUTER 0; 1: ROUTER 1; 2: SERVER; 3: CLIENT; 4: SOURCE; 5: SINK */

    // shared traffic: router0-router1
    NodeContainer n0n1 = NodeContainer (c.Get (0), c.Get (1));

    // server-router0
    NodeContainer n0n2 = NodeContainer (c.Get (0), c.Get (2));

    // client-router1
    NodeContainer n1n3 = NodeContainer (c.Get (1), c.Get (3));


		/* TODO: create nodes for extra clients */		

    /* CREATING CHANNELS */
    // NetDeviceContainer deviceContainer;

    CsmaHelper csma;
    //PointToPointHelper csma;

    csma.SetChannelAttribute("DataRate", StringValue (datarate01));
    csma.SetChannelAttribute("Delay", StringValue("0.5ms"));

    NetDeviceContainer d0d1 = csma.Install (n0n1);

    csma.SetChannelAttribute("DataRate", StringValue (datarate02));
    NetDeviceContainer d0d2 = csma.Install (n0n2);

		/*
    Ptr<RateErrorModel> em = CreateObject<RateErrorModel> ();
    em->SetAttribute ("ErrorRate", DoubleValue (0.00001));
    d0d1.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));
		*/

    csma.SetChannelAttribute("DataRate", StringValue (datarate13));
    NetDeviceContainer d1d3 = csma.Install (n1n3);

		/* TAP-BRIDGE SETTING */
		// Connect pre-configured tap devices to each ghost node:
		TapBridgeHelper tapBridge;
		tapBridge.SetAttribute ("Mode", StringValue ("UseBridge"));

		// - Server
		tapBridge.SetAttribute ("DeviceName", StringValue (sTap));
		// tapBridge.Install (server"${i}  node, <dev on the server side> );
		tapBridge.Install (c.Get (2), d0d2.Get (1));

		// - Slow client
	  tapBridge.SetAttribute ("DeviceName", StringValue (cTap));
		// tapBridge.Install (<slow client node>, <dev on the client side>);
	  tapBridge.Install (c.Get (3), d1d3.Get (1));

		// It's necesary to assign IPs to each device that is not connected to a pre-configured tap device.
		//	InternetStackHelper stack;
		//	stack.Install (router);

    InternetStackHelper stack;
    stack.Install (c.Get(0));
    stack.Install (c.Get(1));

		// SETTING IP ADDRESSES
    Ipv4AddressHelper ipv4;

    ipv4.SetBase ("10.100.1.0", "255.255.255.0");
    Ipv4InterfaceContainer i0i1 = ipv4.Assign (d0d1);

    ipv4.SetBase ("10.100.2.0", "255.255.255.0");
		ipv4.Assign(d0d2.Get (0));
		// Ipv4InterfaceContainer i0i2 = ipv4.Assign (d0d2);

    ipv4.SetBase ("10.100.3.0", "255.255.255.0");
		ipv4.Assign(d1d3.Get (0));
    // Ipv4InterfaceContainer i1i3 = ipv4.Assign (d1d3);

    Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

    Simulator::Stop (Seconds(stop));
    NS_LOG_UNCOND ("[Time (s): " << Simulator::Now ().GetSeconds () << "\t ] \t Simulation starts");
    Simulator::Run ();
    NS_LOG_UNCOND ("[Time (s): " << Simulator::Now ().GetSeconds () << "\t ] \t Simulation has finished");
    Simulator::Destroy ();

    return 0;

    }
