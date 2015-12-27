#include "TinyWireM.h"
#include "lbedGemma.h"
#include "SoftwareSerial.h"
 
SoftwareSerial pc(4, 3);  // RX=4, TX=3
AnalogIn lm35(1);

void setup() {  
  pc.begin(4800);
}

void loop() {
  float value = lm35*5.0*100.0; 
  
  pc.print("Temp="); pc.print(value, 1); pc.println("");
  wait_ms(1000);
}
