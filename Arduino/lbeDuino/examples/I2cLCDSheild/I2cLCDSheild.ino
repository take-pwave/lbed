#include "Wire.h"
#include "lbed.h"
#include "AQCM0802.h"

// D13番ピンにLEDを接続
DigitalOut     led(D13);
// D8番ピンSDA, D9番ピンSCL. ArduinoではハードI2Cを使用しているため、ピン番号は使用されていない。
AQCM0802     lcd(D8, D9);
// タクトスイッチ
DigitalIn     sw1(D2);
DigitalIn     sw2(D3);

void setup() {
     sw1.mode(PullUp);
     sw2.mode(PullUp);
     lcd.setup();
     lcd.print("I2C LCD");
}

void loop() {
     led = !led;
     lcd.locate(0, 1);
     
     if (!sw1) {
          lcd.print("SW1 On ");
     }
     else if (!sw2) {
          lcd.print("SW2 On ");
     }
     else {
          lcd.print("All Off");
     }
     wait_ms(1000);
}
