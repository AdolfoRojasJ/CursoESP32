//ESP32 - PWM - UART(Serial)
//Controlar la intencidad del led de la tarjeta 

//Variables y constantes 
#define led 2   //Dirección del led
#define fre 1000   //Frecuencia PWM
#define res 16   //Resoliución PEM
#define Max (pow(2,res)-1)  //El valor maximo de ancho de pulso 

void setup() {
  //Serial
  Serial.begin(115200);
  delay(200);
  //GPIO
  pinMode(led,OUTPUT);  //Cuando es PWM es opcional asignarlo como salida
  //PWM
  ledcAttach(led,fre,res); //La salida es led, la frecuencia es 1KHz y la resolución de 16 bits

  Serial.println();
  Serial.println("Control de un led por PWM por serial");
  Serial.println();
}

void loop() {
  if(Serial.available()){
    String s=Serial.readStringUntil('\n');
    int pwm=s.toInt();  //Convierte cadena en entero
    if(pwm<0)  pwm=0;
    if(pwm>100) pwm=100;
    ledcWrite(led,map(pwm,0,100,0,Max));  //Ancho de pulso con respecto al valor del map
                                          //map devuelve un entero que se encuentre entre un rango de valores
    Serial.println("Ciclo del trabajo del " + String(pwm) + "%");
  }
}
