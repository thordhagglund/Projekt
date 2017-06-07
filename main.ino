/*
* v1.0: Donerat från Automatiserar.se
*/

#include <Arduino.h>

/*
* Bibliotek för att mäta temperatur med sensorerna (<modellnummer>).
*/
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4       // Anger pinnen där du ska köra temp sensorn. 
/*
* Slut
*/



/*
* Bibliotek för att ansluta till nätverket och posta till REST-tjänst
*/
#include <Bridge>
#include <HttpClient>
/*
* Slut
*/



/*
* Funktioner och variabler relaterade till att posta datat
*/
//TODO

void http_setup(){
//Måste justeras
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  Serial.begin(9600);
  while(!Serial);
}

/*
* Slut
*/



/*
* Funktioner och variabler relaterade till temperaturmätning
*/
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
char temperatureString[6];

 void ReadDS18B20Temperature() {
 // Serial.print("Requesting DS18B20 temperature...");
  float temp;
  float temp1;

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
   
    delay(100); //ms
  }
  
/*
* Slut temperaturmätning
*/



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
