/*
  AutoSwitch - a button with automatic off timer

  created 8 Nov 2017
  by Bence Meszaros
*/

#ifndef AutoSwitch_h
#define AutoSwitch_h

#include "Arduino.h"

class AutoSwitch {
  private: 
    int pin;
    int oldState;
    int state;
    unsigned long debounce;
    unsigned long debounceTimer;
    unsigned long autoOff;
    unsigned long autoOffTimer;
  public:
    AutoSwitch(int pin, unsigned long autoOff = 0);
    AutoSwitch();
    AutoSwitch& setPin(int pin);
    AutoSwitch& setAutoOff(unsigned long time);
    int getState();
};

#endif
