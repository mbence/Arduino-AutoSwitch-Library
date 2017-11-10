/*
  AutoSwitch - Method chaining example

  This example demonstrates the use of the AutoSwitch.h libray, with method
  chaining setup, to switch the on-board LED on and off. With zhis setup type,
  the parameters are much easier to idetify and understand, as with the 
  classic constructor parameter version.
  
  The built-in LED can be turned ON and OFF with the press of a button, but 
  if left ON, it will automatically turn OFF after 10 seconds.
  
  The circuit:
  - push button attached from pin 2 to ground
  - built-in LED on pin 13

  We use pinMode(INPUT_PULLUP), so there is no pull-down resistor necessary. 

  created 8 Nov 2017
  by Bence Meszaros
*/

#include <AutoSwitch.h>

// create the LedButton object
AutoSwitch LedButton;

void setup() {
  // set the internal led pin
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize the button on pin 2, and set the auto-off to 10 seconds
  LedButton
    .setPin(2)
    .setAutoOff(10);
}

void loop() {
  //read the pushbutton value into a variable
  int buttonState = LedButton.getState();

  // the getState() function returns HIGH or LOW, so we can use this value directly on the led output
  digitalWrite(LED_BUILTIN, buttonState);
}
