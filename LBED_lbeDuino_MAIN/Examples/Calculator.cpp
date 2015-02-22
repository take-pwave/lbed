#include "lbed.h"
#include "AQCM0802.h"
#include "Tone.h"
#include "Keypad.h"

// D8番ピンSDA, D9番ピンSCL
AQCM0802	lcd(D8, D9);
// 圧電スピーカー
Tone		buzzer(D3);
// キーパッド

const byte rows = 5; // 5行
const byte cols = 4; // 4列
char keys[rows][cols] = {
  {'S','I','R','T'},
  {'C','D','E','F'},
  {'8','9','A','B'},
  {'4','5','6','7'},
  {'0','1','2','3'}
};
PinName	rowPins[rows] = {D12, D10, D7, D11, D2};
PinName	colPins[cols] = {D4, D5, D6, D13};
Keypad	keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
	lcd.setup();
	lcd.print("I2C LCD");
}

void loop() {
	char c =keypad.getKey();
	if (c) {
		buzzer.tone(440, 100);
		lcd.locate(0, 1);
		lcd.print(c);
	}
	wait_ms(100);
}
