/*
* v1.0: Donerat från Automatiserar.se
*/

#include <Arduino.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4       // Anger pinnen där du ska köra temp sensorn. 


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
char temperatureString[6];


 void ReadDS18B20Temperature() {
 // Serial.print("Requesting DS18B20 temperature...");
  float temp;
  float temp1;
  
   /* 
    
    temp = DS18B20.getTempCByIndex(0);
    Serial.print("sensor 1: ");
   Serial.println(temp);

    temp1 = DS18B20.getTempCByIndex(1);
        Serial.print("sensor 2: ");
   Serial.println(temp1);

   */

  for (int i = 0; i < 2; i++){
    do {
      DS18B20.requestTemperatures(); 
      temp = DS18B20.getTempCByIndex(i);
      // TODO lägg till säkerhetskoll så att vi inte fastnar här i all evighet
    } while (temp == 85.0 || temp == (-127.0));
    
    Serial.print("sensor ");
    Serial.print( (i + 1) );
    Serial.print(": ");
    Serial.println(temp);  
  }
   
    delay(100);
  
//  return temp;
  }
  
void setup() {
  // put your setup code here, to run once:
DS18B20.begin(); // aktiverar sensorn. 
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

 
 ReadDS18B20Temperature(); // V1.3 -- läser temperatur från DS18B20

 //Serial.println(myTemp);
 delay(1000);

}
