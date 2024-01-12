#include "MetronomeController.h"

MetronomeController* MetronomeController::instance = new MetronomeController();

void MetronomeController::update(){
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