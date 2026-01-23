//UDP LEDS
//USING TERMUX ANDROID APP
//FIRST INSTALL: pkg install netcat-openbsd
//SENDING MESSAGE: echo "MESSAGE" | nc -u [localIP] Port
//"MESSAGE" is the message you want to send.
//localIP is your IP Address 192.168.x.x
//Port the value of the variable "Puerto_local"

#include <WiFi.h>
#include <WiFi_Library.h>

//Crear instancias
WiFiUDP udp;        //Crea UDP

//Variables y Constantes
// Coexión
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"
// UDP
const uint16_t Puerto_local = 123;   //0 - 65535
const uint16_t tam = 100;           //Es el número máximo de bytes que puedo recibir
char dato_udp[tam];                //Arreglo de caracteres
// GPIO 
int leds[] = {15, 2, 4, 16}; //Direcciones de led

void setup() {
  //Serial
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Recepcion de Protocolo UDP");
  Serial.println();
  
  //GPIO
  for(int i=0; i<4; i++)
    pinMode(leds[i], OUTPUT);
  //WiFi
  connection(ssid, pass); //Estación
  udp.begin(Puerto_local);        //Inicia UDP

  Serial.println("Puerto Local → " + String(Puerto_local));
  Serial.println();
}

void loop() {
  //int paq = udp.parsePacket();//Analiza paquete entrante
  if(udp.parsePacket()){//Espera por paquete
    f_clear(dato_udp);        //Llama función de limpieza de cadena
    udp.read(dato_udp, tam);  //Guarda la información en dato_udp
    String dato = dato_udp;   //Convertimos arrego en String
    dato.toUpperCase();       //Convierte a mayúsculas
    
    for(int i=0;i<4;i++)
      digitalWrite(leds[i],0);//Apaga todos los leds

    if(dato.indexOf("UNO") != -1) digitalWrite(leds[0],1);//Enciende led
    if(dato.indexOf("DOS") != -1) digitalWrite(leds[1],1);//Enciende led
    if(dato.indexOf("TRES") != -1) digitalWrite(leds[2],1);//Enciende led
    if(dato.indexOf("CUATRO") != -1) digitalWrite(leds[3],1);//Enciende led
    Serial.println("UDP - Dato recibido → " + dato);
    
    udp.flush();//Elimina los datos en el buffer
  }
}

//Limpia arreglo de caracteres
void f_clear(char *msg){
  for(int i=0; i<tam; i++)
    msg[i] = '\0';  //Limpia cada caracter en el arreglo
}