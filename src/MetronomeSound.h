#ifndef __METRONOME_LCD_H__
#define __METRONOME_LCD_H__

#include <Arduino.h>
#include "MetronomeModel.h"
#include "IUpdatable.h"

class MetronomeSound : public IUpdatable {
private:
    MetronomeModel* model;

    bool isChanged = false;
    int rhythm = 0;
    int tempo = 0;

    void updateTempo();
    void updateRhythm();

    unsigned long* time;
    unsigned long startTime;
public:
    MetronomeSound(MetronomeModel* _model , unsigned long* _time){
        model = _model;
        time = _time;
        startTime = millis();
    }
    void indicator_sound();
    void update();
};

#endif