#include "Button.h"
#include "Arduino.h"

Button::Button(int pinNumber, String contactorOperation, int interruptNumber){
    pin = pinNumber;
    pinMode(pin, INPUT_PULLUP);
    interrupt = interruptNumber;

    if (contactorOperation == "NO"){
        buttonLogic = FALLING;
    }
    else if (contactorOperation == "NC"){
        buttonLogic = RISING;
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