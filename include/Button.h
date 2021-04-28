#pragma once
#include "Arduino.h"

class Button{
  
    private:

    int buttonLogic;
    volatile bool state;
    int pin;
    int interrupt;

    public:

    Button(int pinNumber, String contactorOperation, int interruptNumber);

    int getLogic();

    void setState();
    void resetState();
    bool getState();

};