#include "LightChasingFirmware.h"
#include <math.h>

#define HIGH_DISTANCE 20
#define LOW_DISTANCE 5

#define LOW_LIGHT 60
#define HIGH_LIGHT 600
#define LIGHT_TRESHOLD 15

#define TURN_DELAY 5000

uint8_t distance = 0;
int lightRight = 0;
int lightLeft = 0;

// Wether or not the robot has tried turning left and right to avoid an obstacle
bool avoiding = false;
bool changedDirection = false;

// Timestamp of the last turn (both random turns and obstacle avoidance turns)
unsigned long lastTurnTimestamp = 0;

TurnDirection turnDirection = DIR_NONE;

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
  Serial.print("Left value = ");
  Serial.println(lightLeft);
  Serial.print("Right value = ");
  Serial.println(lightRight);
  if (lightRight > HIGH_LIGHT && lightLeft > HIGH_LIGHT) {
    wheels.stop();
  } else if(abs(lightRight - lightLeft) <= LIGHT_TRESHOLD) {
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
  if (distance <= HIGH_DISTANCE && distance != 0) {
    avoidObstacle();
  } else if (lightRight >= LOW_LIGHT || lightLeft >= LOW_LIGHT) {
    chaseLight();
  } else {
    wander();
  }
}

void autoMode() {
  lightChasingMode();
}