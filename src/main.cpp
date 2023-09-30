#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "MetronomeController.h"

MetronomeController* controller;
unsigned long* millisec; 
unsigned long t;

void setup() {
  Serial.begin(9600);
  t = millis();
  millisec = &t;

  controller = MetronomeController::getInstance(millisec);
}

void loop() {
  *millisec = millis();
  controller->update();
}

