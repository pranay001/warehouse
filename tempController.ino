
#include<dht.h>
dht DHT;

// if you require to change the pin number, Edit the pin with your arduino pin.

#define DHT11_PIN 3

void setup() {
  pinMode(9,OUTPUT);

Serial.begin(9600);

Serial.println("welcome to TechPonder Humidity and temperature Detector"); }

void loop() { // READ DATA

int chk = DHT.read11(DHT11_PIN);

Serial.println(" Humidity " );

Serial.println(DHT.humidity, 1);

Serial.println(" Temparature ");

Serial.println(DHT.temperature, 1);

if(DHT.temperature<36)
{
  digitalWrite(9,HIGH);
  Serial.println("TEMPERATURE CONTROL MODE IS ACTIVE.....................");
  Serial.println();
  Serial.println();
  Serial.println();
}
else
{
  digitalWrite(9,LOW);
}

delay(2000);

}
