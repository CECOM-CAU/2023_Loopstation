#include "IUpdatable.h"
#include "Neopixel.h"
#include "MetronomeModel.h"
#include "LCD.h"
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
        updatables[0] = new MetronomeLCD(&model);
        updatables[1] = new Neopixel(1, 3, nullptr, time);
    }

    void update(){
        // 여기서 값 체크 
        
        //여기서 조건 보고 상황에 맞게 업데이트
        for(int i = 0; i < 2; i++){
            updatables[i]->update();
        }
    }
    

};