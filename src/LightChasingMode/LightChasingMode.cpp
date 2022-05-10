#include <math.h>
#include "MeMBotFirmware.h"

#define AVOID_DISTANCE 20
#define CRITICAL_DISTANCE 5

#define MIN_TRESHOLD 10
#define MAX_TRESHOLD 40

#define TURN_DELAY 5000

int lightRight = 0;
int lightLeft = 0;

int lightTreshold = MIN_TRESHOLD;
int chaseLightLevel = 0;
int doneLightLevel = 0;

uint8_t distance = 0;

// Whether or not the robot has tried turning left and right to avoid an obstacle
bool avoiding = false;
bool changedDirection = false;

// Timestamp of the last turn (both random turns and obstacle avoidance turns)
unsigned long lastTurnTimestamp = 0;

TurnDirection turnDirection = DIR_NONE;

int computeChaseLightLevel() {
  int maxLight = -1;
  wheels.turnLeft(150);
  for (int i = 0; i < 30; i++) {
    lightRight = rightLightSensor.read();
    lightLeft = leftLightSensor.read();
    maxLight = max(maxLight, max(lightLeft, lightRight));
    delay(75);
  }
  wheels.stop();
  return maxLight * 1.1;
}

int computeDoneLightLevel(int chaseLightLevel) {
  return -50 + 155 * log(chaseLightLevel);
}

int computeTreshold() {
  int lightRange = doneLightLevel - chaseLightLevel;
  int tresholdRange = MAX_TRESHOLD - MIN_TRESHOLD;
  double lightMax = max(lightRight, lightLeft);
  if (lightMax > lightRange * 0.75 + chaseLightLevel) {
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
    if (distance < CRITICAL_DISTANCE && !changedDirection) {
      changedDirection = true;
      turnDirection = turnDirection == DIR_RIGHT ? DIR_LEFT : DIR_RIGHT;
    }
    wheels.turn(turnDirection, moveSpeed);
  }
  delay(300);
}

void chaseLight() {
  lightTreshold = computeTreshold();
  if (lightRight > doneLightLevel && lightLeft > doneLightLevel) {
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
  if (doneLightLevel == 0) {
    chaseLightLevel = computeChaseLightLevel();
    doneLightLevel = computeDoneLightLevel(chaseLightLevel);
    Serial.print("Chase level: ");
    Serial.println(chaseLightLevel);
    Serial.print("Done level: ");
    Serial.println(doneLightLevel);
  }
  Serial.print("Left value = ");
  Serial.println(lightLeft);
  Serial.print("Right value = ");
  Serial.println(lightRight);
  Serial.print("Treshold value = ");
  Serial.println(lightTreshold);
  if (distance <= AVOID_DISTANCE && distance != 0 && !(lightRight > doneLightLevel || lightLeft > doneLightLevel)) {
    avoidObstacle();
  } else if (lightRight >= chaseLightLevel || lightLeft >= chaseLightLevel) {
    chaseLight();
  } else {
    wander();
  }
}

void autoMode() {
  lightChasingMode();
}