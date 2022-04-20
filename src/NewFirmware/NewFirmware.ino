#include "NewFirmware.h"

MeRGBLed rgbLed(0, 16);
MeUltrasonicSensor ultrasonicSensor(PORT_3);
MeLineFollower lineFollower(PORT_2);
MeIR ir;
MeBuzzer buzzer;
MeWheels wheels(M2, M1);

int moveSpeed = 200;
int minSpeed = 48;
int factor = 23;

Direction motorState = STOP;
Direction prevMotorState = STOP;
Mode mode = DRIVING_MODE;

void setup()
{
  delay(5);
  wheels.stop();
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  rgbLed.reset(PORT_7, SLOT2);
  rgbLed.setColor(0, 0, 0);
  rgbLed.show();
  delay(1);
  rgbLed.setColor(10, 0, 0);
  rgbLed.show();
  startingBuzz();
  Serial.begin(9600);
  ir.begin();
}

void loop()
{
  while (1)
  {
    handleIRCommand();
    handleBuiltinButton();
    // Execute the selected mode
    switch (mode)
    {
      case DRIVING_MODE:
        drivingMode();
        break;
      case OBSTACLE_AVOIDANCE_MODE:
        obstacleAvoidanceMode();
        break;
      case LINE_FOLLWING_MODE:
        lineFollowingMode();
        break;
    }
  }
}