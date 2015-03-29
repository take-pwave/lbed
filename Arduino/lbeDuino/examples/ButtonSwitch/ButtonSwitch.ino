/*
  ButtonSwitch
  Turns on an LED on when button pushed.
 
  This example code is in the public domain.
 */
#include "lbed.h"
 
// Pin 13 has an LED connected on most Arduino boards.
DigitalOut	led(13);
// Pin 7 has an tact switch on Protosanap Pro Mini.
DigitalIn	sw(7);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  led = !sw;
  wait_ms(200);               // wait for 200 mili seconds.
}