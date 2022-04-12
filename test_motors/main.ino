/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    DCMotorDriverTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/09
 * @brief   Description: this file is sample code for Me DC motor device.
 *
 * Function List:
 *    1. void MeDCMotor::run(int16_t speed)
 *    2. void MeDCMotor::stop(void)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2015/09/09    1.0.0          rebuild the old lib
 * </pre>
 */
#include "MeMCore.h""

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
