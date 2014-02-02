// I2cLCD テストスケッチ　勝さんのサンプルプログラムから移植
#include "lbed.h"
#include "I2cLCD.h"
#include "Wire.h"

I2cLCD lcd(A4, A5, 2);  // sda, scl, reset

void setup()
{
    lcd.setup();
    // print TEXT
    lcd.print("Dsp test");
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
}

void loop()
{
    lcd.clearicon( I2cLCD::Antenna );
    wait_ms(500); //wait(0.5);
    lcd.seticon( I2cLCD::Antenna );
    wait_ms(500); //wait(0.5);
}