#ifndef __METRONOME_LCD_H__
#define __METRONOME_LCD_H__

#include <Arduino.h>
#include "BasicLCD.h"
#include "MetronomeModel.h"

class MetronomeLCD : public BasicLCD{
private:
    MetronomeModel* model;

    bool isChanged = false;
    int rhythm = 0;
    int tempo = 0;

    void updateTempo();
    void updateRhythm();

    uint8_t addr;
    unsigned long* time;
    unsigned long startTime;
public:
    MetronomeLCD(MetronomeModel* _model , unsigned long* _time): BasicLCD(){
        model = _model;
        time = _time;
        startTime = millis();
    }
    MetronomeLCD(MetronomeModel* _model, byte _addr, int _row, int _col, unsigned long* _time)
    : BasicLCD(_addr, _row, _col){
        addr = _addr;
        model = _model;
        time = _time;
        startTime = millis();
    }

    void update();
};

#endif