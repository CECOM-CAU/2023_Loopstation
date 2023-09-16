#include "MetronomeLCD.h"

void MetronomeLCD::updateTempo(){
    int newTempo = model->getTempo();
    if(newTempo != tempo){
        str[0] = "Tempo : " + String(newTempo);
        tempo = newTempo;
        isChanged = true;
    }
}

void MetronomeLCD::updateRhythm(){
    int newRhythm = model->getRhythm();
    if(newRhythm != rhythm){
        str[1] = "Rhythm : " + String(newRhythm);
        rhythm = newRhythm;
        isChanged = true;
    }
}

void MetronomeLCD::update(){
    if((*time - startTime) > 100){
        startTime = *time;
    }
    else{
        return;
    }
    isChanged = false;
    updateTempo();
    updateRhythm();
    if(isChanged){
        lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print(str[0].c_str());
        // Serial.println(str[0]);
        lcd->setCursor(0, 1);
        lcd->print(str[1].c_str());
        // Serial.println(str[1]);
    }
}