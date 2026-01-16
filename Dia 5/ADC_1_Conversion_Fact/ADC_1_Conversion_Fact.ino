//ESP32 POTENCIOMETRO ADC
#define POT 4
float voltage_write = 0;
float conversion_factor = 3.3/4095.0;
void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Señal Analógica");
  Serial.println();
}

void loop() {
  voltage_write = analogRead(POT) * conversion_factor;
  Serial.println(voltage_write);
  delay(100);
}
