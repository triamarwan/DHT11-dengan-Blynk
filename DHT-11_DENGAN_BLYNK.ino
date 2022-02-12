#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // Memasukan library sensor DHT

char auth[] = "fnM6JBXdtKa5ufm8Ncl-abadoRLYEIRJ";
char ssid[] = "A83";
char pass[] = "gocengdulu";
 
#define DHTTYPE DHT11      // Sensor yang akan diakses yaitu DHT11
#define DHTPIN D1
DHT dht(DHTPIN, DHTTYPE);
WidgetLCD lcd(V0);

void setup(){
 Serial.begin(9600);
 dht.begin();
 Blynk.begin(auth, ssid, pass);
 lcd.clear();
}

void loop (){
Blynk.run();
int kelembaban = dht.readHumidity();
int suhu = dht.readTemperature();
 Blynk.virtualWrite(V0, suhu);
 Blynk.virtualWrite(V1, suhu);
lcd.print(0,0,"suhu :");
lcd.print(8,0,"°C");
lcd.print(6,0,suhu);
Blynk.virtualWrite(V0, kelembaban);
Blynk.virtualWrite(V2, kelembaban);
lcd.print(0,1,"Kelembaban :");
lcd.print(15,1,"%");
lcd.print(12,1,kelembaban);
if (suhu > 35) {
  Blynk.notify("BERBAHAYA !!!!");
}
 delay(50);
}
