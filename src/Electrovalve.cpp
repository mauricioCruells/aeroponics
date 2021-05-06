#include "Electrovalve.h"
#include "Arduino.h"


    Electrovalve::Electrovalve(int pin, long on, long off){
        ValvePin = pin;
        pinMode(ValvePin, OUTPUT);

        OnTime = on;
        OffTime = off;

        ValveState = false; // true == encendido, false == apagado
        previousMillis = 0;
    }

    void Electrovalve::Update(){
        unsigned long currentMillis = millis();

        if ((ValveState == true) && (currentMillis - previousMillis >= OnTime)){
            previousMillis = currentMillis;  
            ValveState = false;
            digitalWrite(ValvePin, HIGH); // relay desactiva cuando el pin esta en HIGH  
        }

        else if ((ValveState == false) && (currentMillis - previousMillis >= OffTime)){ 
            previousMillis = currentMillis;  
            ValveState = true;
            digitalWrite(ValvePin, LOW); // relay activa cuando pin esta en LOW   
        }
    }

    void Electrovalve::setState(bool state){
        if(state == true){
            digitalWrite(ValvePin, LOW);
        }
        else if(state == false){
            digitalWrite(ValvePin, HIGH);
        }
    }
