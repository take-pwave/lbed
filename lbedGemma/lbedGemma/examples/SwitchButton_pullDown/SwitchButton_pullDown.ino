#include "TinyWireM.h"
#include "lbedGemma.h"
 
DigitalOut  led(1);  // GPIO #1 LED on board.
DigitalIn   sw(2);   // GPIO #2

void setup() {                
}

void loop() {
  if (sw == HIGH) {
    led = HIGH;
    wait_ms(250);
    led = LOW;
    wait_ms(250);
  }
}