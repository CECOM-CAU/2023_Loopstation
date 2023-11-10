#ifndef __METRONOME_MODEL_H__
#define __METRONOME_MODEL_H__

class MetronomeModel{
public:
    void setRhythm(float);
    void setTempo(float);
    void setEnable(bool);

    float getRhythm();
    float getTempo();
    bool isEnable();

private:
    float rhythm;
    float tempo;
    bool enable; 
};

#endif