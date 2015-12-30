#include "TinyWireM.h"
#include "lbedGemma.h"
#include "AQCM0802.h"
#include "ADT7410.h"

AQCM0802 lcd(0, 2);  // sda, scl
ADT7410  themometer(0, 2, 0x90, 400000); // sda, scl, addr, hz
int I2CAdrs;

void setup()
{
    TinyWireM.begin();
    I2CAdrs = 0x48;     // スレーブアドレス
    lcd.setup();
    themometer.setConfig(ONE_SPS_MODE);
    // print TEXT
    lcd.print("Temp. is");
}

void loop()
{
  float temp = themometer.getTemp();
  lcd.locate(0, 1);
  lcd.print(temp, 2);
  lcd.print(" C.");

  wait_ms(1000);
}
