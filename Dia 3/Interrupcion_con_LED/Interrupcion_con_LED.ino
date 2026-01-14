// Interrupcion con LED
#define t_rebote 150
int led = 16;
int boton = 2;
unsigned int t_bak=0;
bool boton_sta = 0;
int cta = 0;

//FILTRO
bool f_Filtro(){
  if(millis()-t_bak >= t_rebote)
  {
    t_bak = millis();
    return 1;
  }
  return 0;
}

//INTERRUPT SERVICE
void IRAM_ATTR f_Cuenta(){
  if(f_Filtro)
    boton_sta = 1;
}
void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  //GPIO
  pinMode(boton,INPUT);
  pinMode(led,OUTPUT);
  //INTERRUPCION
  attachInterrupt(boton, f_Cuenta, FALLING);
  // attachInterrupt(boton, f_Cuenta, RISING);
  //  attachInterrupt(boton, f_Cuenta, CHANGE);
  //UART MONITOR
  Serial.println();
  Serial.println("Cuenta las veces que el botón es presionado con interrupcion");
  Serial.println();
}

void loop() {
  digitalWrite(led,0);
  delay(500);
  digitalWrite(led,1);
  delay(500);
  if(boton_sta){
    cta++;
    Serial.println("Presionado:" + String(cta));
    boton_sta=0;
  }

}
