// #include "ns3/circular-mobility-model.h"
#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include <fstream> // Added for file stream
using namespace ns3;

// Global file stream object
std::ofstream outputFile;

void PrintInfo() {
  Ptr<Node> n0 = ns3::NodeList::GetNode(0);
  Ptr<Node> n1 = ns3::NodeList::GetNode(1);

  Ptr<MobilityModel> m0 = n0->GetObject<MobilityModel>();
  Ptr<MobilityModel> m1 = n1->GetObject<MobilityModel>();

  std::cout << "n0 posx:" << m0->GetPosition().x
            << "\t\tn0 posy:" << m0->GetPosition().y
            << "\t\tn1 posx:" << m1->GetPosition().x
            << "\t\tn1 posy:" << m1->GetPosition().y << std::endl;

  // Write coordinates to the file
  outputFile << m0->GetPosition().x << "\t" << m0->GetPosition().y << "\t"
             << m1->GetPosition().x << "\t" << m1->GetPosition().y << std::endl;

  Simulator::Schedule(Seconds(1), &PrintInfo);
}

int main(int argc, char *argv[]) {
  CommandLine cmd;
  cmd.Parse(argc, argv);

  NodeContainer nodes;
  nodes.Create(2);

  MobilityHelper mob;
  mob.SetMobilityModel("ns3::CircularMobilityModel");
  mob.Install(nodes);

  Ptr<CircularMobilityModel> m0 = DynamicCast<CircularMobilityModel>(
      nodes.Get(0)->GetObject<MobilityModel>());
  Ptr<CircularMobilityModel> m1 = DynamicCast<CircularMobilityModel>(
      nodes.Get(1)->GetObject<MobilityModel>());

  m0->SetParameters(Vector(150, 150, 235), 135, 90, 10);
  m1->SetParameters(Vector(150, 150, 235), 100, 90, 10);

  // Open the file for writing
  outputFile.open("results/vis/circular-mobility-model-coordinates.txt");

  // Write the header to the file
  outputFile << "n0_posx\tn0_posy\tn1_posx\tn1_posy" << std::endl;

  Simulator::Schedule(Seconds(1), &PrintInfo);
  Simulator::Stop(Seconds(120));
  Simulator::Run();
  Simulator::Destroy();

  // Close the file when simulation is done
  outputFile.close();

  return 0;
}
