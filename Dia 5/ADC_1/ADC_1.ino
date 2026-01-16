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
  Serial.println(map(analogRead(POT),0,4095,0,100));
  delay(100);
}
