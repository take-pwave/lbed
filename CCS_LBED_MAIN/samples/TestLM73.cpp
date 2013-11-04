#include"lbed.h"
#include "LM73.h"

int main(void) {
	lbed_setup();

	LM73 lm73(PB_3, PB_2);
	Serial pc(PA_1, PA_0);
	pc.baud(19200);
	// 注意）Serialの影響を受けるので、最後にLEDを生成した
	DigitalOut myled(LEDG);

	while (1) {
		float t = lm73.read();
		pc.printf("temp=%d.%02d\n", int(t), (int(t*100)%100));
		myled = !myled;
		wait_ms(1000);
	}
}
