// DAC 2
#define DAC1 25
#define ADC1 33

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Grafica señales analógicas");
  Serial.println();
}

void loop() {
  int var=0;
  for(int i=0;i<360;i++){
    f_harmo(i); //FUNCION ARMÓNICA
    var = analogRead(ADC1);
    f_trigo(i); //FUNCION TRIGONOMETRICA
    //Serial.println("0," +String(analogRead(ADC1))+",4095");
    Serial.println(String(var)+","+String(analogRead(ADC1)));
    delay(8);
  }
}

void f_trigo(int deg){
  dacWrite(DAC1,int(128+80*(sin(deg*DEG_TO_RAD))));
}

void f_harmo(int deg){
  dacWrite(DAC1,int(128+80*(sin(deg*DEG_TO_RAD)+
  (sin(3*deg*DEG_TO_RAD)/3)+
  (sin(5*deg*DEG_TO_RAD)/5)+
  (sin(7*deg*DEG_TO_RAD)/7)+
  (sin(9*deg*DEG_TO_RAD)/9)+
  (sin(11*deg*DEG_TO_RAD)/11)
  )));
}