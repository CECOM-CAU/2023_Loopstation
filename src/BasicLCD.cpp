#include <Arduino.h>
#include "BasicLCD.h"
#include "LiquidCrystal_I2C.h"

void BasicLCD::init(){
    lcd = new LiquidCrystal_I2C(address, col, row);
    lcd->init();
    lcd->backlight();

    Serial.print("LCD Addr: 0x");
    if(address < 16) Serial.print("0");
    Serial.println(address, HEX);
}