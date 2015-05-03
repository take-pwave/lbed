#include "lbed.h"
#include "lpcdevice.h"

// D13番ピンにLEDを接続
DigitalOut	led(D13);
// タクトスイッチ
//DigitalIn	sw1(D5);
InterruptIn	sw1(D2);
extern "C" {
extern void setIRS0Function(void(*fptr)(void), uint32_t mask);
extern void setIRS1Function(void(*fptr)(void), uint32_t mask);
};

uint32_t	_mask = (1<<1);

void flip() {
	led = !led;
}

void setup() {
	led = 0;
	sw1.mode(PullUp);
	sw1.fall(&flip);
/*
	setIRS0Function(&flip, _mask);
	sw1.mode(PullUp);
	NVIC_EnableIRQ(EINT0_IRQn);
	LPC_GPIO0->IS &= ~_mask;
	LPC_GPIO0->IBE &= ~_mask;
	LPC_GPIO0->IEV &= ~_mask;
	LPC_GPIO0->IE |= _mask;
*/
}

void loop() {
	wait_ms(200);
}
