/*
  Buzzer
  Sound on an buzzer on when button pressed.
 
  This example code is in the public domain.
 */
#include "lbedGemma.h"

int duration = 500;

// Pin 7 has an tact switch on Protosanap Pro Mini.
DigitalIn	sw(7);
// Pin 2 has a buzzer on Protosanap Pro Mini.
Tone		buzzer(2);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  if (!sw) {
    buzzer.tone(262, duration);	// C, 500 msec
    wait_ms(500);
    buzzer.tone(294, duration);	// D, 500 msec
    wait_ms(500);
    buzzer.tone(330, duration);	// E, 500 msec
  }   
}