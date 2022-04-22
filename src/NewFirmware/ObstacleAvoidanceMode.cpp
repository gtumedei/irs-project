#include "NewFirmware.h"

#define HIGH_DISTANCE 20
#define LOW_DISTANCE 5

#define TURN_DELAY 5000

bool tryLeft = false;
bool tryRight = false;
unsigned long lastTurnTimestamp = 0;

uint8_t distance = 0;

void wander() {
  tryLeft = false;
  tryRight = false;
  uint8_t r = random(30);
  unsigned long timestamp = millis();
  bool canTurn = timestamp - lastTurnTimestamp > TURN_DELAY;
  if (r == 0 && canTurn) {
    wheels.turnRight(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  } else if (r == 1 && canTurn) {
    wheels.turnLeft(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  } else {
    wheels.forward(moveSpeed);
    delay(100);
  }
}

void avoidObstacle() {
  if (tryLeft && tryRight) {
    tryLeft = false;
    tryRight = false;
    wheels.backward(moveSpeed);
  } else if (tryLeft && distance < LOW_DISTANCE) {
    wheels.turnRight(moveSpeed);
    tryRight = true;
  } else if (tryRight && distance < LOW_DISTANCE) {
    wheels.turnLeft(moveSpeed);
    tryLeft = true;
  } else {
    uint8_t r = random(2);
    switch (r)
    {
      case 0:
        wheels.turnLeft(moveSpeed);
        tryLeft = true;
        break;
      case 1:
        wheels.turnRight(moveSpeed);
        tryRight = true;
        break;
    }
  }
  delay(300);
}

void obstacleAvoidanceMode() {
  distance = ultrasonicSensor.distanceCm();
  if (distance > HIGH_DISTANCE || distance == 0) {
    wander();
  } else {
    avoidObstacle();
  }
}