#include <WiFi.h>
#include <WiFi_Library.h>

WiFiServer server(714);

#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"

void setup() {
  Serial.begin(115200);
  delay(200);
  connection(ssid,pass);
  server.begin();
  Serial.println();
  Serial.println("Servidor TCP");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {
  WiFiClient client = server.available();
  if(client){
    Serial.println("Cliente Conectado");
    while(client.connected()){
      if(client.available()){
        String linea = client.readStringUntil('\r');
        Serial.println("Cliente: " +linea);
        client.println("Servidor: Mensaje recibido");
        break;
      }
    }
    client.stop();
    Serial.println("Cliente desconectado");
  }
  else
  {
    Serial.println("No hay cliente disponible");
  }

}
