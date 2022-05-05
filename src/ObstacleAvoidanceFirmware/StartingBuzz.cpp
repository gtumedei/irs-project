#include "ObstacleAvoidanceFirmware.h"

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