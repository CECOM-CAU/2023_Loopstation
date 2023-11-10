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

void tempoISR();
void rhythmISR();

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable** updatables;
    unsigned long* time = nullptr;

    BasicRotaryEncoder* tempoEncoder;
    BasicRotaryEncoder* rhythmEncoder;
    static MetronomeController* instance;

    MetronomeLCD* lcd = nullptr;

    void init(){
        updatables = (IUpdatable**)malloc(sizeof(IUpdatable*)*2);
        
        Serial.println("MC init begin");
        model = MetronomeModel();

        model.setEnable(true);
        model.setTempo(60);
        model.setRhythm(4);

        if(lcd == nullptr){
            lcd = new MetronomeLCD(&model, time);
        }
        else{
            lcd->reset(time);
        }
        updatables[0] = lcd;
        updatables[1] = new Neopixel(7, 3, &model, time);

        Serial.println("MC init middle");

        tempoEncoder = new BasicRotaryEncoder(18, 39, 37);
        attachInterrupt(digitalPinToInterrupt(18), tempoISR, CHANGE);
        rhythmEncoder = new BasicRotaryEncoder(19, 51, 49);
        attachInterrupt(digitalPinToInterrupt(19), rhythmISR, CHANGE);
    }
    MetronomeController(){
        // init();
    }

    MetronomeController(unsigned long* _time){
        time = _time;
        init();
    }

    friend void tempoISR();
    friend void rhythmISR();

public:  
    static MetronomeController* getInstance(){
        if(instance->time == nullptr){
            return nullptr;
        }
        return instance;
    }  
    static MetronomeController* getInstance(unsigned long* _time){
        if(instance->time == nullptr){
            // instance = new MetronomeController(_time);
            instance->time = _time;
            instance->init();
        }
        else{
            Serial.println("Set Time with getInstance");
            instance->time = _time;
        }
        return instance;
    }

    // void setModel(MetronomeModel &model);
    // MetronomeModel& getModel()

    void update();
};
#endif