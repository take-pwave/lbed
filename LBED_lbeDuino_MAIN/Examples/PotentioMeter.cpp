/*
  PotentioMeter
  Turns on an LED on when potentiometer > 0.33V(0.1).

  This example code is in the public domain.
 */
#include "lbed.h"

// Pin 13 has an LED connected on lbeDuino.
DigitalOut   led(D13);
// Pin A0 has a analog input.
AnalogIn     sensor(A0);     // #A

// the setup routine runs once when you press reset:
void setup() {
}

// the loop routine runs over and over again forever:
void loop() {
  float value = sensor;
  if (value > 0.1)          // #B
    led = 1;
  else
    led = 0;
  wait_ms(200);              // wait for 200 mili seconds.
}
