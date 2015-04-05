/*
  ButtonSwitch（ボタンスイッチの例）
  ボタンを押すとLEDが点灯します。
*/
#include "lbed.h"
 
// D13番ピンに接続されたLEDを使用
DigitalOut	led(D13);
// D7番ピンに接続されたタクトスイッチを使用
DigitalIn	sw(D7);

// リセット時に呼び出されるsetupでは、特に処理は必要ありません。
void setup() {                
}

// 毎回呼び出されるloopで、タクトスイッチの値を読んで、LEDを点灯します。
void loop() {
  led = !sw;      // タクトスイッチは押すと0になるので、!で反転した値をledにセットします
  wait_ms(200);   // 200ミリ秒待つ
}
