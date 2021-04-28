#include "Button.h"
#include "Arduino.h"

  Button::Button(int pinNumber, String contactorOperation, int interruptNumber){
    pin = pinNumber;
    pinMode(pin, INPUT_PULLUP);

    contactor = contactorOperation;
    interrupt = interruptNumber;
  }

  void Button::set(){
    state = true;
  }

  void Button::reset(){
    state = false;
  }

  bool Button::getState(){
    return state;
  }