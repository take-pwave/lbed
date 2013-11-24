#include "lbed.h"
#include "I2cLCD.h"

// Icon Name ----
// Mark
// Battery_1
// Battery_2
// Battery_3
// Battery_4
// NoSound
// Lock
// ArrowDown
// ArrowUp
// Input
// Alarm
// Tell
// Antenna
// --------------

int main() {
	lbed_setup();

	I2cLCD lcd(J4_3, J2_2, J2_10); //sda scl reset

    // print TEXT
	// printfのva_argsの処理が変！
	lcd.print("Dsp test");
    // lcd.printf("Dsp test");
    lcd.locate(0, 1);
    lcd.print("Hello World!");
    // print ICON
    lcd.seticon( I2cLCD::Mark );
    lcd.seticon( I2cLCD::Battery_1 );
    lcd.seticon( I2cLCD::Battery_2 );
    lcd.seticon( I2cLCD::Battery_3 );
    lcd.seticon( I2cLCD::Battery_4 );
    lcd.seticon( I2cLCD::NoSound );
    lcd.seticon( I2cLCD::Lock );
    lcd.seticon( I2cLCD::ArrowDown );
    lcd.seticon( I2cLCD::ArrowUp );
    lcd.seticon( I2cLCD::Input );
    lcd.seticon( I2cLCD::Alarm );
    lcd.seticon( I2cLCD::Tell );
    lcd.seticon( I2cLCD::Antenna );

    while(1) {
        lcd.clearicon( I2cLCD::Antenna );
        wait_ms(500); //wait(0.5);
        lcd.seticon( I2cLCD::Antenna );
        wait_ms(500); //wait(0.5);
    }
}
