//ESP32 TOUCH
#define PAD 15
#define UMBRAL 45
void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Touch");
  Serial.println();
}

void loop() {
  Serial.println(touchRead(PAD));
  delay(500);
}
