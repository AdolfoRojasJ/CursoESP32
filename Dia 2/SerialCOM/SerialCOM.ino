// SERIAL COM
String chain = ":D";
String msg = "Hola Edmundo!!!";
void setup() {
  Serial.begin(115200);
  
}

void loop() {
  Serial.println();
  Serial.println("1 Hola Edmundo!!!");
  Serial.print("2 Hola Edmundo!!!\n");
  Serial.printf("3 %s", msg);
  Serial.println("4 " + msg);
  int num = 5;
  Serial.print(String(num) + " " + msg);
    // Serial.println(chain);
    // delay(500);
  delay(1000);
}
