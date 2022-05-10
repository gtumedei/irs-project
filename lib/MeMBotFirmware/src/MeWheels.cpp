#include "MeWheels.h"

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

void MeWheels::forward(int moveSpeed) {
  spinLeft(moveSpeed);
  spinRight(moveSpeed);
}

void MeWheels::backward(int moveSpeed) {
  spinLeft(-moveSpeed);
  spinRight(-moveSpeed);
}

void MeWheels::turn(TurnDirection direction, int moveSpeed, float factor) {
  if (direction == DIR_RIGHT) {
    turnRight(moveSpeed, factor);
  } else if (direction == DIR_LEFT) {
    turnLeft(moveSpeed, factor);
  }
}

void MeWheels::turnLeft(int moveSpeed, float factor) {
  spinLeft(-moveSpeed * factor);
  spinRight(moveSpeed * factor);
}

void MeWheels::turnRight(int moveSpeed, float factor) {
  spinLeft(moveSpeed * factor);
  spinRight(-moveSpeed * factor);
}

void MeWheels::forwardAndTurn(TurnDirection direction, int moveSpeed, float factor) {
  if (direction == DIR_RIGHT) {
    forwardAndTurnRight(moveSpeed, factor);
  } else if (direction == DIR_LEFT) {
    forwardAndTurnLeft(moveSpeed, factor);
  }
}

void MeWheels::forwardAndTurnLeft(int moveSpeed, float factor) {
  spinLeft(moveSpeed * factor);
  spinRight(moveSpeed);
}

void MeWheels::forwardAndTurnRight(int moveSpeed, float factor) {
  spinLeft(moveSpeed);
  spinRight(moveSpeed * factor);
}

void MeWheels::backwardAndTurn(TurnDirection direction, int moveSpeed, float factor) {
  if (direction == DIR_RIGHT) {
    backwardAndTurnRight(moveSpeed, factor);
  } else if (direction == DIR_LEFT) {
    backwardAndTurnLeft(moveSpeed, factor);
  }
}

void MeWheels::backwardAndTurnLeft(int moveSpeed, float factor) {
  spinLeft(-moveSpeed * factor);
  spinRight(-moveSpeed);
}

void MeWheels::backwardAndTurnRight(int moveSpeed, float factor) {
  spinLeft(-moveSpeed);
  spinRight(-moveSpeed * factor);
}

void MeWheels::stop() {
  stopLeft();
  stopRight();
}
