#include "config.h"
#include <Arduino.h>

static unsigned long SensorTimer=0;   //check all sensors and updates algorythm every 15-20 min ish 
static unsigned long WateringTimer=0; // for running pumps at calculated frequency (also check water levl during this operation time)

uint16_t Moisture1=0;
uint16_t Moisture2=0;
uint16_t Moisture3=0;
uint16_t Moisture4=0;
bool WaterLevel=1;//0 low, 1 high 

unsigned long WateringFreq=3600000;//for now static set but late this val will be set by optimisation algorythm 

void setup(){
  Serial.begin(115200);
  SensorTimer=millis();
  WateringTimer=millis();
  pinMode(WLevel_PIN, INPUT_PULLUP);

}

void loop(){

  if(millis()-SensorTimer>9000){ //check sensors every 15 min 
    // read the raw ADC value (returns 0 to 4095) - high value= dry, low value = wet 
    Moisture1 = analogRead(SOIL_PIN_1);
    Moisture2 = analogRead(SOIL_PIN_2);
    Moisture3 = analogRead(SOIL_PIN_3);
    Moisture4 = analogRead(SOIL_PIN_4);
    
    /* just to print values in terminal if needed 
    Serial.println(Moisture1);
    Serial.println(Moisture2);
    Serial.println(Moisture3);
    Serial.println(Moisture4);
    */

    //check water level with mechanical sensor
    WaterLevel=digitalRead(WLevel_PIN);
    while (WaterLevel==LOW){ //if theres low water it gets stuck here not being able to continue measuring other stuff
      Serial.println("LOW WATER");
      WaterLevel=digitalRead(WLevel_PIN);
      delay(1000);//rechecks every 1s in this state to get out if water has been refilled 
    }

    SensorTimer=millis();
  }

  if(millis()-WateringTimer>WateringFreq){

    WateringTimer=millis();
  }
}