#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;

#include"lbed.h"
#include "PCF2123.h"

int main(void) {
	wait_init();
	DigitalOut myled(LED2);

	SerialCDC pc(USBTX, USBRX);
	pc.baud(9600);
	// キー入力を待つ
	pc.read();
	pc.println("Real Time Clock Test.");

	PCF2123	rtc(MOSI, MISO, SCKL, P0_2);
	rtc.set_alarm(0x45, 0x59, 0x23, 0x31, 0x06, 0x12, 0x10);

	int	pS = 0xff;
	while (1) {
		rtc.read_rtc();
		if (pS != rtc.S) {
			pc.printf("%d%d/%d%d/%d%d[%d] ", (rtc.Y>>4)&0xf, rtc.Y&0xf, (rtc.N>>4)&0xf, rtc.N&0xf,(rtc.D>>4)&0xf, rtc.D&0xf, rtc.W&0x7);
			pc.printf("%d%d:%d%d:%d%d\r\n",(rtc.H>>4)&0xf, rtc.H&0xf, (rtc.M>>4)&0xf, rtc.M&0xf,(rtc.S>>4)&0xf, rtc.S&0xf);
			myled = !myled;
			pS = rtc.S;
		}
		wait_ms(100);
	}
	return 0;
}
