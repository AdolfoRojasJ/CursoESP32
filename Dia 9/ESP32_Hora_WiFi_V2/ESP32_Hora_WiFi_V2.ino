//ESP32 - WiFi V2
//Solicitar un servicio de internet.
//Solicitar las hora a un servidor NTP.
//Print using timeinfo

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
  connection();

  //NTP
  configTime(GTM_SEGUNDOS, H_VERANO_SEGUNDOS, NTP);
}

void loop() {
  int cuenta = 0;

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
    cuenta = 0;
    while(cuenta<5){
      struct tm timeinfo;

      if(getLocalTime(&timeinfo)){
        int year = timeinfo.tm_year + 1900;
        int month = timeinfo.tm_mon+1;
        int day = timeinfo.tm_mday;
        int hour = timeinfo.tm_hour;
        int min =  timeinfo.tm_min;
        int sec = timeinfo.tm_sec;

        Serial.printf("Fecha: %d/%d/%d\t Hora: %d:%d:%d \n", day,month,year,hour,min,sec);
      }

      else{
        Serial.println("No se pudo obtener la fecha y hora");
      }
      cuenta++;
      delay(1000);
    }
  }
