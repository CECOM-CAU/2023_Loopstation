#include "IUpdatable.h"
#include "Neopixel.h"
#include "MetronomeModel.h"
#include "LCD.h"

class MetronomeController : public IUpdatable{
private:
    MetronomeModel model;

    IUpdatable** updatables;

public:
    MetronomeController(){
        updatables = (IUpdatable**)malloc(sizeof(IUpdatable**)*2);
        
    }


    void update(){
        // 여기서 값 체크 
        
        //여기서 조건 보고 상황에 맞게 업데이트
        for(int i = 0; i < 2; i++){
            updatables[i]->update();
        }
    }
    

};