void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Led ON");
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Led OFF");
  delay(500);
}