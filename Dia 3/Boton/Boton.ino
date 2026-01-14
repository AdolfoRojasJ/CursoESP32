//BOTON
#define boton 2  //Dirección de entrada 
int cta = 0; //Contador

void setup() {
  // UART
  Serial.begin(115200);
  delay(200);

//GPIO
  pinMode(boton, INPUT); //Pin como entrada

  Serial.println();
  Serial.println("Cuenta las veces que el botón es presionado");
  Serial.println();

}

void loop() {
  if(!digitalRead(boton)){ 
  cta++; 
  Serial.println("El boton se ha presionado" + String(cta) + "veces" ); 
  while (!digitalRead(boton))
  {
    delay(20);
  }
  }
}