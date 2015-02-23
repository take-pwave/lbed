#include "lbed.h"
#include "LM73.h"

// D13番ピンにLEDを接続
DigitalOut	led(D13);
// D8番ピンSDA, D9番ピンSCL
LM73 		lm73(D8, D9);
Serial 		pc(D0, D1);

void setup() {
	pc.baud(9600);
	pc.println("Hello World!");
}

void loop() {
	led = !led;
	float t = lm73.read();
	pc.print("Temp:");
	pc.print(t);
	pc.println("C");
	wait_ms(1000);
}
