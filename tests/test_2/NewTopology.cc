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

NS_LOG_COMPONENT_DEFINE ("NewTopology");

bool verbose;

class MyApp : public Application
{
public:

  MyApp ();
  virtual ~MyApp();

  void Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate);

private:
  virtual void StartApplication (void);
  virtual void StopApplication (void);

  void ScheduleTx (void);
  void SendPacket (void);

  Ptr<Socket>     m_socket;
  Address         m_peer;
  uint32_t        m_packetSize;
  uint32_t        m_nPackets;
  DataRate        m_dataRate;
  EventId         m_sendEvent;
  bool            m_running;
  uint32_t        m_packetsSent;
};

MyApp::MyApp ()
  : m_socket (0),
    m_peer (),
    m_packetSize (0),
    m_nPackets (0),
    m_dataRate (0),
    m_sendEvent (),
    m_running (false),
    m_packetsSent (0)
{
}

MyApp::~MyApp()
{
  m_socket = 0;
}

void
MyApp::Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate)
{
  m_socket = socket;
  m_peer = address;
  m_packetSize = packetSize;
  m_nPackets = nPackets;
  m_dataRate = dataRate;
}

void
MyApp::StartApplication (void)
{
  NS_LOG_UNCOND ("[Time (s): " <<  Simulator::Now ().GetSeconds () << "\t ] \t Source Node: Transmission starts");
  m_running = true;
  m_packetsSent = 0;
  m_socket->Bind ();
  m_socket->Connect (m_peer);
  SendPacket ();

}

void
MyApp::StopApplication (void)
{
  m_running = false;

  if (m_sendEvent.IsRunning ())
    {
      Simulator::Cancel (m_sendEvent);
    }

  if (m_socket)
    {
      m_socket->Close ();
    }
  NS_LOG_UNCOND ("[Time (s): " << Simulator::Now ().GetSeconds () << "\t ] \t Source Node: Transmission has finished");
}

void
MyApp::SendPacket (void)
{
  Ptr<Packet> packet = Create<Packet> (m_packetSize);
  m_socket->Send (packet);

  if (++m_packetsSent < m_nPackets)
    {
      ScheduleTx ();
    }
}

void
MyApp::ScheduleTx (void)
{
  if (m_running)
    {
      Time tNext (Seconds (m_packetSize * 8 / static_cast<double> (m_dataRate.GetBitRate ())));
      m_sendEvent = Simulator::Schedule (tNext, &MyApp::SendPacket, this);
    }
}

static void
CwndChange (uint32_t oldCwnd, uint32_t newCwnd)
{		if (verbose){
    NS_LOG_UNCOND (Simulator::Now ().GetSeconds () << "\t" << newCwnd);
		}
}

static void
RxDrop (Ptr<const Packet> p)
{
		if (verbose){
    NS_LOG_UNCOND ("RxDrop at " << Simulator::Now ().GetSeconds ());
		}
}
/**/

