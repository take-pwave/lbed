#include "lbedGemma.h"
#include "Wire.h"
#include "LM73.h"

DigitalOut led(13);
LM73  lm73(A4, A5);

void setup() 
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Hello World");
  lm73.setup();
}

void loop()
{
  led = ~ led;
  float t = lm73.read();
  Serial.print("Temp=");
  Serial.println(t);
  wait_ms(1000);
}