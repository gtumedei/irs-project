#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Distance: ");
  Serial.print(ultraSensor.distanceCm());
  Serial.println(" cm");
  delay(1000);
}