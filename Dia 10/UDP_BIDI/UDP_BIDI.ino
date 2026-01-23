//Comunicaión bidiriccional UDP

#include <WiFi.h>
#include <WiFi_Library.h>

WiFiUDP udp;        //Crea instancia UDP

//Variables y Constantes
// Coexión
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"
// UDP
const uint16_t Puerto_local = 123;   //0 - 65535
const uint16_t tam = 100;           //Es el número máximo de bytes que puedo recibir
char dato_udp[tam];                //Arreglo de caracteres
const char* IP_remota = "192.168.50.15";   //Dirección Ip del dispositivo remoto
const uint16_t Puerto_remoto = 60518;        //Pueto del dispositivo remoto
// GPIO 
int leds[] = {15, 2, 4, 16}; //Direcciones de led

void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Comunicación bidireccional en protocolo UDP");
  Serial.println();
  
  //GPIO
  for(int i=0; i<4; i++)
    pinMode(leds[i], OUTPUT);
  //WiFi
  connection(ssid, pass);       //Modo estación
  udp.begin(Puerto_local);        //Inicia UDP

  Serial.println("Puerto Local → " + String(Puerto_local));
  Serial.println("Dirección IP Remota → " + String(IP_remota));
  Serial.println("Puerto Remoto → " + String(Puerto_remoto));
  Serial.println();
}

void loop() {
  if(udp.parsePacket()){//Espera por paquete
    f_clear(dato_udp);        //Llama función de limpieza de cadena
    udp.read(dato_udp, tam);  //Guarda la información en dato_udp
    String dato = dato_udp;   //Convertimos arrego en String
    dato.toUpperCase();       //Convierte a mayúsculas
    
    f_envio_udp();            //Eco de recepción
    
    udp.flush();//Elimina los datos en el buffer
  }
}

//UDP → Escribe un paquete a dispositivo remoto
void f_envio_udp(){
  if(udp.beginPacket(IP_remota, Puerto_remoto)){//Conecta
    Serial.println("Se envía dato...");
    udp.println("Mensaje recibido!"); //Envía
    udp.endPacket();      //Termina
  }
}

//Limpia arreglo de caracteres
void f_clear(char *msg){
  for(int i=0; i<tam; i++)
    msg[i] = '\0';  //Limpia cada caracter en el arreglo
}
