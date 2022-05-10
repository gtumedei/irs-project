#include "MeMBotFirmware.h"

MeRGBLed rgbLed(0, 16);
MeUltrasonicSensor ultrasonicSensor(PORT_1);
MeLineFollower lineFollower(PORT_2);
MeLightSensor rightLightSensor(PORT_4);
MeLightSensor leftLightSensor(PORT_3);
MeIR ir;
MeBuzzer buzzer;
MeWheels wheels(M2, M1);

int moveSpeed = 200;
int minSpeed = 48;
int factor = 23;

Direction motorState = STOP;
Direction prevMotorState = STOP;
Mode mode = MANUAL_MODE;

void setup() {
  delay(5);
  wheels.stop();
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  rgbLed.reset(PORT_7, SLOT2);
  rgbLed.setColor(0, 0, 0);
  rgbLed.show();
  delay(1);
  rgbLed.setColor(10, 0, 0);
  rgbLed.show();
  startingBuzz();
  Serial.begin(9600);
  ir.begin();
  randomSeed(analogRead(6));
}

void loop() {
  while (1)
  {
    handleIRCommand();
    handleBuiltinButton();
    // Execute the selected mode
    switch (mode)
    {
      case MANUAL_MODE:
        manualMode();
        break;
      case AUTO_MODE:
        autoMode();
        break;
    }
  }
}
