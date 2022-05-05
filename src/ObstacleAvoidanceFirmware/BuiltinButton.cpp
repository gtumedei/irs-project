#include "ObstacleAvoidanceFirmware.h"

boolean currentButtonPressed = false;
boolean prevButtonPressed = false;

void handleBuiltinButton() {
  currentButtonPressed = !(analogRead(7) > 100);
  if (currentButtonPressed != prevButtonPressed)
  {
    if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
    {
      rgbLed.reset(PORT_7, SLOT2);
    }
    prevButtonPressed = currentButtonPressed;
    if (currentButtonPressed == true)
    {
      if (mode == MANUAL_MODE)
      {
        mode = AUTO_MODE;
        moveSpeed = 200;
        wheels.stop();
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        buzzer.noTone();
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0, 0, 10);
        rgbLed.show();
      }
      else if (mode == AUTO_MODE)
      {
        mode = MANUAL_MODE;
        moveSpeed = 220;
        wheels.stop();
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