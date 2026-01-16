//ESP32 - PWM - UART(Serial)
//Controlar la intencidad del led de la tarjeta 

//Variables y constantes 
//Color rojo (R)
#define R_led 25   //Dirección del led
#define R_fre 1000   //Frecuencia PWM
#define R_res 16   //Resoliución PEM
#define R_Max (pow(2,R_res)-1)  //El valor maximo de ancho de pulso 
//Color verde (G)
#define G_led 15   //Dirección del led
#define G_fre 1000   //Frecuencia PWM
#define G_res 16   //Resoliución PEM
#define G_Max (pow(2,G_res)-1)  //El valor maximo de ancho de pulso 
//Color azul (B)
#define B_led 4   //Dirección del led
#define B_fre 1000   //Frecuencia PWM
#define B_res 16   //Resoliución PEM
#define B_Max (pow(2,B_res)-1)  //El valor maximo de ancho de pulso 

unsigned int R_ap=0; //Ancho de pulso 
unsigned int G_ap=0; //Ancho de pulso 
unsigned int B_ap=0; //Ancho de pulso 

void setup() {
  //Serial
  Serial.begin(115200);
  delay(200);
  //GPIO
  pinMode(R_led,OUTPUT);  //Cuando es PWM es opcional asignarlo como salida
  pinMode(G_led,OUTPUT);  //Cuando es PWM es opcional asignarlo como salida
  pinMode(B_led,OUTPUT);  //Cuando es PWM es opcional asignarlo como salida
  //PWM
  ledcAttach(R_led,R_fre,R_res); //La salida es led, la frecuencia es 1KHz y la resolución de 16 bits
  ledcAttach(G_led,G_fre,G_res); //La salida es led, la frecuencia es 1KHz y la resolución de 16 bits
  ledcAttach(B_led,B_fre,B_res); //La salida es led, la frecuencia es 1KHz y la resolución de 16 bits

  Serial.println();
  Serial.println("Control de un led RGB por serial y Bluetooth");
  Serial.println();
}

void loop() {
  if(Serial.available()){
    String s=Serial.readStringUntil('\n');
    Serial.println("Recibido -> " + s);

    int posPts =s.indexOf(':'); //Posición de los :
    int posFin = s.length();  //Largo de la cadena 
    String c = s.substring(0,posPts);
    c.toUpperCase();
    int pwm = s.substring(posPts+1,posFin).toInt();
    if(pwm<0)  pwm=0;
    if(pwm>100) pwm=100;

    if(c.equals("R"))  R_ap=map(pwm,0,100,0,R_Max);
    else if(c.equals("G"))  G_ap=map(pwm,0,100,0,G_Max);
    else if(c.equals("B"))  B_ap=map(pwm,0,100,0,B_Max);

    s = "Colores -> R: " +  String(R_ap) +
                   "   G: " +  String(G_ap) +
                   "   B: " +  String(B_ap);
    Serial.println(s);
  }
  ledcWrite(R_led,R_ap);
  ledcWrite(G_led,G_ap);
  ledcWrite(B_led,B_ap);
}
