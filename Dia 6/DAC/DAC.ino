// DAC
#define DAC1 25
#define ADC1 33

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Grafica señales analógicas");
  Serial.println();
}

void loop() {
  for(int i=0;i<256;i++){
    dacWrite(DAC1,1);
    Serial.println(analogRead(ADC1));
    delay(8);
  }
}
