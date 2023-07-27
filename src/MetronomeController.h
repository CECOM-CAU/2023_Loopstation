#include "IUpdatable.h"
#include "Neopixel.h"
#include "MetronomeModel.h"
#include "LCD.h"

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable* metronomeLCD = LCD();
    IUpdatable* metronomeNeopixel = Neopixel();

public:
    void update(){
        // 여기서 값 체크 

        //여기서 조건 보고 상황에 맞게 업데이트
        metronomeLCD->update();
        metronomeNeopixel->update();
    }
    

};