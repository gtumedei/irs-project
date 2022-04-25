#include "MeMCore.h"
#include "MeMCoreExtensions.h"

MeWheels wheels(M2, M1);
MeLineFollower lineSensor(PORT_2);
MeUltrasonicSensor ultrasonicSensor(PORT_3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lineSensorState = lineSensor.readSensors();
  double distance = ultrasonicSensor.distanceCm();
  int speed = distance * 255 / 400;

  if (speed < 50) {
    speed = 0;
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Speed: ");
  Serial.println(speed);

  switch(lineSensorState)
  {
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 and 2 are inside of the black line");
      wheels.spinRight(speed);
      wheels.spinLeft(speed);
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 2 is outside of the black line");
      wheels.spinRight(-speed);
      wheels.spinLeft(speed);
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of the black line");
      wheels.spinRight(speed);
      wheels.spinLeft(-speed);
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 and 2 are outside of the black line");
      wheels.spinRight(-speed);
      wheels.spinLeft(-speed);
      break;
    default:
      break;
  }
  delay(200);
}
