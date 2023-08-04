#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "MetronomeController.h"

const int address = 0x3F;
LiquidCrystal_I2C lcd(address, 16, 2);

MetronomeController controller;
unsigned long* millisec; 

void setup() {
  controller = MetronomeController(millisec);
}

void loop() {
  *millisec = millis();
  controller.update();
}