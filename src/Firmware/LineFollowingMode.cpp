#include "Firmware.h"

int lineFollowFlag = 0;

void lineFollowingMode() {
  uint8_t val;
  val = lineFollower.readSensors();
  if (moveSpeed > 230)
  {
    moveSpeed = 230;
  }
  switch (val)
  {
    case S1_IN_S2_IN:
      wheels.forward(moveSpeed);
      lineFollowFlag = 10;
      break;

    case S1_IN_S2_OUT:
      wheels.forward(moveSpeed);
      if (lineFollowFlag > 1)
      {
        lineFollowFlag--;
      }
      break;

    case S1_OUT_S2_IN:
      wheels.forward(moveSpeed);
      if (lineFollowFlag < 20)
      {
        lineFollowFlag++;
      }
      break;

    case S1_OUT_S2_OUT:
      if (lineFollowFlag == 10)
      {
        wheels.backward(moveSpeed);
      }
      if (lineFollowFlag < 10)
      {
        wheels.forwardAndTurnLeft(moveSpeed);
      }
      if (lineFollowFlag > 10)
      {
        wheels.forwardAndTurnRight(moveSpeed);
      }
      break;
  }
}