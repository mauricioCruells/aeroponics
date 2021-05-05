#include "Button.h"
#include "Arduino.h"

Button::Button(int pinNumber, String contactorOperation, int interruptNumber){
    pin = pinNumber;
    pinMode(pin, INPUT_PULLUP);
    interrupt = interruptNumber;
    state = false;

    if (contactorOperation == "NO"){
        buttonLogic = 2; // 2 is equivalent to FALLING
    }
    else if (contactorOperation == "NC"){
        buttonLogic = 3; // 3 is equivalent to RISING
    }
}

int Button::getLogic(){
    return buttonLogic;
}
int Button::getInterrupt(){
    return interrupt;
}


void Button::setState(){
    state = true;
}
void Button::resetState(){
    state = false;
}
bool Button::getState(){
    return state;
}