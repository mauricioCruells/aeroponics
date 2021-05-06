#pragma once
#include "Arduino.h"

class Electrovalve
{
    public:
    
    int ValvePin;    
    unsigned long OnTime;     
    unsigned long OffTime;    
    
    int ValveState;                 
    unsigned long previousMillis;   

    
    Electrovalve(int pin, long on, long off);
    void Update();
    void setState(bool state);
};
