#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"
#include "PCF2123.h"

void DeepPowerDown(void) {
	int d;
	LPC_SYSCON->PDAWAKECFG = LPC_SYSCON->PDRUNCFG;

	LPC_SYSCON->PDSLEEPCFG=0xFFFFFFFF; 	//アナログブロックをOFF状態にする
	SCB->SCR |= 0x04;    				// システム制御レジスタのSLEEPDEEPビットをセット（クロック停止可能なときにクロック停止）
	LPC_PMU->PCON |= 0x2;				// DEEP PowerDownモードビットをセット
	d = LPC_PMU->PCON;
	__WFI();							// 割り込み待ちで停止
}

int main(void) {
	int wakeupCounter = 10;
    wait_init();
    DigitalOut myled(LED2);
	SerialCDC pc(USBTX, USBRX);
	pc.baud(9600);
	// キー入力を待つ
	pc.read();

    PCF2123     rtc(MOSI, MISO, SCKL, P0_2);
    // 1回目に時刻をセットした後は、コメントにするとRTCが動いていることが確認できる
    rtc.set_time(0x40, 0x42, 0x10, 0x01, 0x00, 0x09, 0x13);
    // 分単位の割り込みを発生するようにセット
    rtc.command((PCF2123::WRITE_BIT|PCF2123::SUBADDR|PCF2123::REG_CTRL2), 0x82);
    // アラームのセット(時間、分は、16進で指定する)
    // rtc.set_alarm(0x10, 0x33);
    int     pS = 0xff;
	pc.println("After 10 seconds, I will be into deep sleep!");
    myled = 1;
    while(1) {
    	rtc.read_rtc();
        if (pS != rtc.S) {
        	pc.printf("wake up count = %d\n",	wakeupCounter--);
            pc.printf("20%02x/%02x/%02x[%d] ",	rtc.Y, rtc.N, rtc.D, rtc.W&0x7);
            pc.printf("%02x/%02x/%02x\n",		rtc.H, rtc.M&0x7F, rtc.S&0x7F);
            pS = rtc.S;
        }
    	if (wakeupCounter == 0) {
            myled = 0;
            DeepPowerDown();
    	}
        wait_ms(100);
    }
}
