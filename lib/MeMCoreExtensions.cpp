#include "MeMCoreExtensions.h"

class MeWheels {
private:
  MeDCMotor rightMotor;
  MeDCMotor leftMotor;

public:
  MeWheels(uint8_t rightWheelPort, uint8_t leftWheelPort) {
    rightMotor.reset(rightWheelPort);
    leftMotor.reset(leftWheelPort);
  }

  void spinRight(uint8_t speed) {
    rightMotor.run(speed);
  }

  void spinLeft(uint8_t speed) {
    leftMotor.run(-speed);
  }

  void stopRight() {
    rightMotor.run(0);
  }

  void stopLeft() {
    leftMotor.run(0);
  }
};
