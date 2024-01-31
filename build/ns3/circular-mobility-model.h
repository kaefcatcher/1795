/*
 * NOTE : Using a custom Mobility Model works, but have issues working with
 * PyViz due to lack of Python Bindings. therefore, work on this is halted for
 * now.
 */

#ifndef NS3_SCRATCH_CIRCULAR_MOBILITY_MODEL_H
#define NS3_SCRATCH_CIRCULAR_MOBILITY_MODEL_H

// #include "ns3/constant-acceleration-mobility-model.h"
#include "ns3/event-id.h"
#include "ns3/mobility-model.h"
#include "ns3/nstime.h"
namespace ns3 {

class CircularMobilityModel : public MobilityModel {
public:
  static TypeId GetTypeId(void);

  virtual TypeId GetInstanceTypeId() const;

  CircularMobilityModel();
  virtual ~CircularMobilityModel();
  void SetParameters(const Vector &Origin, const double Radius,
                     const double StartAngle, const double Speed);
  virtual Vector DoGetPosition(void) const;
  virtual void DoSetPosition(const Vector &position);
  virtual Vector DoGetVelocity(void) const;
  void DoSetVelocityAngleRadius (const double Radius,
                     const double StartAngle, const double Speed);
private:
  void Test(void);

  Vector m_position;
  Vector m_Origin;
  double m_Radius;
  double m_StartAngle;
  double m_Speed;
  Time m_lastUpdate;
};

} // namespace ns3

#endif