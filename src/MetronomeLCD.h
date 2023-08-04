#include "LCD.h"
#include "MetronomeModel.h"

class MetronomeLCD : public LCD{
private:
    MetronomeModel* model;

    bool isChanged = false;
    int rhythm = 0;
    int tempo = 0;

    void updateTempo();
    void updateRhythm();

public:
    MetronomeLCD(MetronomeModel* _model): LCD(){
        model = _model;
    }

    void update();
};