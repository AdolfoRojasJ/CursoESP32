//ESP32 - WiFi- UDP - UART
#include <WiFi.h>
#include "WiFi_Library.h"

WiFiUDP udp;        //Crea instancia UDP

//Variables y Constantes
// Coexión
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"
// UDP
const char* IP_remota = "192.168.50.37";   //Dirección Ip del dispositivo remoto
const uint16_t Puerto_remoto = 60518;        //Pueto del dispositivo remoto

void setup() {
  //Serial
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Envío de datos UART en protocolo UDP");
  Serial.println();
  
  //WiFi
  connection(ssid, pass);      //Modo estación
  // UDP
  udp.begin(Puerto_remoto);        //Inicia UDP

  Serial.println();
  Serial.println("Dirección IP Remota → " + String(IP_remota));
  Serial.println("Puerto Remoto → " + String(Puerto_remoto));
  Serial.println();
}

void loop() {
  if(Serial.available()){
    String msg = Serial.readStringUntil('\n');
    f_envio_udp(msg); //Llama función de transmisión UDP
  }
}

//UDP → Escribe un paquete a dispositivo remoto
void f_envio_udp(String s){
  if(udp.beginPacket(IP_remota, Puerto_remoto)){//Conecta
    Serial.println("Se envía dato...");
    udp.println(s); //Envía
    udp.endPacket();      //Termina
  }
}
