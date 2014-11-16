/*
  SoftSerialTxOnly
  I2CデバイスLM73から値を読み取り、シリアルに4800ボーで送信する
 */

#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

#include <cr_section_macros.h>

#include "lbed.h"
#include "SoftSerialTxOnly.h"
#include "LM73.h"

int main(void) {
	// lbedライブラリの初期化
	lbed_setup();
	/* I2C用スイッチマトリックスの設定 */
	I2C_SwitchMatrix_Init();

	// 8番ピンSDA, 2番ピンSCL
	LM73	lm73(P8, P2);
	// 5番ピンをURARTのRxに接続
	SoftSerialTxOnly pc(P5);
	pc.println("Hello World\n");
	while(1) {
		pc.print("temp=");
		//pc.print(lm73.read(), 2);
		// floatを使うとサイズオーバーになるので、0.1度までを整数で出力
		int v = lm73.read();
		pc.print(v, DEC);
		pc.println();
		wait_ms(1000);	// 1秒待つ
	}
    return 0 ;
}
