/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
#include "TinyWireM.h"
#include "lbedGemma.h"
 
// Pin 1 has an LED connected on Gemma, Trinket boards.
DigitalOut led(1);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  led = !led;
  wait_ms(1000);               // wait for a second
}