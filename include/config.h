#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

struct PlantProfile{
    const char* name;                   //plant name
    uint8_t ID;                         //pump station number
    int MoistureMin;                    //how dry the soil can be at max
    int MoistureMax;                    //prevents moisture being too wet
    unsigned long WaterPulseDuration;   // how much water per watering
    unsigned long WaterPulseFreq;       //how often to water plant
    float IdealTemp;                    //ideal temperature of plant 
    float IdealLight;                   //ideal lighting of plant how much light per day
};


// Preset Plant Profiles

const PlantProfile ALOE_VERA = {
    .name = "Aloe Vera",
    .ID= 1,
    .MoistureMin=20, //temporary varible 
    .MoistureMax=100,//temp
    .WaterPulseDuration= 5000,//5s temp
    .WaterPulseFreq=36000000,//10 hour temp
    .IdealTemp= 25,//C temp
    .IdealLight=80 //temp 
};

#endif

