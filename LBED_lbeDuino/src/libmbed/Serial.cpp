#include "Serial.h"
#include "PinNames.h"
#include "LPC11xx.h"

Serial::Serial()
	: _tx(-1)
	, _rx(-1)
{
	setup(P1_6, P1_7, "default");
}

Serial::Serial(PinName tx, PinName rx, const char *name)
	: _tx(-1)
	, _rx(-1)
{
	setup(tx, rx, name);
}

void Serial::setup(PinName tx, PinName rx, const char *name)
{
	_tx = tx;
	_rx = rx;
	_available = false;
	LPC_IOCON->PIO1_6 |= 0x01;							// RXD機能に設定(FUNC=001)
	LPC_IOCON->PIO1_7 |= 0x01;							// TXD機能に設定(FUNC=001)
}

void Serial::baud(unsigned int baudrate) {
	unsigned int DL;
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);				// UARTへクロック供給
	LPC_SYSCON->UARTCLKDIV = 0x01;						// ボーレート生成ブロックへクロック供給
	DL = (SystemCoreClock * LPC_SYSCON->SYSAHBCLKDIV)	// ボーレート分周比の算出
		/ (16 * baudrate * LPC_SYSCON->UARTCLKDIV);
	LPC_UART->LCR |= (1<<7);							// ディバイザ・ラッチ・アクセス有効(DLAB=1)
	LPC_UART->DLM = DL / 256;							// ボーレートの設定(U0DLM)
	LPC_UART->DLL = DL % 256;							// ボーレートの設定(U0DLL)
	LPC_UART->LCR &= ~(1<<7);							// ディバイザ゙・ラッチ・アクセス無効(DLAB=0)
	LPC_UART->LCR = 0x03;								// データのフォーマット設定（8bit Non Stop 1）
	LPC_UART->FCR = 0x07;								// 入出力バッファの初期化
	_available = true;									// 利用可能にセット
}

void Serial::begin(unsigned int baudrate) {
	baud(baudrate);
}

int Serial::write(const char c) {
	while (!(LPC_UART->LSR & (1<<5)))					// データ転送待ち
		continue;
	LPC_UART->THR = c;									// データ送信
	return 1;
}

int Serial::read() {
	while (!(LPC_UART->LSR & 0x01))						// 受信待ち
		continue;
	return LPC_UART->RBR;								// データ受信
}

int Serial::available() {
	return _available ? 1 : 0;
}
