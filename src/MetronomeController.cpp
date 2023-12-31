#include "MetronomeController.h"

MetronomeController* MetronomeController::instance = new MetronomeController();

void MetronomeController::update(){
    // static unsigned long t = (*time);
    // if((*time) - t > 1000){
    //     t = (*time);
    //     Serial.println("MC update");
    // }
    // int te_val = tempoEncoder->getRotate();
    // int re_val = rhythmEncoder->getRotate();

    // 여기서 값 체크 
    // if(te_val == CLOCK_WISE){
    //     model.setTempo(model.getTempo() + 1);
    // }else if(te_val == COUNTER_CLOCK_WISE){
    //     model.setTempo(model.getTempo() - 1);
    // }

    // if(re_val == CLOCK_WISE){
    //     model.setRhythm(model.getRhythm() + 1);
    // }else if(re_val == COUNTER_CLOCK_WISE){
    //     model.setRhythm(model.getRhythm() - 1);
    // }

    //여기서 조건 보고 상황에 맞게 업데이트
    for(int i = 0; i < 2; i++){
        updatables[i]->update();
    }
}

void tempoISR(){
    MetronomeController* ctrlr = MetronomeController::getInstance();
    int clk_val = ctrlr->tempoEncoder->getCLK();
    int dt_val = ctrlr->tempoEncoder->getDT();

    if(dt_val != clk_val){
        ctrlr->model.setTempo(ctrlr->model.getTempo() + 0.4);
    }
    else{
        ctrlr->model.setTempo(ctrlr->model.getTempo() - 0.4);
    }
}
void rhythmISR(){
    MetronomeController* ctrlr = MetronomeController::getInstance();
    int clk_val = ctrlr->rhythmEncoder->getCLK();
    int dt_val = ctrlr->rhythmEncoder->getDT();

    if(dt_val != clk_val){
        ctrlr->model.setRhythm(ctrlr->model.getRhythm() + 0.2);
    }
    else{
        ctrlr->model.setRhythm(ctrlr->model.getRhythm() - 0.2);
    }
}