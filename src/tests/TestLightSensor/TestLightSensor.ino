#include "MeMCore.h"

MeLightSensor rightLightSensor(PORT_4);
MeLightSensor leftLightSensor(PORT_3);

int rightValue = 0;
int leftValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rightValue = rightLightSensor.read();
  leftValue = leftLightSensor.read();

  Serial.print("Left value = ");
  Serial.println(leftValue);
  Serial.print("Right value = ");
  Serial.println(rightValue);

  delay(1000);
}
