#include "MeMCore.h"
#include "MeMCoreExtensions.h"

MeWheels wheels(M2, M1);

uint8_t motorSpeed = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  wheels.spinLeft(motorSpeed);
  Serial.println("Left wheel spinning");
  delay(2000);
  wheels.stopLeft();
  wheels.spinRight(motorSpeed);
  Serial.println("Right wheel spinning");
  delay(2000);
  wheels.stopRight();
  delay(2000);

  wheels.spinLeft(motorSpeed);
  wheels.spinRight(motorSpeed);
  Serial.println("Wheels spinning forward");
  delay(2000);
  wheels.stopLeft();
  wheels.stopRight();
  delay(500);
  wheels.spinLeft(-motorSpeed);
  wheels.spinRight(-motorSpeed);
  Serial.println("Wheels spinning backrward");
  delay(2000);
  wheels.stopLeft();
  wheels.stopRight();
  delay(2000);
}
