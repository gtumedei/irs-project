#include <math.h>
#include "MeMBotFirmware.h"

#define HIGH_DISTANCE 20
#define LOW_DISTANCE 5

#define MIN_TRESHOLD 10
#define MAX_TRESHOLD 40

#define TURN_DELAY 5000

uint8_t distance = 0;
int lightRight = 0;
int lightLeft = 0;
int lightTreshold = MIN_TRESHOLD;
int lowLight = 0;
int highLight = 0;

// Wether or not the robot has tried turning left and right to avoid an obstacle
bool avoiding = false;
bool changedDirection = false;

// Timestamp of the last turn (both random turns and obstacle avoidance turns)
unsigned long lastTurnTimestamp = 0;

TurnDirection turnDirection = DIR_NONE;

int computeLowLight() {
  int lowLight = 1000;
  wheels.turnLeft(100);
  for (int i = 0; i<30; i++) {
    lightRight = rightLightSensor.read();
    lightLeft = leftLightSensor.read();
    int minLight = min(lightLeft, lightRight);
    lowLight = minLight < lowLight ? minLight : lowLight;
    delay(100);
  }
  wheels.stop();
  return lowLight;
}

int computeTreshold() {
  int lightRange = highLight - lowLight;
  int tresholdRange = MAX_TRESHOLD - MIN_TRESHOLD;
  double lightMax = max(lightRight, lightLeft);
  if (lightMax > lightRange * 0.75 + 60) {
    return lightMax * tresholdRange / lightRange;
  }
  return MIN_TRESHOLD;
}

void wander() {
  // Reset obstacle avoidance variables
  avoiding = false;
  changedDirection = false;
  turnDirection = DIR_NONE;

  unsigned long timestamp = millis();
  bool canTurn = timestamp - lastTurnTimestamp > TURN_DELAY;
  uint8_t r = random(30);
  if (r == 0 && canTurn) {
    wheels.forwardAndTurnRight(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  } else if (r == 1 && canTurn) {
    wheels.forwardAndTurnLeft(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  } else {
    wheels.forward(moveSpeed);
    delay(100);
  }
}

void avoidObstacle() {
  lastTurnTimestamp = millis();
  if (!avoiding) {
    // On first entering avoidance mode, turn in a random direction
    avoiding = true;
    turnDirection = random(2) == 0 ? DIR_RIGHT : DIR_LEFT;
    wheels.turn(turnDirection, moveSpeed);
  } else {
    // Invert turning direction if the distance has lowed
    if (distance < LOW_DISTANCE && !changedDirection) {
      changedDirection = true;
      turnDirection = turnDirection == DIR_RIGHT ? DIR_LEFT : DIR_RIGHT;
    }
    wheels.turn(turnDirection, moveSpeed);
  }
  delay(300);
}

void chaseLight() {
  lightTreshold = computeTreshold();
/*   Serial.print("Left value = ");
  Serial.println(lightLeft);
  Serial.print("Right value = ");
  Serial.println(lightRight);
  Serial.print("Treshold value = ");
  Serial.println(lightTreshold); */
  if (lightRight > highLight && lightLeft > highLight) {
    wheels.stop();
  } else if (abs(lightRight - lightLeft) <= lightTreshold) {
    wheels.forward(moveSpeed);
  } else if (lightRight > lightLeft) {
    wheels.forwardAndTurnRight(moveSpeed);
  } else {
    wheels.forwardAndTurnLeft(moveSpeed);
  }
}

void lightChasingMode() {
  distance = ultrasonicSensor.distanceCm();
  lightRight = rightLightSensor.read();
  lightLeft = leftLightSensor.read();
  if (highLight == 0) {
    lowLight = computeLowLight();
    highLight = min(lowLight * 10, 950);
    Serial.print("Luce minima: ");
    Serial.println(lowLight);
    Serial.print("Luce massima: ");
    Serial.println(highLight);
  }
  if (distance <= HIGH_DISTANCE && distance != 0 && !(lightRight > highLight || lightLeft > highLight)) {
    avoidObstacle();
  } else if (lightRight >= lowLight || lightLeft >= lowLight) {
    chaseLight();
  } else {
    wander();
  }
}

void autoMode() {
  lightChasingMode();
}