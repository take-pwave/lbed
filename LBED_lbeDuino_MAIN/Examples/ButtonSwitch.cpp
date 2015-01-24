#include "lbed.h"
// Pin 13 has an LED connected on most lbeDuino boards.
DigitalOut	led(D13);
// Pin 7 has an tact switch on bread board.
DigitalIn	sw(D7);          // #A

// the setup routine runs once when you press reset:
void setup() {
}

// the loop routine runs over and over again forever:
void loop() {
  led = !sw;                // #B
  wait_ms(200);             // wait for 200 mili seconds.
}
