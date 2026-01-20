//ESP32 WiFi Station
#include<WiFi.h>
#define SSID ".:PC Puma FI:."
#define PASS NULL

void setup() {
  Serial.begin(115200);
  delay(200);
  WiFi.mode(WIFI_STA);
  delay(250);
  Serial.println();
  Serial.println("Conectando ESP32 a "+String(SSID));
  Serial.println();
  WiFi.begin(SSID,PASS);
  int WIFI_CTA = 0;
  while(WiFi.status() != WL_CONNECTED && WIFI_CTA<15){
    Serial.print(".");
    delay(500);
    WIFI_CTA++;
  }
  Serial.println();
  if (WIFI_CTA>=15)
  {
    Serial.println("Error, no se pudo establecer conexión");
    Serial.println("Reiniciando");
    delay(3000);
    ESP.restart();
  }
  Serial.println("Conectado a "+String(SSID));
  Serial.println("IP Local: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
