#include <math.h>
#include "LineFollowingFirmware.h"

#define MAX_SPEED 255
#define MIN_SPEED 230

int direction = 0;

int computeMoveSpeed() {
  int speed = MAX_SPEED * (1 - abs(direction) / 10);
  return max(speed, MIN_SPEED);
}

void lineFollowingMode() {
  uint8_t sensorsValue = lineFollower.readSensors();
  Serial.println(moveSpeed);
  switch (sensorsValue)
  {
    case S1_IN_S2_IN:
      direction = 0;
      moveSpeed = computeMoveSpeed();
      wheels.forward(moveSpeed);
      break;

    case S1_IN_S2_OUT:
      if (direction > -10)
      {
        direction--;
      }
      moveSpeed = computeMoveSpeed();
      wheels.forward(moveSpeed);
      break;

    case S1_OUT_S2_IN:
      if (direction < 10)
      {
        direction++;
      }
      moveSpeed = computeMoveSpeed();
      wheels.forward(moveSpeed);
      break;

    case S1_OUT_S2_OUT:
      if (direction == 0)
      {
        wheels.backward(moveSpeed);
      }
      else if (direction < 0)
      {
        wheels.forwardAndTurnLeft(moveSpeed);
      }
      else if (direction > 0)
      {
        wheels.forwardAndTurnRight(moveSpeed);
      }
      break;
  }
}

void autoMode() {
  lineFollowingMode();
}