#include "IUpdatable.h"
#include "MetronomeModel.h"

class Neopixel : public IUpdatable{
private:
    int pin;
    int rgb;
    
    MetronomeModel* model;
    unsigned long* time;

public: 
    Neopixel(int _pin, int _rgb, MetronomeModel* _model, unsigned long* _time);
    void update();
};