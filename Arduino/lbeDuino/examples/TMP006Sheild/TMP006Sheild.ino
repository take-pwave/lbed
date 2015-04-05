#include "lbed.h"
#include "TMP006.h"
#include "AQCM0802.h"

#define Address (0x40<<1)

// D8番ピンSDA, D9番ピンSCL
TMP006           sensor(D8, D9, Address);
AQCM0802     lcd(D8, D9);

void setup() {
     lcd.setup();
     sensor.config(Address, 8);
}

void loop() {
     lcd.locate(0, 0);
     lcd.print("DieTemp: ");
     lcd.print(sensor.readDieTempC(Address), 2);
     lcd.locate(0, 1);
     lcd.print("ObjTemp: ");
     lcd.print(sensor.readObjTempC(Address), 2);
     wait_ms(1000);
}