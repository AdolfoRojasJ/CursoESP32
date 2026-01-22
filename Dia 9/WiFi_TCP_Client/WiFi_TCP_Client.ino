#include <WiFi.h>
#include <WiFi_Library.h>

WiFiServer server(777);

#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"
int counter=0;
const char* serverIP="192.168.50.242";

void setup() {
  Serial.begin(115200);
  delay(200);
  connection(ssid,pass);

  Serial.println();
  Serial.println("Cliente TCP");
  Serial.println();
}

void loop() {
  WiFiClient client;
  Serial.println("Conectando con el servidor");
  if(client.connect(serverIP,777)){
    Serial.println("Servidor conectado");
    Serial.println("Enviando datos");

    counter++;
    client.println("Cuenta: "+String(counter));
    unsigned long response = millis();
    while(client.available()==0)
    {
      if(millis()-response > 5000)
      {
        Serial.println("Error: Tiempo de espera agotado");
        client.stop();
        return;
      }
    }
    while(client.available())
    {
      String msg = client.readStringUntil('\r');
      Serial.println("Servidor: "+msg);
    }
    client.stop();
    Serial.println("Conexión cerrada");
  }
  
  else{
    Serial.println("Conexión fallida");
  }
  delay(10000);
}
