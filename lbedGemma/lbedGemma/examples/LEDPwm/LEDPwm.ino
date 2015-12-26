#include "TinyWireM.h"
#include "lbedGemma.h"
 
PwmOut led(1); // PWM LED

void setup() {  
}

void loop() {
  for (led = 0.0; led < 1.0; led = led + 0.02)
    wait_ms(20);
  for (led = 1.0; led > 0.0; led = led - 0.02)
    wait_ms(20);
}