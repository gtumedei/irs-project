#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_1);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Distance: ");
  Serial.print(ultraSensor.distanceCm());
  Serial.println(" cm");
  delay(1000);
}