int
main (int argc, char *argv[])
{

		verbose = true;
		float stop = -1.0;
		float app_start_time = 10;
		float app_stop_time = 20;
		uint32_t n_packets = 2147483647;
		uint32_t packet_size = 1040;
		std::string datarate01 = "5Mbps";
		std::string datarate02 = "5Mbps";
		std::string datarate13 = "5Mbps";
		std::string datarate14 = "5Mbps";
		std::string datarate05 = "5Mbps";
		std::string app_datarate = "3Mbps";

    /* ********************* */
    /* COMMANDLINE VARIABLES */
    /* ********************* */

		CommandLine cmd;
		cmd.AddValue("verbose", "Show ", verbose);
		cmd.AddValue("duration", "Simulation length, in seconds", stop);
		cmd.AddValue("appStartTime", "Time when packet transmission starts", app_start_time);
		cmd.AddValue("appStopTime", "Time when packet transmission ends", app_stop_time);
		cmd.AddValue("nPackets", "Number of packets to send to the sink", n_packets);
		cmd.AddValue("packetSize", "Packet size", packet_size);
		cmd.AddValue("datarate01", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate01);
		cmd.AddValue("datarate02", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate02);
		cmd.AddValue("datarate13", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate13);
		cmd.AddValue("datarate14", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate14);
		cmd.AddValue("datarate05", "Link bandwith, for example \"5Mbps\" or \"1800Kbps\"", datarate05);
		cmd.AddValue("appDataRate", "Application data rate, for example \"2.5Mbps\" or \"1500Kbps\"", app_datarate);
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
    c.Create (6);
    /* 0: ROUTER 0; 1: ROUTER 1; 2: SERVER; 3: CLIENT; 4: SOURCE; 5: SINK */

    // shared traffic: router0-router1
    NodeContainer n0n1 = NodeContainer (c.Get (0), c.Get (1));

    // server-router0
    NodeContainer n0n2 = NodeContainer (c.Get (0), c.Get (2));

    // client-router1
    NodeContainer n1n3 = NodeContainer (c.Get (1), c.Get (3));

    // source-router1
    NodeContainer n1n4 = NodeContainer (c.Get (1), c.Get (4));

    // sink-router0
    NodeContainer n0n5 = NodeContainer (c.Get (0), c.Get (5));

    /* CREATING CHANNELS */
    // NetDeviceContainer deviceContainer;

    CsmaHelper csma;
    //PointToPointHelper csma;

    csma.SetChannelAttribute("DataRate", StringValue (datarate01));
    csma.SetChannelAttribute("Delay", StringValue("0.5ms"));

    NetDeviceContainer d0d1 = csma.Install (n0n1);

    csma.SetChannelAttribute("DataRate", StringValue (datarate02));
    NetDeviceContainer d0d2 = csma.Install (n0n2);

    csma.SetChannelAttribute("DataRate", StringValue (datarate14));
    NetDeviceContainer d1d4 = csma.Install (n1n4);

    csma.SetChannelAttribute("DataRate", StringValue (datarate05));
    NetDeviceContainer d0d5 = csma.Install (n0n5);

    Ptr<RateErrorModel> em = CreateObject<RateErrorModel> ();
    em->SetAttribute ("ErrorRate", DoubleValue (0.00001));
    d0d5.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));

    csma.SetChannelAttribute("DataRate", StringValue (datarate13));
    NetDeviceContainer d1d3 = csma.Install (n1n3);


		/* TAP-BRIDGE SETTING */
		// Connect pre-configured tap devices to each ghost node:
		TapBridgeHelper tapBridge;
		tapBridge.SetAttribute ("Mode", StringValue ("UseBridge"));

		// - Server
		tapBridge.SetAttribute ("DeviceName", StringValue ("tap-server"));
		// tapBridge.Install (server"${i}  node, <dev on the server side> );
		tapBridge.Install (c.Get (2), d0d2.Get (1));

		// - Slow client
	  tapBridge.SetAttribute ("DeviceName", StringValue ("tap-scx"));
		// tapBridge.Install (<slow client node>, <dev on the client side>);
	  tapBridge.Install (c.Get (3), d1d3.Get (1));

		// It's necesary to assign IPs to each device that is not connected to a pre-configured tap device.
		//	InternetStackHelper stack;
		//	stack.Install (router);

    InternetStackHelper stack;
    stack.Install (c.Get(0)); //
    stack.Install (c.Get(1));
    stack.Install (c.Get(4));
    stack.Install (c.Get(5));

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
		
    ipv4.SetBase ("10.100.4.0", "255.255.255.0");
    Ipv4InterfaceContainer i1i4 = ipv4.Assign (d1d4);

    ipv4.SetBase ("10.100.5.0", "255.255.255.0");
    Ipv4InterfaceContainer i0i5 = ipv4.Assign (d0d5);

		// SETTING SINK-SOURCE NODES AND APPLICATION
    uint16_t sinkPort = 8080;
    Address sinkAddress (InetSocketAddress (i0i5.GetAddress (1), sinkPort));
    PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
    ApplicationContainer sinkApps = packetSinkHelper.Install (c.Get (5));
    sinkApps.Start (Seconds (1.0));
    sinkApps.Stop (Seconds (stop-1.0));

    Ptr<Socket> ns3TcpSocket = Socket::CreateSocket (c.Get (4), TcpSocketFactory::GetTypeId ());
    ns3TcpSocket->TraceConnectWithoutContext ("CongestionWindow", MakeCallback (&CwndChange));

    Ptr<MyApp> app = CreateObject<MyApp> ();
    app->Setup (ns3TcpSocket, sinkAddress, packet_size, n_packets, DataRate (app_datarate));
    c.Get (4)->AddApplication (app);
    app->SetStartTime (Seconds (app_start_time));
    app->SetStopTime (Seconds (app_stop_time));

	  d0d5.Get (1)->TraceConnectWithoutContext ("PhyRxDrop", MakeCallback (&RxDrop));

    Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

    Simulator::Stop (Seconds(stop));
    NS_LOG_UNCOND ("[Time (s): " << Simulator::Now ().GetSeconds () << "\t ] \t Simulation starts");
    Simulator::Run ();
    NS_LOG_UNCOND ("[Time (s): " << Simulator::Now ().GetSeconds () << "\t ] \t Simulation has finished");
    Simulator::Destroy ();

    return 0;

    }
