#include "NewFirmware.h"

void handleIRCommand()
{
  static long time = millis();
  if (ir.decode())
  {
    uint32_t value = ir.value;
    time = millis();
    switch ((value >> 16) & 0xff)
    {
      case IR_BUTTON_A:
        moveSpeed = 220;
        mode = DRIVING_MODE;
        wheels.stop();
        cli();
        buzzer.tone(NTD1, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(10,10,10);
        rgbLed.show();
        break;
      case IR_BUTTON_B:
        moveSpeed = 200;
        mode = OBSTACLE_AVOIDANCE_MODE;
        wheels.stop();
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0,10,0);
        rgbLed.show();
        break;
      case IR_BUTTON_C:
        moveSpeed = 200;
        mode = LINE_FOLLWING_MODE;
        wheels.stop();
        cli();
        buzzer.tone(NTD3, 300);
        sei();
        if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
        {
          rgbLed.reset(PORT_7,SLOT2);;
        }
        rgbLed.setColor(0,0,0);
        rgbLed.setColor(0,0,10);
        rgbLed.show();
        break;
      case IR_BUTTON_PLUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_F;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_MINUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_B;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(10,0,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_NEXT:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_R;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(1,10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_PREVIOUS:
        if (mode == DRIVING_MODE)
        {
          motorState = RUN_L;
          if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
          {
            rgbLed.reset(PORT_7,SLOT2);;
          }
          rgbLed.setColor(0,0,0);
          rgbLed.setColor(2,10,10,0);
          rgbLed.show();
        }
        break;
      case IR_BUTTON_9:
        cli();
        buzzer.tone(NTDH2, 300);
        sei();
        moveSpeed = factor * 9 + minSpeed;
        break;
      case IR_BUTTON_8:
        cli();
        buzzer.tone(NTDH1, 300);
        sei();
        moveSpeed = factor * 9 + minSpeed;
        break;
      case IR_BUTTON_7:
        cli();
        buzzer.tone(NTD7, 300);
        sei();
        moveSpeed = factor * 9 + minSpeed;
        break;
      case IR_BUTTON_6:
        cli();
        buzzer.tone(NTD6, 300);
        sei();
        moveSpeed = factor * 6 + minSpeed;
        break;
      case IR_BUTTON_5:
        cli();
        buzzer.tone(NTD5, 300);
        sei();
        moveSpeed = factor * 6 + minSpeed;
        break;
      case IR_BUTTON_4:
        cli();
        buzzer.tone(NTD4, 300);
        sei();
        moveSpeed = factor * 6 + minSpeed;
        break;
      case IR_BUTTON_3:
        cli();
        buzzer.tone(NTD3, 300);
        sei();
        moveSpeed = factor * 3 + minSpeed;
        break;
      case IR_BUTTON_2:
        cli();
        buzzer.tone(NTD2, 300);
        sei();
        moveSpeed = factor * 3 + minSpeed;
        break;
      case IR_BUTTON_1:
        cli();
        buzzer.tone(NTD1, 300);
        sei();
        moveSpeed = factor * 3 + minSpeed;
        break;
    }
  }
  else if (millis() - time > 120)
  {
    motorState = STOP;
    time = millis();
    if (mode == DRIVING_MODE )
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(10, 10, 10);
      rgbLed.show();
    }
    else if (mode == OBSTACLE_AVOIDANCE_MODE )
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(0, 10, 0);
      rgbLed.show();
    }
    else if (mode == LINE_FOLLWING_MODE)
    {
      if ((rgbLed.getPort() != PORT_7) || rgbLed.getSlot() != SLOT2)
      {
        rgbLed.reset(PORT_7,SLOT2);;
      }
      rgbLed.setColor(0, 0, 10);
      rgbLed.show();
    }
  }
}