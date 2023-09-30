#ifndef __METRONOME_CONTROLLER_H__
#define __METRONOME_CONTROLLER_H__


#include "IUpdatable.h"
#include "Neopixel.h"
#include "BasicLCD.h"
#include "MetronomeModel.h"
#include "MetronomeLCD.h"
#include "BasicRotaryEncoder.h"

#define CLOCK_WISE BasicRotaryEncoder::CLOCK_WISE
#define COUNTER_CLOCK_WISE BasicRotaryEncoder::COUNTER_CLOCK_WISE

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable** updatables;
    unsigned long* time;

    BasicRotaryEncoder* tempoEncoder;
    BasicRotaryEncoder* rhythmEncoder;
    static MetronomeController* instance;
    MetronomeController(unsigned long* _time){
        updatables = (IUpdatable**)malloc(sizeof(IUpdatable*)*2);
        
        time = _time;
        
        model = MetronomeModel();

        model.setEnable(true);
        model.setTempo(60);
        model.setRhythm(4);

        updatables[0] = new MetronomeLCD(&model, time);
        updatables[1] = new Neopixel(1, 3, &model, time);

        tempoEncoder = new BasicRotaryEncoder(20, 39, 37);
        attachInterrupt(20, tempoISR, CHANGE);
        rhythmEncoder = new BasicRotaryEncoder(21, 51, 49);
        attachInterrupt(21, rhythmISR, CHANGE);
    }

    friend void tempoISR();
    friend void rhythmISR();

public:    
    static MetronomeController* getInstance(unsigned long* _time){
        if(instance == nullptr){
            instance = new MetronomeController(_time);
        }
        else{
            instance->time = _time;
        }
        return instance;
    }
    static MetronomeController* getInstance(){
        return instance;
    }

    void update();
};

void tempoISR();
void rhythmISR();

#endif