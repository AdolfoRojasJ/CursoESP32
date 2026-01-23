AsyncWebServer server(80);                //Instanica Server
AsyncEventSource events("/events");  //Crea repositorio de Eventos

//Manejo de WebServer Asíncrono (Handle Web Server)
void server_init(){
     //Home
     server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
          request->send(SPIFFS, "/index.html", "text/html");});
  
     //Dirección SPIFFS
     server.serveStatic("/", SPIFFS, "/");

     //Presionar un botón
     server.on("/nuevo", HTTP_GET, [](AsyncWebServerRequest *request){
          request->send(200, "text/plain", "OK");
          events.send(crearJson().c_str(),"perro_salchicha",millis());
     });
     
     //Presionar un botón
     server.on("/bot1", HTTP_GET, [](AsyncWebServerRequest *request){
          led_sta = !led_sta; request->send(200, "text/plain", "OK");
          Serial.println("← Botón presionado, nuevo estado = " + 
                    String(led_sta));
     });
     
     //Control slider → Controla PWM
     server.on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request){
          pwm_ct = request->getParam(PARAM_INPUT)->value();
          ct = pwm_ct.toInt(); 
       ledcWrite(pwm_pin,map(ct,0,100,0,pwm_max));
          request->send(200, "text/plain", "OK"); 
          events.send(crearJson().c_str(),"perro_salchicha",millis());
    Serial.println("← Slider de PWM, nuevo valor = "+pwm_ct +"%" );
     });
     
     // → Al conectarse un cliente
     events.onConnect([](AsyncEventSourceClient *client){
     if(client->lastId()){
          Serial.println("Cliente reconectado!");
          Serial.printf("El último ID de mensaje que se recibió: %u\n", 
                    client->lastId());
          delay(250);
     }client->send("Hola!", NULL, millis(), 10000);
     });
     
     server.addHandler(&events); //Carga manejo de eventos
     server.begin();             //Inicia el servidor
}
