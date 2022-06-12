#include "MeMBotFirmware.h"

#define AVOID_DISTANCE 20
#define CRITICAL_DISTANCE 5

#define TURN_DELAY 5000

uint8_t distance = 0;

// Wether or not the robot has tried turning left and right to avoid an obstacle
bool avoiding = false;
bool changedDirection = false;

// Timestamp of the last turn (both random turns and obstacle avoidance turns)
unsigned long lastTurnTimestamp = 0;

TurnDirection turnDirection = DIR_NONE;

void wander()
{
  // Reset obstacle avoidance variables
  avoiding = false;
  changedDirection = false;
  turnDirection = DIR_NONE;

  unsigned long timestamp = millis();
  bool canTurn = timestamp - lastTurnTimestamp > TURN_DELAY;
  uint8_t r = random(30);
  if (r == 0 && canTurn)
  {
    wheels.forwardAndTurnRight(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  }
  else if (r == 1 && canTurn)
  {
    wheels.forwardAndTurnLeft(moveSpeed);
    lastTurnTimestamp = timestamp;
    delay(500);
  }
  else
  {
    wheels.forward(moveSpeed);
    delay(100);
  }
}

void avoidObstacle()
{
  lastTurnTimestamp = millis();
  if (!avoiding)
  {
    // On first entering avoidance mode, turn in a random direction
    avoiding = true;
    turnDirection = random(2) == 0 ? DIR_RIGHT : DIR_LEFT;
    wheels.turn(turnDirection, moveSpeed);
  }
  else
  {
    // Invert turning direction if the distance has lowed
    if (distance < CRITICAL_DISTANCE && !changedDirection)
    {
      changedDirection = true;
      turnDirection = turnDirection == DIR_RIGHT ? DIR_LEFT : DIR_RIGHT;
    }
    wheels.turn(turnDirection, moveSpeed);
  }
  delay(300);
}

void obstacleAvoidanceMode()
{
  distance = ultrasonicSensor.distanceCm();
  if (distance > AVOID_DISTANCE || distance == 0)
  {
    wander();
  }
  else
  {
    avoidObstacle();
  }
}

void autoMode()
{
  obstacleAvoidanceMode();
}