#include "TinyWireM.h"
#include "lbedGemma.h"
#include "SoftwareSerial.h"
 
DigitalOut led(1); // Gemmaに付属のLED
SoftwareSerial pc(4, 3);  // RX=4, TX=3

void setup() {  
  pc.begin(4800);
}

void loop() {
  if (pc.available()) {
    // PCから受信した値
    int recv_value = pc.read();
    // PCにそのまま送信
    pc.write(recv_value);
    // 数字'0'〜'9'を数値の0〜9に変える
    int value = recv_value - '0';
    if (0 < value && value <= 9) {
      for (int i = 0; i < value; i++) {
        led = HIGH;
        wait_ms(250);
        led = LOW;
        wait_ms(250);
      }
    }
  }
}
