#include "MeMCore.h"

MeDCMotor leftWheel(M1);

MeDCMotor rightWheel(M2);

uint8_t motorSpeed = 100;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  leftWheel.run(-motorSpeed);
  Serial.println("Left wheel spinning");
  delay(2000);
  leftWheel.stop();
  rightWheel.run(motorSpeed);
  Serial.println("Right wheel spinning");
  delay(2000);
  rightWheel.stop();
  delay(2000);

  leftWheel.run(-motorSpeed);
  rightWheel.run(motorSpeed);
  Serial.println("Wheels spinning forward");
  delay(2000);
  leftWheel.stop();
  rightWheel.stop();
  delay(500);
  leftWheel.run(motorSpeed);
  rightWheel.run(-motorSpeed);
  Serial.println("Wheels spinning backrward");
  delay(2000);
  leftWheel.stop();
  rightWheel.stop();
  delay(2000);
}
