#include "DHT.h"
#define DHTPIN 2

#define DHTTYPE DHT11   // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(9600); 
    Serial.println("DHT11");

    dht.begin();
}

int sensorPin = A0;
int sensorValue = 0;

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);
  
  sensorValue = analogRead(sensorPin);
  Serial.print("Moisture = " );
  Serial.println(sensorValue);
  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) 
  {
     Serial.println("Failed to read from DHT");
  } 
  else 
  {
       Serial.print("Humidity: "); 
       Serial.print(h);
       Serial.print(" %\t");
       Serial.print("Temperature: "); 
       Serial.print(t);
       Serial.println(" *C");
    }
}
