#include "lbed.h"

DigitalOut myled(D13);
Serial pc(D0, D1);

void setup() {
	pc.baud(9600);
	pc.println("Hello World!");
}

void loop() {
	char c = pc.read();
	pc.write(c + 1);
	myled = !myled;
}
