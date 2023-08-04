#include "IUpdatable.h"
#include "Neopixel.h"
#include "MetronomeModel.h"
#include "LCD.h"

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable** updatables;

public:
    MetronomeController(unsigned long* _time){
        updatables = (IUpdatable**)malloc(sizeof(IUpdatable*)*2);
        updatables[0] = new LCD(1, 2, 16);
        updatables[1] = new Neopixel(1, 3, nullptr, _time);
    }

    void update(){
        // 여기서 값 체크 
        
        //여기서 조건 보고 상황에 맞게 업데이트
        for(int i = 0; i < 2; i++){
            updatables[i]->update();
        }
    }
    

};