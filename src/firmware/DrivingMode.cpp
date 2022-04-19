#include "firmware.h"

void drivingMode()
{
  switch (motorState)
  {
    case RUN_F:
      wheels.forward(moveSpeed);
      prevMotorState = motorState;
      break;
    case RUN_B:
      wheels.backward(moveSpeed);
      prevMotorState = motorState;
      break;
    case RUN_L:
      wheels.turnLeft(moveSpeed);
      prevMotorState = motorState;
      break;
    case RUN_R:
      wheels.turnRight(moveSpeed);
      prevMotorState = motorState;
      break;
    case STOP:
      if (prevMotorState != motorState)
      {
        prevMotorState = motorState;
        wheels.stop();
      }
      break;
  }
}