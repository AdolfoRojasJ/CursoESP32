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
  // put your main code here, to run repeatedly:

}
