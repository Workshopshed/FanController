/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include "DallasTemperature.h"
/********************************************************************/
// Data wire is plugged into pin 9 on the Arduino 
#define ONE_WIRE_BUS 9 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

float tempC;
int motor;
int motorPin = 11;

void setup(void) 
{ 
    pinMode(motorPin, OUTPUT);  // sets the pin as output
    // Start up the library 
    sensors.begin(); 
} 
void loop(void) 
{ 
    // call sensors.requestTemperatures() to issue a global temperature 
    // request to all devices on the bus 
    /********************************************************************/
    sensors.requestTemperatures(); // Send the command to get temperature readings 
    tempC = sensors.getTempCByIndex(0);
    // Why "byIndex"?  
    // You can have more than one DS18B20 on the same bus.  
    // 0 refers to the first IC on the wire 

    motor = map(long(tempC),25,60,0,255);
    motor = constrain(motor,0,255);
 
    analogWrite(motorPin, motor); 

    delay(1000); 
} 