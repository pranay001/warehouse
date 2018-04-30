/* Earthquake + fire alert code (Arduino)            
 
   D9                 Vibration DOut
   A0                 Fire AOut   
   D12                Fire alert buzzer 
   D13                Indication LED Earthquake
   D0                 Tx GSM
   D1                 Rx GSM
   D3                 DHT11 DOut
   D7                 Relay
*/

#include<dht.h>
dht DHT;
#define DHT11_PIN 3

int ledPin = 13;
int EP =9;
const int analogPin = A0;    // Flame Sensor (A0) to Arduino analog input pin A0
const int BuzzerPin = 12;       // Buzzer output pin
const int threshold = 400;  
const int relay = 7;
String message = "";


void setup()
{
  pinMode(relay,OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(EP, INPUT); //set EP input for measurment
  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}



void loop()
{
  
  long measurement =TP_init();                                //Earthquake algorithm
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 500)
  {
    digitalWrite(ledPin, HIGH);
    message = "Earthquake detected in RMK warehouse......";
    SendSMS();
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin, LOW); 
  }
  
  
  
  
  int analogValue = analogRead(analogPin);                   //Fire accident algorithm    
  Serial.println(analogValue); //serial print the FLAME sensor value
  
  if (analogValue > threshold) 
  {
    digitalWrite(BuzzerPin, HIGH);
    Serial.println("High FLAME");
    message = "Fire alert in RMK warehouse............";  
    SendSMS();
    delay(1000);
  } 
  else 
  {
    digitalWrite(BuzzerPin, LOW);
    Serial.println("No flame");
  }

  int chk = DHT.read11(DHT11_PIN);
  Serial.print(" Temparature =  ");
  Serial.println(DHT.temperature, 1);
  if(DHT.temperature<36)
  {
    digitalWrite(relay,HIGH);
    Serial.println("TEMPERATURE CONTROL MODE IS ACTIVE.....................");
    Serial.println();
    Serial.println();
    Serial.println();
  }
  else
  {
    digitalWrite(relay,LOW);
  }


}


long TP_init()
{
  delay(10);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}


void SendSMS()
{
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919884806511\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println(message);//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);  
  message = "";
}
