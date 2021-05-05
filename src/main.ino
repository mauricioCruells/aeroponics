#include <Arduino.h>
#include "Button.h"

bool runFlag = false;

Button green(2, "NO", 0);
Button red(3, "NC", 1);

void setup() {
    //debugging

    Serial.begin(9600);

    //end debugging
    attachInterrupt(green.getInterrupt(), updateGreenFlag, green.getLogic()); 
    attachInterrupt(red.getInterrupt(), updateRedFlag, red.getLogic());
    
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

    //debugging
    Serial.println(String(runFlag) + " " + String(green.getState()) + " " + String(red.getState()));
    //end debugging
    
    if(runFlag){
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (!runFlag){
        digitalWrite(LED_BUILTIN, LOW);
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
