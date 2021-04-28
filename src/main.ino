#include <Arduino.h>
#include "Button.h"

bool runFlag = false;
Button green(2, "NO", 0);
Button red(3, "NC", 1);



void setup() {
    attachInterrupt(green.getInterrupt(), updateGreenFlag, green.getLogic()); 
    attachInterrupt(red.getInterrupt(), updateRedFlag, red.getLogic());
}

void loop() {

}




void updateGreenFlag(){
    green.setState();
    red.resetState();
    runFlag = green.getState();
}

void updateRedFlag(){
    green.resetState();
    red.setState();
    runFlag = red.getState();
}
