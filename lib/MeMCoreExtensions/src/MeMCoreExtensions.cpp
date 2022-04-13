#include "MeMCoreExtensions.h"

MeWheels::MeWheels(uint8_t rightWheelPort, uint8_t leftWheelPort) {
  rightMotor.reset(rightWheelPort);
  leftMotor.reset(leftWheelPort);
}

void MeWheels::spinRight(int16_t speed) {
  rightMotor.run(speed);
}

void MeWheels::spinLeft(int16_t speed) {
  leftMotor.run(-speed);
}

void MeWheels::stopRight() {
  rightMotor.run(0);
}

void MeWheels::stopLeft() {
  leftMotor.run(0);
}
