#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"

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
    wait_init();
    DigitalOut myled(LED2);
    myled = 1;
	int wakeupCounter = 30;
    while(1) {
    	if (--wakeupCounter == 0) {
            myled = 0;
            DeepPowerDown();
    	}
        wait_ms(1000);
    }
}
