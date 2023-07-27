#include "Neopixel.h"

Neopixel::Neopixel(int _pin, int _rgb, MetronomeModel* _model, unsigned long* _time){
    model = _model;
}

void Neopixel::update(){
    int r = model->getRhythm();
}

