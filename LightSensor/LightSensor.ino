// Light sensor
// To connect A0

//Light sensor integrates a photo-resistor(light dependent resistor) to detect the intensity of light. 
//The resistance of photo-resistor decreases when the intensity of light increases. 
//A dual OpAmp chip LM358 on board produces voltage corresponding to intensity of light(i.e. based on resistance value). 
//The output signal is analog value, the brighter the light is, the larger the value.
//This module can be used to build a light controlled switch i.e. switch off lights during day time and switch on lights during night time.

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
