#include <Arduino.h>
bool greenFlag = false;

void setup() {

}

void loop() {

}



class Button{
  
  volatile bool state;
  int pin;
  String contactor;
  int interrupt;

  public:
  Button(int pinNumber, String contactorOperation, int interruptNumber){
    pin = pinNumber;
    pinMode(pin, INPUT_PULLUP);

    contactor = contactorOperation;
    interrupt = interruptNumber;
  }

  void set(){
    state = true;
  }

  void reset(){
    state = false;
  }

  bool getState(){
    return state;
  }

};