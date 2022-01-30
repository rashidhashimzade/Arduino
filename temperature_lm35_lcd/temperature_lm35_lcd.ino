
#include <LiquidCrystal.h>

#define sensorPin A0

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode (4,OUTPUT); //green
  pinMode (3,OUTPUT); //blue
  pinMode (2,OUTPUT); //red
}

void loop() {
  int reading = analogRead(sensorPin);

  float voltage = reading * (5000 / 1024.0);


  float temperature = voltage / 10;


  Serial.print(temperature);
   
  if (temperature < 20)
  {
    digitalWrite (3,HIGH) ;
    digitalWrite (4,LOW) ;    
    digitalWrite (2,LOW) ;
    delay(1000);
  }  
  if ((temperature > 20 && temperature < 27))
  {
    digitalWrite (4,HIGH) ;
    digitalWrite (2,LOW) ;
    digitalWrite (3,LOW) ;
    delay(1000);
  }
  if (temperature > 27)
  {
    digitalWrite (3,LOW) ;
    digitalWrite (4,LOW) ;    
    digitalWrite (2,HIGH) ;
    delay(1000);
  }  
    
  Serial.print(" \xC2\xB0");
  Serial.println("C");

  lcd.setCursor(0, 0);  
  lcd.print(temperature);  
  lcd.print("C");  

  delay(1000); 
