/*
  AutoSwitch - On-board LED example

  This example demonstrates the use of the AutoSwitch.h libray, to switch 
  the on-board LED on and off. The built-in LED can be turned ON and OFF 
  with the press of a button, but if the second parameter is set, it will 
  automatically turn OFF after the set seconds.
  
  The circuit:
  - push button attached from pin 2 to ground
  - built-in LED on pin 13

  We use pinMode(INPUT_PULLUP), so there is no pull-down resistor necessary. 

  created 8 Nov 2017
  by Bence Meszaros
*/

#include <AutoSwitch.h>

// initialize the button on pin 2, and set the auto-off to 12 seconds
AutoSwitch LedButton(2, 10);

void setup() {
  // set the internal led pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //read the pushbutton value into a variable
  int buttonState = LedButton.getState();

  // the getState() function returns HIGH or LOW, so we can use this value directly on the led output
  digitalWrite(LED_BUILTIN, buttonState);
}
