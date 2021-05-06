#include <Arduino.h>
#include "Button.h"

bool runFlag = false;
bool autoFlag = false;
bool manualFlag = false;

int autoManPosA = 9;
int autoManPosB = 10;

//Button init, pin number, contactor logic, interrupt to attach
Button green(2, "NO", 0); 
Button red(3, "NC", 1);


void setup() {
    //debugging
    //Serial.begin(9600);
    //end debugging
    
    attachInterrupt(green.getInterrupt(), updateGreenFlag, green.getLogic()); 
    attachInterrupt(red.getInterrupt(), updateRedFlag, red.getLogic());
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(autoManPosA, INPUT_PULLUP);
    pinMode(autoManPosB, INPUT_PULLUP);
}

void loop() {

    //debugging
    //Serial.println(String(runFlag) + " " + String(green.getState()) + " " + String(red.getState()));
    //end debugging
    manStateUpdate(); // rutina para ver en que posicion esta la maneta de automatico y manual

    if(manualFlag){
        if(runFlag){
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else if (!runFlag){
            digitalWrite(LED_BUILTIN, LOW);
        }
    }

}


void manStateUpdate(){
    if((digitalRead(autoManPosA) == false) & (digitalRead(autoManPosB) == true)){
        autoFlag = true;
        manualFlag = false;
    }
    else if((digitalRead(autoManPosB) == false) & (digitalRead(autoManPosA) == true)){
        autoFlag = false;
        manualFlag = true;
    }
    else{
        autoFlag = false;
        manualFlag = false;
    }
}

//ISRs for button operation

void updateGreenFlag(){
    green.setState();
    red.resetState();
    runFlag = green.getState();
}

void updateRedFlag(){
    green.resetState();
    red.setState();
    runFlag = green.getState();
}

