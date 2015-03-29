/*
  LightSensor
  Turns on an LED on when light sensor > 0.5V(0.1).
 
  This example code is in the public domain.
 */
#include "lbed.h"
 
// Pin 13 has an LED connected on most Arduino boards.
DigitalOut	led(13);
// Pin A0 has a light sensor on Protosanap Pro Mini.
AnalogIn	sensor(A0);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  if (sensor > 0.1) 
    led = 1;
  else
    led = 0;
  wait_ms(200);               // wait for 200 mili seconds.
}