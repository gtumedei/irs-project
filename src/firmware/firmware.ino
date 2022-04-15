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
Mode mode = DRIVING_MODE;

void handleOnBoardButton() {
  currentButtonPressed = !(analogRead(7) > 100);
  if (currentButtonPressed != prevButtonPressed)
  {
    if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
    {
      rgbLed.reset(PORT_7,SLOT2);
    }
    prevButtonPressed = currentButtonPressed;
    if (currentButtonPressed == true)
    {
      if (mode == DRIVING_MODE)
      {
        mode = OBSTACLE_AVOIDANCE_MODE;
        moveSpeed = 200;
        stop();
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        buzzer.noTone();
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0, 10, 0);
        rgbLed.show();
      }
      else if (mode == OBSTACLE_AVOIDANCE_MODE)
      {
        mode = LINE_FOLLWING_MODE;
        moveSpeed = 200;
        stop();
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        buzzer.noTone();
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0, 0, 10);
        rgbLed.show();
      }
      else if (mode == LINE_FOLLWING_MODE)
      {
        mode = DRIVING_MODE;
        moveSpeed = 220;
        stop();
        cli();
        buzzer.tone(NTD1, 300);
        sei();
        buzzer.noTone();
        rgbLed.setColor(0, 0, 0);
        rgbLed.setColor(10, 10, 10);
        rgbLed.show();
      }
    }
  }
}

void handleIRCommand()
{
  static long time = millis();
  if (ir.decode())
  {
    uint32_t value = ir.value;
    time = millis();
    switch ((value >> 16) & 0xff)
    {
      case IR_BUTTON_A:
        moveSpeed = 220;
        mode = DRIVING_MODE;
        stop();
        cli();
        buzzer.tone(NTD1, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(10,10,10);
        rgbLed.show();
        break;
      case IR_BUTTON_B:
        moveSpeed = 200;
        mode = OBSTACLE_AVOIDANCE_MODE;
        stop();
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0,10,0);
        rgbLed.show();
        break;
      case IR_BUTTON_C:
        moveSpeed = 200;
        mode = LINE_FOLLWING_MODE;
        stop();
        cli();
        buzzer.tone(NTD3, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0,0,10);
        rgbLed.show();
        break;
      case IR_BUTTON_PLUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_F;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_MINUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_B;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(10,0,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_NEXT:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_R;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(1,10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_PREVIOUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_L;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(2,10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_9:
        cli();
        buzzer.tone(NTDH2, 300);
        sei();
        changeSpeed(factor * 9 + minSpeed);
        break;
      case IR_BUTTON_8:
        cli();
        buzzer.tone(NTDH1, 300);
        sei();
        changeSpeed(factor * 9 + minSpeed);
        break;
      case IR_BUTTON_7:
        cli();
        buzzer.tone(NTD7, 300);
        sei();
        changeSpeed(factor * 9 + minSpeed);
        break;
      case IR_BUTTON_6:
        cli();
        buzzer.tone(NTD6, 300);
        sei();
        changeSpeed(factor * 6 + minSpeed);
        break;
      case IR_BUTTON_5:
        cli();
        buzzer.tone(NTD5, 300);
        sei();
        changeSpeed(factor * 6 + minSpeed);
        break;
      case IR_BUTTON_4:
        cli();
        buzzer.tone(NTD4, 300);
        sei();
        changeSpeed(factor * 6 + minSpeed);
        break;
      case IR_BUTTON_3:
        cli();
        buzzer.tone(NTD3, 300);
        sei();
        changeSpeed(factor * 3 + minSpeed);
        break;
      case IR_BUTTON_2:
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        changeSpeed(factor * 3 + minSpeed);
        break;
      case IR_BUTTON_1:
        cli();
        buzzer.tone(NTD1, 300);
        sei();
        changeSpeed(factor * 3 + minSpeed);
        break;
    }
  }
  else if (millis() - time > 120)
  {
    motorState = STOP;
    time = millis();
    if (mode == DRIVING_MODE )
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(10, 10, 10);
      rgbLed.show();
    }
    else if (mode == OBSTACLE_AVOIDANCE_MODE )
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(0, 10, 0);
      rgbLed.show();
    }
    else if (mode == LINE_FOLLWING_MODE)
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(0, 0, 10);
      rgbLed.show();
    }
  }
}

void forward()
{
  wheels.spinLeft(moveSpeed);
  wheels.spinRight(moveSpeed);
}

void backward()
{
  wheels.spinLeft(-moveSpeed);
  wheels.spinRight(-moveSpeed);
}

void turnLeft()
{
  wheels.spinLeft(-moveSpeed*0.8);
  wheels.spinRight(moveSpeed*0.8);
}

void turnRight()
{
  wheels.spinLeft(moveSpeed*0.8);
  wheels.spinRight(-moveSpeed*0.8);
}

void turnLeft2()
{
  wheels.spinLeft(moveSpeed/5);
  wheels.spinRight(moveSpeed);
}

void turnRight2()
{
  wheels.spinLeft(moveSpeed);
  wheels.spinRight(moveSpeed/5);
}

void backwardAndTurnLeft()
{
  wheels.spinLeft(-moveSpeed/3 );
  wheels.spinRight(-moveSpeed);
}

void backwardAndTurnRight()
{
  wheels.spinLeft(-moveSpeed);
  wheels.spinRight(-moveSpeed/3);
}

void stop()
{
  rgbLed.setColor(0,0,0);
  rgbLed.show();
  wheels.stopLeft();
  wheels.stopRight();
}

uint8_t prevState = 0;

void changeSpeed(int spd)
{
  moveSpeed = spd;
}

void drivingMode()
{
  switch (motorState)
  {
    case RUN_F:
      forward();
      prevState = motorState;
      break;
    case RUN_B:
      backward();
      prevState = motorState;
      break;
    case RUN_L:
      turnLeft();
      prevState = motorState;
      break;
    case RUN_R:
      turnRight();
      prevState = motorState;
      break;
    case STOP:
      if (prevState != motorState)
      {
        prevState = motorState;
        stop();
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
    forward();
  }
  else if ((d > LOW_DISTANCE) && (d < HIGH_DISTANCE))
  {
    switch (randNumber)
    {
      case 0:
        turnLeft();
        delay(300);
        break;
      case 1:
        turnRight();
        delay(300);
        break;
    }
  }
  else
  {
    switch (randNumber)
    {
      case 0:
        turnLeft();
        delay(800);
        break;
      case 1:
        turnRight();
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
      forward();
      lineFollowFlag = 10;
      break;

    case S1_IN_S2_OUT:
      forward();
      if (lineFollowFlag > 1)
      {
        lineFollowFlag--;
      }
      break;

    case S1_OUT_S2_IN:
      forward();
      if (lineFollowFlag < 20)
      {
        lineFollowFlag++;
      }
      break;

    case S1_OUT_S2_OUT:
      if (lineFollowFlag == 10)
      {
        backward();
      }
      if (lineFollowFlag < 10)
      {
        turnLeft2();
      }
      if (lineFollowFlag > 10)
      {
        turnRight2();
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
  stop();
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
    handleOnBoardButton();
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