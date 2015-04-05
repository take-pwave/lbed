/*
  BlinkLED（LEDの点滅）
  １秒間隔でLEDを点滅します。
 */
#include "lbed.h"
 
// D13番ピンに接続されたLEDを使用
DigitalOut led(D13);

// リセット時に呼び出されるsetupでは、特に処理は必要ありません。
void setup() {                
}

// 毎回呼び出されるloopで、ledを切り替えて１秒待ちます。
void loop() {
  led = !led;        // LEDを切り替える（点灯→消灯、消灯→点灯）
  wait_ms(1000);     // １秒待つ（1000ミリ秒=１秒）
}
