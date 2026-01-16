//ESP32 POTENCIOMETRO ADC
#define POT 4

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Señal Analógica");
  Serial.println();
}

void loop() {
  Serial.println(analogRead(POT));
  delay(100);
}
