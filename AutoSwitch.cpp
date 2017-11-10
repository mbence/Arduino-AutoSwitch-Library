/*
  AutoSwitch - a button with automatic off timer

  created 8 Nov 2017
  by Bence Meszaros
*/

#include "Arduino.h"
#include "AutoSwitch.h"


AutoSwitch::AutoSwitch()
{
  this->state = LOW;
  this->debounce = 200;
  this->debounceTimer = 0;
}

AutoSwitch::AutoSwitch(int pin, unsigned long autoOff)
  : AutoSwitch()
{
  this->setPin(pin);
  this->setAutoOff(autoOff);
}

AutoSwitch& AutoSwitch::setPin(int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT_PULLUP);
    
    return *this;
}

AutoSwitch& AutoSwitch::setAutoOff(unsigned long time)
{
    this->autoOff = time * 1000;
    
    return *this;
}

int AutoSwitch::getState()
{
  int newState = digitalRead(this->pin);

  // check state change
  if (this->oldState != newState && millis() - this->debounceTimer > this->debounce) {
    if (newState == LOW) {
      this->state = !this->state;
      if (this->autoOff > 0) {
        this->autoOffTimer = millis();
      }
      this->debounceTimer = millis();
    }
    this->oldState = newState;
  }
    
  // check auto off
  if (this->autoOffTimer > 0 &&  millis() - this->autoOffTimer >= this->autoOff) {
      this->state = LOW;
      this->autoOffTimer = 0;
  }

  return this->state;
}
