#ifndef MeMCoreExtensions_H
#define MeMCoreExtensions_H

#ifndef MeDCMotor_H
#include "MeDCMotor.h"
#endif

class MeWheels {
private:
  MeDCMotor rightMotor;
  MeDCMotor leftMotor;

public:
  MeWheels(uint8_t rightWheelPort, uint8_t leftWheelPort);
  void spinRight(uint8_t speed);
  void spinLeft(uint8_t speed);
  void stopRight();
  void stopLeft();
};

#endif
