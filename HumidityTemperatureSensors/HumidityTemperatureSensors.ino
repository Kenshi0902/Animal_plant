// humidity/temperature sensors
// To connect D2

//When MCU sends a trigger signal, sensor will change from low power consumption mode to active mode. 
//After the trigger signal sensor will send a response signal back to MCU, then 40 bit collected data is sent out and a new signal collecting is trigged.
//(Note that the 40 bit collected data which is sent from sensor to MCU is already collected before the trigger signal comes.) 
//One trigger signal receives one time 40 bit response data from sensor. Single-bus data is used for communication between MCU and sensor.
//It costs 5ms for single time communication.The high-order bit of data sends out first. 
//Signal Data is 40 bit, comprised of 16 bit humidity data, 16 bit temperature data and 8 bit checksum.
//The data format is:
//8bits integer part of humidity+8bits decimal part of humidity+8bits integer part of temperature+8bits decimal part of temperature+8bits checksum.

#include "DHT.h"
#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(9600); 
    Serial.println("DHT11");

    dht.begin();
}

void loop() 
{
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // check if returns are valid, if they are NaN (not a number) then something went wrong!
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
