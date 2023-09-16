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

public:    
    MetronomeController(unsigned long* _time){
        updatables = (IUpdatable**)malloc(sizeof(IUpdatable*)*2);
        
        time = _time;
        
        model = MetronomeModel();

        model.setEnable(true);
        model.setTempo(60);
        model.setRhythm(4);

        updatables[0] = new MetronomeLCD(&model, time);
        // updatables[1] = new Neopixel(1, 3, &model, time);

        tempoEncoder = new BasicRotaryEncoder(20, 39, 37);

        // auto tempo_ISR = [=]()->void {
        //     if(tempoEncoder->getRotate() == CLOCK_WISE){
        //         model.setTempo(model.getTempo() + 1);
        //     }
        // };

        attachInterrupt(20, tempoISR, CHANGE);
        rhythmEncoder = new BasicRotaryEncoder(21, 51, 49);
        attachInterrupt(21, tempoISR, CHANGE);
    }

    void update(){
        int te_val = tempoEncoder->getRotate();
        int re_val = rhythmEncoder->getRotate();

        // 여기서 값 체크 
        if(te_val == CLOCK_WISE){
            model.setTempo(model.getTempo() + 1);
        }else if(te_val == COUNTER_CLOCK_WISE){
            model.setTempo(model.getTempo() - 1);
        }

        if(re_val == CLOCK_WISE){
            model.setRhythm(model.getRhythm() + 1);
        }else if(re_val == COUNTER_CLOCK_WISE){
            model.setRhythm(model.getRhythm() - 1);
        }

        //여기서 조건 보고 상황에 맞게 업데이트
        for(int i = 0; i < 1; i++){
            updatables[i]->update();
        }
    }
};

void tempoISR();
void rhythmISR();

#endif