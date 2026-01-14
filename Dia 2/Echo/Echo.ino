// UART ECHO
void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Eco Serial");
  Serial.println();
}

void loop() {
  if(Serial.available())
  {
    Serial.write(Serial.read());
  }
}
