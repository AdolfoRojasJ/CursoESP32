// LED BLINK v2
#define LED 25
#define DELAY 2000
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  int i = 0;
  while (i<200)
  {
    digitalWrite(LED,0);
    delay(DELAY+i);
    digitalWrite(LED,1);
    delay(DELAY-i);
    i=i+10;
    Serial.println(i);
  }
}