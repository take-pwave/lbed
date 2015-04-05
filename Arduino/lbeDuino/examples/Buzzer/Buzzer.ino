/*
  Buzzer（ブザーの例）
  ボタンを押すと圧電ブザーがド、レ、ミと鳴ります。
 */
#include "lbed.h"

int duration = 500;

// D７番ピンに接続されたタクトスイッチを使用
DigitalIn     sw(D7);
// D3番ピンに接続された圧電ブザーを使用
Tone          buzzer(D3);          // #A

// リセット時に呼び出されるsetupでは、特に処理は必要ありません。
void setup() {                
}

// 毎回呼び出されるloopで、タクトスイッチの値を読んで、ブザーを鳴らします。
void loop() {
  if (!sw) {                        // #B
    buzzer.tone(262, duration);     // ド, 500 msec
    wait_ms(500);
    buzzer.tone(294, duration);     // レ, 500 msec
    wait_ms(500);
    buzzer.tone(330, duration);     // ミ, 500 msec
  }
}