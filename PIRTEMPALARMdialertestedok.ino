#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial mySerial(7, 8); //SIM900 Tx & Rx is connected to Arduino #7 & #8
#define sensorPin  A0
int sim900=9;
int pirOutput=10;
int pushbutton=2;
int led=13;
int relay=5;
void setup()
{  
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(sim900,OUTPUT);
  pinMode(pirOutput,INPUT);
  pinMode(pushbutton,INPUT);
  pinMode(led,OUTPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(sim900,HIGH);
  delay(1000);
  digitalWrite(sim900,LOW);
  delay(5000);
  digitalWrite(pirOutput,LOW);
  digitalWrite(led,LOW);
  digitalWrite(relay,LOW);
 
}

void loop()
{
  int reading = analogRead(sensorPin);  
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  if(digitalRead(pirOutput)==HIGH||digitalRead(pushbutton)==HIGH||(temperatureF >= 75))
  { 
    digitalWrite(led,HIGH);
    digitalWrite(relay,HIGH);
    Serial.println("PUSHBUTTON PRESSED");
    Serial.println("OR");
    Serial.println("TEMP HIGH");
    Serial.println("OR");
    Serial.println("MOTION DETECTED");
    delay(10000);
    Serial.println("DIALING TO MOBILE NUMBER"); 
    mySerial.println("ATD++971557407961;");
    delay(50000);
    }
    else
    {
    digitalWrite(led,LOW);
    digitalWrite(relay,LOW);
    Serial.println("ATH");
    delay(1000);
    }
}
