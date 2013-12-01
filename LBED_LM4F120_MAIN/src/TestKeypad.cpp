#include "lbed.h"
#include "Keypad.h"

int main(void) {
	const byte rows = 4; //four rows
	const byte cols = 3; //three columns
	char keys[rows][cols] = {
	  {'1','2','3'},
	  {'4','5','6'},
	  {'7','8','9'},
	  {'*','0','#'}
	};
	byte	rowPins[rows] = {J1_9, J1_8, J1_7, J1_6};	//connect to the row pinouts of the keypad
	byte	colPins[cols] = {J1_5, J1_4, J1_3};			//connect to the column pinouts of the keypad
	Serial	pc(PA_1, PA_0);
	Keypad	keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
	pc.baud(19200);
	pc.println("InputNumber");
	wait_ms(500);
	while (1) {
		char c = keypad.getKey();
		if (c)
			pc.write(c);
	}
}

