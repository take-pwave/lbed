#include "LPC11xx.h"

void (*irs0Ptr)() = 0;
void (*irs1Ptr)() = 0;
uint32_t	_mask0;
uint32_t	_mask1;

void setIRS0Function(void(*fptr)(void), uint32_t mask) {
	irs0Ptr = fptr;
	_mask0 = mask;
}

void setIRS1Function(void(*fptr)(void), uint32_t mask) {
	irs1Ptr = fptr;
	_mask1 = mask;
}

void PIOINT0_IRQHandler(void) {
	if (irs0Ptr) {
		(*irs0Ptr)();
	}
	if (LPC_GPIO0 ->MIS & _mask0) {	// 割り込み検出
		LPC_GPIO0 ->IC |= _mask0;		// 割り込みエッジ検出ロジックのクリア
	}
}

void PIOINT1_IRQHandler(void) {
	if (irs1Ptr) {
		(*irs1Ptr)();
	}
	if (LPC_GPIO1 ->MIS & _mask1) {	// 割り込み検出
		LPC_GPIO1 ->IC |= _mask1;		// 割り込みエッジ検出ロジックのクリア
	}
}
