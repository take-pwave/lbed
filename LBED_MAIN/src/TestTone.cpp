#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;

#include	"lbed.h"
#include	"Tone.h"

DigitalOut myled( LED1);
int tones[]={262,294,330,392,440};  // C, D, E, G, A
int toneDuration = 500;

int main(void) {
	wait_init();
	Serial	pc(p9, p10);
	pc.baud(9600);
	pc.println("Input number");
	// Toneのインスタンスを生成
	Tone	tone(p26);
	tone.noTone();

	while (1) {
		char c = pc.read();
		myled = !myled;
		if (c >= '1' && c <= '4') {
			int index = c - '1';
			tone.tone(tones[index], toneDuration);
		}
	}
	return 0;
}

