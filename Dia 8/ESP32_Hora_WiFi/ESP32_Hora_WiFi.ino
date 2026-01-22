//ESP32 - WiFi
//Solicitar un servicio de internet.
//Solicitar las hora a un servidor NTP.

#include <WiFi_Library.h>
#include <time.h> //Manejo de tiempo epoch.

//Variables y constantes
//#define SSID ""
//#define PASS ""
#define GTM -6 //Uso horario de la Ciudad de México.
#define GTM_SEGUNDOS GTM*3600 //GTM en segundos.
#define H_VERANO 0 //Variable para horario de verano. 1: Verano / 0:Invierno
#define H_VERANO_SEGUNDOS H_VERANO*3600 //Horario de verano en segundos (sí funciona).
#define NTP "pool.ntp.org" //Dirección del servicio NTP.
//char ntp[] = "pool.ntp.org";

void setup() {
  //Comunicación serial.
  Serial.begin(115200);
  delay(200);

  //WiFi.
  IniciarSTA();

  //NTP
  configTime(GTM_SEGUNDOS, H_VERANO_SEGUNDOS, NTP);
}

void loop() {
  int cuenta = 0;
  int anos = 0;
  int meses = 0;
  int dias = 0;
  int horas = 0;
  int segundos = 0;

  while(cuenta<5){
    //Lee dato epoch.
    time_t ahora; //Variable de tipo tiempo.
    time(&ahora);
    Serial.print("La hora actual es: ");
    Serial.println(ahora);
    cuenta++;
    delay(1000);
  }
  cuenta = 0;
  while(cuenta < 60){
    struct tm tiempoInfo; //tm -> Año, mes, día, hora, minuto, segundo.
    if(getLocalTime(&tiempoInfo)){
      Serial.println(&tiempoInfo, "%d / %m / %Y\n%H:%M:%S");
      cuenta++;
      delay(1000);
    }
  }
}
