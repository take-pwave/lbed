/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
#include "lbed.h"
 
// Pin 13 has an LED connected on most Arduino boards.
DigitalOut led(D13);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  led = !led;
  wait_ms(1000);               // wait for a second
}