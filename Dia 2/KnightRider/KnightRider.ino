// KNIGHT RIDER
int leds[3] = {25,0,2};
int secuencia[5][3]{
  {1,0,0},
  {0,1,0},
  {0,0,1},
  {0,1,0},
  {1,0,0}
};

void setup() {
  for(int i=0;i<4;i++)
    pinMode(leds[i],OUTPUT);
}

void loop() {
  for (int ren=0;ren<5;ren++){
    for (int col=0;col<3;col++)
      digitalWrite(leds[col],secuencia[ren][col]);    
  delay(1200);
  }
}
