//ESP32 WiFi Station Library
#include<WiFi.h>
#define SSID ".:PC Puma FI:."
#define PASS NULL

void connection(char *_ssid = ".:PC Puma FI:.", char *_pass = NULL);

void connection(char *_ssid, char *_pass)
{
  WiFi.mode(WIFI_STA);
  delay(250);
  Serial.println();
  Serial.println("Conectando ESP32 a "+String(SSID));
  Serial.println();
  WiFi.begin(_ssid,_pass);
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
}
