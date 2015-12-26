#include "TinyWireM.h"
#include "lbedGemma.h"
#include "SoftwareSerial.h"

DigitalOut led(1);
SoftwareSerial pc(4, 3);

void setup() {
  pc.begin(4800);
}

void loop() {
  if (pc.available()) {
    // 受信した値をrecv_valueに保持
    int recv_value = pc.read();
    // 受信した値をPCに送信
    pc.write(recv_value);
    // 受信した文字が数字ならその回数LEDを点滅させる
    int value = recv_value - '0';
    if (value > 0 && value <= 9) {
      for (int i = 0; i < value; i++) {
        led = HIGH;
        wait_ms(250);
        led = LOW;
        wait_ms(250);
      }
    }
  }

}
