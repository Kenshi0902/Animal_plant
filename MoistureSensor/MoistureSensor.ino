//Moisture Sensor
//To connect A0

//This Moisture Senor can be used for detecting the moisture of soil or judge if there is water around the sensor, let the plant in your garden able to reach out for human's help when they are thirsty. 
//This sensor is very easy to use, you can just simply insert in into the soil and read the data. 
//With this sensor, you can make a small project that can let the plant send a message to you like " I am thirsty now, please feed me some water."

int sensorPin = A0;
int sensorValue = 0;

void setup() {
    Serial.begin(9600);
}
void loop() {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    Serial.print("Moisture = " );
    Serial.println(sensorValue);
    delay(1000);
}
