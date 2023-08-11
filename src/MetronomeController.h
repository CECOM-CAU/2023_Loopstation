#ifndef __METRONOME_CONTROLLER_H__
#define __METRONOME_CONTROLLER_H__

#include "IUpdatable.h"
#include "Neopixel.h"
#include "MetronomeModel.h"
#include "BasicLCD.h"
#include "MetronomeLCD.h"

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable** updatables;
    unsigned long* time;

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
    }

    void update(){
        Serial.println("MET_CONTROL_UPDATE");
        // 여기서 값 체크 
        //여기서 조건 보고 상황에 맞게 업데이트
        for(int i = 0; i < 1; i++){
            updatables[i]->update();
        }
        delay(500);
    }
    

};

#endif