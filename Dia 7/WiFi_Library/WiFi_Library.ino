//ESP32 WiFi Station Library
#include<WiFi.h>
#include<WiFi_Library.h>
#define SSID ".:PC Puma FI:."
#define PASS NULL

void setup() {
  Serial.begin(115200);
  delay(200);
  connection(SSID,PASS);
  Serial.println("Conectado a "+String(SSID));
  Serial.println("IP Local: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
