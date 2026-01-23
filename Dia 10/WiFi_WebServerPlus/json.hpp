//Instancias 
JSONVar JDoc;                             //Variable de almacenamiento Json
//Crea cadena Json
String crearJson(){
  //SI7021_lee();
  int tmp = analogRead(pot);
  float temp = analogRead(ldr);//tmp*200/4095. - 50; 
  JDoc["Pot"] = String(map(analogRead(pot),0,adc_max,0,100));
  JDoc["LDR"] = String(map(analogRead(ldr),0,adc_max,0,100));
  JDoc["CT"] = String(ct);
  if(led_sta) JDoc["led_sta"] = "ON";
  else JDoc["led_sta"] = "OFF";
  String jsonString = JSON.stringify(JDoc);
  Serial.println("→ " + jsonString);
  return jsonString;
}
