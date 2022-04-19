#include "firmware.h"

MeRGBLed rgbLed(0, 16);
MeUltrasonicSensor ultrasonicSensor(PORT_3);
MeLineFollower lineFollower(PORT_2);
MeIR ir;
MeBuzzer buzzer;
MeWheels wheels(M2, M1);

boolean currentButtonPressed = false;
boolean prevButtonPressed = false;

int lineFollowFlag = 0;
int moveSpeed = 200;
int minSpeed = 48;
int factor = 23;

Direction motorState = STOP;
Direction prevMotorState = STOP;
Mode mode = DRIVING_MODE;

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

void obstacleAvoidanceMode()
{
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

void lineFollowingMode()
{
  uint8_t val;
  val = lineFollower.readSensors();
  if (moveSpeed > 230)
  {
    moveSpeed = 230;
  }
  switch (val)
  {
    case S1_IN_S2_IN:
      wheels.forward(moveSpeed);
      lineFollowFlag = 10;
      break;

    case S1_IN_S2_OUT:
      wheels.forward(moveSpeed);
      if (lineFollowFlag > 1)
      {
        lineFollowFlag--;
      }
      break;

    case S1_OUT_S2_IN:
      wheels.forward(moveSpeed);
      if (lineFollowFlag < 20)
      {
        lineFollowFlag++;
      }
      break;

    case S1_OUT_S2_OUT:
      if (lineFollowFlag == 10)
      {
        wheels.backward(moveSpeed);
      }
      if (lineFollowFlag < 10)
      {
        wheels.forwardAndTurnLeft(moveSpeed);
      }
      if (lineFollowFlag > 10)
      {
        wheels.forwardAndTurnRight(moveSpeed);
      }
      break;
  }
}

void startingBuzz() {
  buzzer.tone(NTD1, 300);
  delay(300);
  rgbLed.setColor(0, 10, 0);
  rgbLed.show();
  buzzer.tone(NTD2, 300);
  delay(300);
  rgbLed.setColor(0, 0, 10);
  rgbLed.show();
  buzzer.tone(NTD3, 300);
  delay(300);
  rgbLed.setColor(10, 10, 10);
  rgbLed.show();
  buzzer.noTone();
}

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