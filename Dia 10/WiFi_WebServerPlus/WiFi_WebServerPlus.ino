//ESP32 - WiFi - WEB SERVER MEZCLADITO
//Lectura de dos datos analógicos y los publica en página WEB
//Control de PWM y de un led desde página WEB
//Lectura de estatus de led desde página WEB
//Uso de servidorasíncrono, DNS, JSON, SPIFFS

#include <WiFi.h>                            //Biblioteca WiFi
#include <ESPAsyncWebServer.h>  //WebServer asíncrono
#include <Arduino_JSON.h>           //Manejo de datos JSON
#include <SPIFFS.h>                        //Sistema de archivos
#include <WiFi_Library.h>
#include "spiffs_uli.hpp"                        //Sistema de archivos
#include "variables.h"          //Manejo de variables y constantes
#include "json.hpp"
#include "server.hpp"

void setup(){
     //UART
  Serial.begin(115200);
  //GPIO
  pinMode(led,OUTPUT);
  //PWM
  ledcAttach(pwm_pin,pwm_fre,pwm_res);
  ledcWrite(pwm_pin, map(0,0,100,0,pwm_max));
  //WIFI
  connection(ssid,pass);
  //Serial.println();
  delay(1000);
  //SPIFFS
  spiffs_init();
  //Server
  server_init();
  delay(100);
}

void loop() {
  //Envía evento al Servidor Web con la lectura de los sensores
  if ((millis() - t_anterior) > t_sensado) {//Tiempo entre envío de datos
    events.send(crearJson().c_str(),"perro_salchicha",millis());
    t_anterior = millis();  }  
  digitalWrite(led,led_sta);
}
