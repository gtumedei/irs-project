#include "Firmware.h"

void obstacleAvoidanceMode() {
  uint8_t d = ultrasonicSensor.distanceCm(70);
  static long time = millis();
  randomSeed(analogRead(6));
  uint8_t randNumber = random(2);
  if ((d > HIGH_DISTANCE) || (d == 0))
  {
    wheels.forward(moveSpeed);
  }
  else if ((d > LOW_DISTANCE) && (d < HIGH_DISTANCE))
  {
    switch (randNumber)
    {
      case 0:
        wheels.turnLeft(moveSpeed);
        delay(300);
        break;
      case 1:
        wheels.turnRight(moveSpeed);
        delay(300);
        break;
    }
  }
  else
  {
    switch (randNumber)
    {
      case 0:
        wheels.turnLeft(moveSpeed);
        delay(800);
        break;
      case 1:
        wheels.turnRight(moveSpeed);
        delay(800);
        break;
    }
  }
  delay(100);
}