#include "config.h"
#include <Arduino.h>

static unsigned long SensorTimer=0;   //check all sensors and updates algorythm every 15-20 min ish 
static unsigned long WateringTimer=0; // for running pumps at calculated frequency (also check water levl during this operation time)

unsigned long WateringFreq=3600000;//for now static set but late this val will be set by optimisation algorythm 

void setup(){
  Serial.begin(115200);
  SensorTimer=millis();
  WateringTimer=millis();

}

void loop(){
  // read the raw ADC value (returns 0 to 4095)
    int rawValue = analogRead(SOIL_PIN_1);

    // 2. Print the result
    Serial.print("Raw ADC Value on GPIO 34: ");
    Serial.println(rawValue);

    delay(1000);


  if(millis()-SensorTimer>900000){ //check sensors every 15 min 
    
    SensorTimer=millis();
  }

  if(millis()-WateringTimer>WateringFreq){

    WateringTimer=millis();
  }
}