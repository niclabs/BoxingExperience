#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/tap-bridge-module.h"
#include "ns3/realtime-simulator-impl.h"

#define FRAME_KB 24
#define FRAME_BIT 1024*8*FRAME_KB

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("CameraStreaming");

/*
 * double fpsToDataRate (double fps)
 * Receives a frame rate <fps> (in frames per second), and returns the data
 * rate (in bytes per second) required to stream at this frame rate.
 */
double
fpsToDataRate (double fps)
{
  // x FPS ~ FRAME_KB*x KBps ~ FRAME_KB*8*x Kbps
  return FRAME_BIT*fps;
}

std::string
generateDataRate (int id, int total)
{
  double dr;
  if (id < 0) {			// fast-client-id data rate
      if (total == 1) {
        dr = fpsToDataRate(29.0);
      }
      else {
        dr = fpsToDataRate(24.0 - 10.0 * id / (total-1));
      }
	}
  else {						// slow-client-id data rate
      if (total == 1) {
        dr = fpsToDataRate(4.5);
      }
      else {
        dr = fpsToDataRate(3.5 + 2.0 * id / (total-1));
      }
  }
  std::stringstream sDataRate;
  if (dr < (1<<10))
    sDataRate << dr << "bps";
  else if (dr < (1<<20))
    sDataRate << dr/(1<<10) << "Kbps";
  else if (dr < (1<<30))
    sDataRate << dr/(1<<20) << "Mbps";
  else
    sDataRate << dr/(1<<30) << "Gbps";

  return sDataRate.str ();
}

// Generates names of the pre-configured Tap devices
std::string
generateTapName (int i, int id)
{
  std::stringstream sTapName;
  if (id == 0)
    sTapName << "tap-fc" << i;
  else
    sTapName << "tap-sc" << i;
  return sTapName.str ();

	//char *cTapName = (char *)malloc(16);
	//if (id == 0)
	//	sprintf(cTapName, "tap-fc%d", i);
	//else
	//	sprintf(cTapName, "tap-sc%d", i);
	//return cTapName;
}

int
main (int argc, char *argv[])
{

	float stop = -1.0;
	uint32_t nfClients = 2; // Number of fast clients
	uint32_t nsClients = 0; // Number of slow clients

	CommandLine cmd;
	cmd.AddValue("duration", "Simulation length, in seconds", stop);
  cmd.AddValue("nsClients", "Number of slow clients", nsClients);
  cmd.AddValue("nfClients", "Number of fast clients", nfClients);
  cmd.Parse (argc, argv);

  if (nsClients < 0)
  {
    std::cout << "Number of clients must be more than zero." << std::endl;
    exit (1);
  }

  Time::SetResolution (Time::NS);

  // We are interacting with the real world.  This means we have to interact in
  // real-time and therefore, we have to use the real-time simulator and
  // calculate checksums for packets.
  GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));
  GlobalValue::Bind ("ChecksumEnabled", BooleanValue (true));

	// This will stop ns-3 if it can't keep up with the traffic to simulate.
	Config::SetDefault ("ns3::RealtimeSimulatorImpl::SynchronizationMode", StringValue("HardLimit"));
	// Default time difference is 100 ms
	Config::SetDefault ("ns3::RealtimeSimulatorImpl::HardLimit", TimeValue(Time("20ms")));

  NodeContainer router;
  NodeContainer buffer; //Ghost node
	NodeContainer fastClients; //Ghost nodes
	NodeContainer slowClients; //Ghost nodes

  router.Create (1);
  buffer.Create (1);
	fastClients.Create (nfClients);
	slowClients.Create (nsClients);

	NetDeviceContainer deviceContainer;
  CsmaHelper csma;

  // Add Router-Buffer devices
  NodeContainer cnodes;
  cnodes.Add (router.Get (0));
  cnodes.Add (buffer.Get (0));
  csma.SetChannelAttribute("DataRate", StringValue ("10Gbps"));
  csma.SetChannelAttribute("Delay", StringValue("0.0ms")); // Depends on each client
	
	deviceContainer.Add (csma.Install (cnodes));

	// Add Router-FastClients devices
	for (uint32_t i=0; i < nfClients; i++)
	{
		NodeContainer cnodes;
		cnodes.Add (router.Get (0));
		cnodes.Add (fastClients.Get (i));

		csma.SetChannelAttribute("DataRate", StringValue(generateDataRate(-(i+1), nfClients).c_str ())); // Depends on each client
		csma.SetChannelAttribute("Delay", StringValue("0.0ms")); // Depends on each client

		deviceContainer.Add (csma.Install (cnodes));
	}

	// Add Router-SlowClients devices
	for (uint32_t i=0; i < nsClients; i++)
	{
		NodeContainer cnodes;
		cnodes.Add (router.Get (0));
		cnodes.Add (slowClients.Get (i));
		csma.SetChannelAttribute("DataRate", StringValue(generateDataRate(i, nsClients).c_str ())); // Depends on each client
		csma.SetChannelAttribute("Delay", StringValue("0.0ms")); // Depends on each client

		deviceContainer.Add (csma.Install (cnodes));
	}

  // Connect pre-configured tap devices to each ghost node:
  TapBridgeHelper tapBridge;
  tapBridge.SetAttribute ("Mode", StringValue ("UseBridge"));

  // - Buffer
  tapBridge.SetAttribute ("DeviceName", StringValue ("tap-buffer"));
  tapBridge.Install (buffer.Get (0), deviceContainer.Get (1));

  // - Fast Clients
  for (uint32_t i=0; i < nfClients; i++)
  {
    tapBridge.SetAttribute ("DeviceName", StringValue (generateTapName (i,0).c_str ()));
    tapBridge.Install (fastClients.Get (i), deviceContainer.Get (2*(i+1)+1));
  }

  // - Slow Clients
  for (uint32_t i=0; i < nsClients; i++)
  {
    tapBridge.SetAttribute ("DeviceName", StringValue (generateTapName (i,1).c_str ()));
    tapBridge.Install (slowClients.Get (i), deviceContainer.Get (2*(i+nfClients+1)+1));
  }

  // It's necesary to assign IPs to each device that is not connected to a pre-configured tap device.
  InternetStackHelper stack;
  stack.Install (router);

  Ipv4AddressHelper addressHlpr;

  // Router IPs
  addressHlpr.SetBase("10.10.0.0", "255.255.255.0");
  addressHlpr.Assign(deviceContainer.Get (0));

  for (uint32_t i=0; i < nfClients; i++){
    std::stringstream sIP;
    sIP << "10." << i/256 + 20 << "." << i%256 << ".0";

    addressHlpr.SetBase(sIP.str ().c_str (), "255.255.255.0");
    addressHlpr.Assign(deviceContainer.Get (2*(i+1)));
  }

  for (uint32_t i=0; i < nsClients; i++){
    std::stringstream sIP;
    sIP << "10." << i/256 + 30 << "." << i%256 << ".0";

    addressHlpr.SetBase(sIP.str ().c_str (), "255.255.255.0");
    addressHlpr.Assign(deviceContainer.Get (2*(nfClients+i+1)));
  }

	//Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

	//csma.EnablePcap ("RouterTrace", deviceContainer.Get (0), false);

   // Ipv4GlobalRoutingHelper g;
   // Ptr<OutputStreamWrapper> routingStream = Create<OutputStreamWrapper> ("dynamic-global-routing.routes", std::ios::out);
   // g.PrintRoutingTableAllAt (Seconds (12), routingStream);

	if (stop != -1.0)
  	Simulator::Stop (Seconds (stop));
  Simulator::Run ();
  Simulator::Destroy ();
}
