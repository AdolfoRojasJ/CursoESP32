//ESP32 - PWM
//Controlar la intensidad del led de la tarjeta 

//Variables y constantes 
#define led 2   //Dirección del led
#define fre 1000   //Frecuencia PWM
#define res 16   //Resolución PEM
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
  Serial.println("Control de un led or PWM");
  Serial.println();
} 

void loop() {
  for(int i=0; i<=Max; i+=500){
    ledcWrite(led,i);  //Cambia el valor del ancho de pulso
    delay(10);
  }
  for(int i=0; i<=Max; i+=500){
    ledcWrite(led,Max-i);  //Cambia el valor del ancho de pulso :D
    delay(10);
  }
}
