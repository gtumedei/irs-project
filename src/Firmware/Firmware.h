#ifndef Firmware_H
#define Firmware_H

#include <MeMCore.h>
#include "BuzzerTones.h"
#include "MeMCoreExtensions.h"

// Wheels directions
enum Direction {
  RUN_F = 0x01,
  RUN_B = 0x01<<1,
  RUN_L = 0x01<<2,
  RUN_R = 0x01<<3,
  STOP = 0
};

// Robot modes
enum Mode {
  DRIVING_MODE,
  OBSTACLE_AVOIDANCE_MODE,
  LINE_FOLLWING_MODE
};

// Distances for the ultrasonic sensor
#define HIGH_DISTANCE 15
#define LOW_DISTANCE 15

extern MeRGBLed rgbLed;
extern MeUltrasonicSensor ultrasonicSensor;
extern MeLineFollower lineFollower;
extern MeIR ir;
extern MeBuzzer buzzer;
extern MeWheels wheels;

extern Direction motorState;
extern Direction prevMotorState;
extern Mode mode;

extern int moveSpeed;
extern int minSpeed;
extern int factor;

void handleIRCommand();
void handleBuiltinButton();
void drivingMode();
void lineFollowingMode();
void obstacleAvoidanceMode();
void startingBuzz();

#endif