#include "lbed.h"
#include "Tone.h"

int duration = 2000;
Tone          buzzer(D11);     // #A

// the setup routine runs once when you press reset:
void setup() {
	buzzer.tone(440, duration);
}

// the loop routine runs over and over again forever:
void loop() {
}
