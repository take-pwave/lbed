#include	"lbed.h"
#include	"Tone.h"

int main(void) {
	int tones[]={262,294,330,392,440};  // C, D, E, G, A
	int toneDuration = 500;

	Serial		pc(PA_1, PA_0);
	Tone		tone(PB_5);		// T1CCP1
	DigitalOut	myled(LEDR);
	pc.baud(19200);
	tone.noTone();

	pc.println("Input number");
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

