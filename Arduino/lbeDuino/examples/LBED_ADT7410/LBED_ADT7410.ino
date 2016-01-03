#include "Wire.h"
#include "lbed.h"
#include "ADT7410.h"

ADT7410 healthThemometer(D8, D9, 0x90, 400000);

void setup() {
  Wire.begin(4, 14); // Wire.begin();
  Serial.begin(9600);
  healthThemometer.setConfig(ONE_SPS_MODE);
}

void loop() {
  float temp = healthThemometer.getTemp();
  Serial.print("Current temperature is ");
  Serial.print(temp, 2);
  Serial.println(" C. ");
  wait_ms(2000);
}
