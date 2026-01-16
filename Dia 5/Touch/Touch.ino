//ESP32 TOUCH
#define PAD 15
#define UMBRAL 1544 //DEPENDE DE LA TARJETA Y DEL VALOR LEÍDO
void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Touch");
  Serial.println();
}

void loop() {
  //Serial.println(touchRead(PAD));
  if (touchRead(PAD)<UMBRAL)
  {
     Serial.println("TOUCHED");
     while(touchRead(PAD)<UMBRAL){
       delay(50);
     }
     Serial.println("NOT TOUCHED");
   }
   delay(50);
}
