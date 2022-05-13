#ifndef GenericFirmaware_H
#define GenericFirmaware_H

#include <MeMCore.h>
#include "BuzzerTones.h"
#include "MeWheels.h"

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
  MANUAL_MODE,
  AUTO_MODE
};

extern MeRGBLed rgbLed;
extern MeUltrasonicSensor ultrasonicSensor;
extern MeLineFollower lineFollower;
extern MeLightSensor rightLightSensor;
extern MeLightSensor leftLightSensor;
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
void manualMode();
void autoMode();
void startingBuzz();

#endif