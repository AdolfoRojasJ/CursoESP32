// I2C Address Detector
#include <Wire.h>
void setup() {
  Serial.begin(115200);
  delay(200);
  Wire.begin();
  Serial.println();
  Serial.println("Buscador de esclavos I2C");
  Serial.println();
}

void loop() {
  uint8_t data, dir;
  Serial.println("Buscando");
  for(dir=0;dir<128;dir++)
  {
    Wire.beginTransmission(dir);
    data=Wire.endTransmission(dir);
    if(data==0)
    {
      Serial.println("Dato encontrado en direccion 0x");
      Serial.println(dir,HEX);
    }
  }
  delay(5000);
}
