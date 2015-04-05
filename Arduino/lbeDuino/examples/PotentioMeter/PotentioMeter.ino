/*
  PotentioMeter（電圧測定の例）
  電圧が規定電圧（3.3V）の0.1倍になったらLEDを消します。
 */
#include "lbed.h"

// D13番ピンに接続されたLEDを使用
DigitalOut   led(D13);
// A0番をアナログ入力に使用
AnalogIn     sensor(A0);    // #A

// リセット時に呼び出されるsetupでは、特に処理は必要ありません。
void setup() {
}

// 毎回呼び出されるloopで、potentiometerの値を読んで、0.33V以下ならLEDを消します。
void loop() {
  float value = sensor;
  if (value > 0.1)           // #B
    led = 1;
  else
    led = 0;
  wait_ms(200);              // 200ミリ秒待つ
}