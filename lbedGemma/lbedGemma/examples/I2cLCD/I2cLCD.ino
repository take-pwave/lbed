#include "TinyWireM.h"
#include "lbedGemma.h"
#include "AQCM0802.h"

AQCM0802 lcd(0, 2);  // sda, scl

void setup()
{
    TinyWireM.begin();
    lcd.setup();
    // print Hello Wrold!
    lcd.print("Hello");
    lcd.locate(0, 1);
    lcd.print("World!");
}

void loop()
{
}