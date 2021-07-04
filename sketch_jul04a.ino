#include <Arduino.h>
#include "RotaryEncoder.h"


#define __CLK_PIN 2
#define __DT_PIN 3
#define __SW_PIN 4
#define __ACTIVE LOW

RotaryEncoder RE(__CLK_PIN, __DT_PIN, __SW_PIN, __ACTIVE);

void checkRotary()
{
  RE.waitRotary();
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, checkRotary, FALLING);
  Serial.println("Initialize complete!");
}

void loop() {
  //RE.waitRotary();
  if (RE.rotaryData.avai)
  {
    Serial.println("Count = " + String(RE.rotaryData.count));
    RE.dataGot();
  }
  if (RE.isButtonPressed())
  {
    Serial.println(digitalRead(__CLK_PIN));
    Serial.println(digitalRead(__DT_PIN));
  }
  
}
