/*
  LEDPwm
  PWM on an LED.
 
  This example code is in the public domain.
 */
#include "lbed.h"
 
// Pin 5 has an Green LED connected on Protosnap pro mini boards.
PwmOut led(5);

// the setup routine runs once when you press reset:
void setup() {  
	led = 0.5;              
}

// the loop routine runs over and over again forever:
void loop() {
        led = led + 0.02;
        if(led >= 1.0) {
            led = 0.0;
        }
        wait_ms(80);
}