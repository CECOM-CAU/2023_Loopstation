#include "MetronomeSound.h"
#define INITIAL_FREQ
#define BEEP_FREQ
#define SPEAKER_PIN

/* 
이거 중간에 템포가 바뀌거나 리듬이 바뀌면 
그 상태에서 바로 다시 소리를 
시작해야 하고 화면과 동기화가 되어야 할 것 같은데
update 가 되면 바로 바뀌게 하려는데 어렵군
 어떻게 하면 좋을지 모르겠음
*/
void MetronomeSound::updateTempo(){
    int newTempo = model->getTempo();
    if(newTempo != tempo){
        tempo = newTempo;
        isChanged = true;
    }
}

void MetronomeSound::updateRhythm(){
    int newRhythm = model->getRhythm();
    if(newRhythm != rhythm){
        rhythm = newRhythm;
        isChanged = true;
    }
}

void MetronomeSound::update(){
     if((*time - startTime) == tempo){
        startTime = *time;
    }
    updateTempo();
    updateRhythm();
    if(isChanged){
        MetronomeSound -> indicator_sound()
    }
}

void MetronomeSound::indicator_sound(){
    int beep = 0;
    int beat = 0;

    beep = (*time - startTime) / tempo; ///beep 의 길이
    beat = tempo / rhythm /// 예를 들어 60 템포에 4박이면 15에 한번씩 비트
    for(int i = 0, i < rhythm, i++)
    {
        if (i = 0)///첫 박만 initual frequency
        {
            tone(SPEAKER_PIN, INITIAL_FREQ, beep);
        }
        else{/// 나머지 박의 비프음
            tone(SPEAKER_PIN, BEEP_FREQ, beep);         
        }
        delay(beat);///비프음 중간 시간
        
    }
    
}