//ESP32 WiFi Station Library
#include<WiFi.h>
#define SSID ".:PC Puma FI:."
#define PASS NULL

void connection(char *_ssid = ".:PC Puma FI:.", char *_pass = NULL);
void hotspot(char* ssid = "Hy3n4", char* password = "qu4ck1n5hy3n4!");

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

void hotspot(char* ssid, char* password){
  WiFi.mode(WIFI_AP); 
  delay(250);
  Serial.println("ESP32 como punto de acceso con el SSID: " + String(ssid) + "\nY la contraseña: *****");
  WiFi.softAP(ssid, password);
  IPAddress apIP = WiFi.softAPIP(); //Lee la dirección IP del punto de acceso.
  Serial.print("Dirección IP: ");
  Serial.println(apIP);
}
