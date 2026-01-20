// WiFi Net Detection
#include<WiFi.h>

String enc[6]{
    "Abierta",
    "WEP",
    "WPA",
    "WPA2",
    "WPA_WPA2",
    "WPA_ENTERPRISE"
};

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Deteccion de Redes WiFi");
  Serial.println();
}

void loop() {
  String message="";
  Serial.println("Buscando...");
  int n = WiFi.scanNetworks(); //Cantidad de redes localizadas
  Serial.println("Fin de la busqueda");
  if (n==0)
  {
    Serial.println("No hay redes disponibles");
  }
  else
  {
    Serial.println("Se encontraron "+String(n)+" redes");
    for(int i=0;i<n;i++){
      Serial.println(
        String(i+1)+ "."+ WiFi.SSID(i) +  "\t" + WiFi.RSSI(i) + "DBm \t" + enc[WiFi.encryptionType(i)]
      );
    }
    delay(10000);
  }
}
