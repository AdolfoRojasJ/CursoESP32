// LED BLINK
#define LED 25
void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {
  digitalWrite(LED,0);
  delay(500);
  digitalWrite(LED,1);
  delay(500);
}
