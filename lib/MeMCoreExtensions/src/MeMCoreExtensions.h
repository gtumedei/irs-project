#ifndef MeMCoreExtensions_H
#define MeMCoreExtensions_H

#include "MeDCMotor.h"

class MeWheels {
private:
  MeDCMotor rightMotor;
  MeDCMotor leftMotor;

public:
  MeWheels(uint8_t rightWheelPort, uint8_t leftWheelPort);
  void spinRight(int16_t speed);
  void spinLeft(int16_t speed);
  void stopRight();
  void stopLeft();
  void forward(int moveSpeed);
  void backward(int moveSpeed);
  void turnLeft(int moveSpeed, float factor = 0.8);
  void turnRight(int moveSpeed, float factor = 0.8);
  void forwardAndTurnLeft(int moveSpeed, float factor = 0.2);
  void forwardAndTurnRight(int moveSpeed, float factor = 0.2);
  void backwardAndTurnLeft(int moveSpeed, float factor = 0.333);
  void backwardAndTurnRight(int moveSpeed, float factor = 0.333);
  void stop();
};

#endif
