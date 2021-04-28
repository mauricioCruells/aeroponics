#pragma once
#include "Arduino.h"

class Button{
  
  private:

  volatile bool state;
  int pin;
  String contactor;
  int interrupt;

  public:
  
  Button(int pinNumber, String contactorOperation, int interruptNumber);

  void set();
  void reset();
  bool getState();

};