#include "Button.h"
#include "Arduino.h"

Button::Button(int pinNumber, String contactorOperation, int interruptNumber){
    pin = pinNumber;
    pinMode(pin, INPUT_PULLUP);
    interrupt = interruptNumber;

    if (contactorOperation == "NO"){
        buttonLogic = 0;
    }
    else if (contactorOperation == "NC"){
        buttonLogic = 1;
    }

}

int Button::getLogic(){
    return buttonLogic;
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