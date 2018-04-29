const int analogPin = A0;    // Flame Sensor (A0) to Arduino analog input pin A0
const int BuzzerPin = 13;       // Buzzer output pin
const int threshold = 400;   // Flame level threshold (You can vary the value depends on your need)

void setup() 
{
  
  pinMode(BuzzerPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() 
{
  // read the value of the Flame Sensor:
  int analogValue = analogRead(analogPin);
   Serial.println(analogValue); //serial print the FLAME sensor value
  
  if (analogValue > threshold) 
  {
    digitalWrite(BuzzerPin, HIGH);
    Serial.print("High FLAME");
    SendSMS();
    delay(1000);
  } 
  
  else 
  {
    digitalWrite(BuzzerPin, LOW);
    Serial.print("No flame");
  }

  delay(1);       
}
void SendSMS()
{
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919444853575\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println("FIRE ALERT!!!!");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);
  Serial.println("AT+CMGF=2");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919884806511\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println("FIRE ALERT!!!!");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);
  Serial.println("AT+CMGF=3");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919042994107\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println("FIRE ALERT!!!!");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);
  Serial.println("AT+CMGF=4");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+918124052660\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println("FIRE ALERT!!!!");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);
}
