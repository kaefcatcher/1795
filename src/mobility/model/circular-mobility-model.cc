#include "circular-mobility-model.h"
#include "ns3/log.h"
#include "ns3/nstime.h"
#include "ns3/simulator.h"
#include <cmath>
#include <iomanip>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE("CircularMobilityModel");
NS_OBJECT_ENSURE_REGISTERED(CircularMobilityModel);

TypeId CircularMobilityModel::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::CircularMobilityModel")
                          .SetParent<MobilityModel>()
                          .SetGroupName("circ")
                          .AddConstructor<CircularMobilityModel>();
  return tid;
}

TypeId CircularMobilityModel::GetInstanceTypeId() const {
  return CircularMobilityModel::GetTypeId();
}

CircularMobilityModel::CircularMobilityModel()
    : m_Origin(Vector(0, 0, 0)), m_Radius(0), m_StartAngle(0), m_Speed(0),
      m_lastUpdate(Simulator::Now()) {}

CircularMobilityModel::~CircularMobilityModel() {}

void CircularMobilityModel::SetParameters(const Vector &Origin,
                                          const double Radius,
                                          const double StartAngle,
                                          const double Speed) {
  DoSetPosition(Origin);
  m_Origin = Origin;
  m_Radius = Radius;
  m_StartAngle = StartAngle;
  m_Speed = Speed;
  NotifyCourseChange();
}

void CircularMobilityModel::DoSetPosition(const Vector &position) {
  m_position = position;
  m_lastUpdate = Simulator::Now();
  NotifyCourseChange();
}
  void CircularMobilityModel::DoSetVelocityAngleRadius (const double Radius,
                     const double StartAngle, const double Speed){
                      m_Radius = Radius;
  m_StartAngle = StartAngle;
  m_Speed = Speed;
  NotifyCourseChange();
                     }

Vector CircularMobilityModel::DoGetVelocity(void) const {
  Time now = Simulator::Now();
  NS_ASSERT(m_lastUpdate <= now);

  double angle = m_StartAngle + ((m_Speed / m_Radius) * now.GetSeconds());
  double cosAngle = cos(angle);
  double sinAngle = sin(angle);

  return Vector(-sinAngle * m_Speed, cosAngle * m_Speed, 0.0);
}
Vector CircularMobilityModel::DoGetPosition(void) const {
  return Vector(m_position.x + DoGetVelocity().x,
                m_position.y + DoGetVelocity().y,
                m_position.z + DoGetVelocity().z);
}

} // namespace ns3
