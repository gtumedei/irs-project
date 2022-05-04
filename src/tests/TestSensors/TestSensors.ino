#include "MeMCore.h"
#include "MeMCoreExtensions.h"

MeLineFollower lineSensor(PORT_2);
MeUltrasonicSensor ultrasonicSensor(PORT_1);
MeLightSensor rightLightSensor(PORT_4);
MeLightSensor leftLightSensor(PORT_3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lineSensorState = lineSensor.readSensors();
  double distance = ultrasonicSensor.distanceCm();
  int rightValue = rightLightSensor.read();
  int leftValue = leftLightSensor.read();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Left light value = ");
  Serial.println(leftValue);
  Serial.print("Right light value = ");
  Serial.println(rightValue);

  switch(lineSensorState)
  {
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 IN sensor 2 IN");
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 1 IN sensor 2 OUT");
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 OUT sensor 2 IN");
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 OUT sensor 2 OUT");
      break;
    default:
      break;
  }
  delay(1000);
}
