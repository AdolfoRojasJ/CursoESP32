//ESP32 - GPIO

#define led 2     
int del = 250;   
bool led_sta = 0; 

void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  // GPIO
  pinMode(led,OUTPUT); //Pin led=2 como salida

  Serial.println();
  Serial.println("Blink serial");
  Serial.println();
}

void loop() {
if(Serial.available()){
String s = Serial.readStringUntil('\n');
del = s.toInt();
if(del<10) del=10;
if(del>250) del=250;
}

digitalWrite(led,led_sta); 
led_sta = !led_sta;
delay(del);                
}