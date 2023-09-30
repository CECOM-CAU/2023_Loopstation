#ifndef __BASIC_ROTARY_ENCODER_H__
#define __BASIC_ROTARY_ENCODER_H__

#include <Arduino.h>
#include "MetronomeController.h"

class BasicRotaryEncoder {
private:
    const int clk_pin;
    const int dt_pin;
    const int sw_pin;

    int prev_clk_val;

    int getDT() {return digitalRead(dt_pin);}
    int getCLK(){return digitalRead(clk_pin);}

    friend void tempoISR();
    friend void rhythmISR();

public: 
    static const int COUNTER_CLOCK_WISE = -1;
    static const int CLOCK_WISE = 1;
    static const int NONE = 0;

    BasicRotaryEncoder(int _clk, int _dt, int _sw): clk_pin(_clk), dt_pin(_dt), sw_pin(_sw){
        pinMode(clk_pin, INPUT);
        pinMode(dt_pin, INPUT);
        pinMode(sw_pin, INPUT_PULLUP);

        prev_clk_val = digitalRead(clk_pin);
    }

    int getRotate();
};
#endif