/*
  Buzzer
  Sound on an buzzer on when button pressed.

  This example code is in the public domain.
 */
#include "lbed.h"
#include "Tone.h"

int duration = 500;

// Pin 7 has an tact switch on lbeDuino.
DigitalIn     sw(D7);
// Pin 2 has a buzzer on lbeDuino.
Tone          buzzer(D3);     // #A

// the setup routine runs once when you press reset:
void setup() {
}

// the loop routine runs over and over again forever:
void loop() {
  if (!sw) {                         // #B
    buzzer.tone(262, duration);     // ド, 500 msec
    wait_ms(500);
    buzzer.tone(294, duration);     // レ, 500 msec
    wait_ms(500);
    buzzer.tone(330, duration);     // ミ, 500 msec
  }
}
