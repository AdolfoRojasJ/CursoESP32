// BLUETOOTH
#include <BluetoothSerial.h>;
BluetoothSerial bt;

void setup() {
  Serial.begin(115200);
  delay(200);
  bt.begin("Hy3n4");
  delay(500);
  Serial.println();
  Serial.println("Cuenta las veces que el botón es presionado con interrupcion");
  Serial.println();
}

void loop() {
  String s = "";
  if(Serial.available()){
    s = Serial.readStringUntil('\n');
    Serial.println("PC: " +s);
    bt.println(s);
  }
  if(bt.available())
  {
    s = bt.readStringUntil('\n');
    Serial.println("BT: " +s);
    bt.println(s);
  }

}
