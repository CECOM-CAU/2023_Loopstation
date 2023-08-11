#ifndef __METRONOME_MODEL_H__
#define __METRONOME_MODEL_H__

class MetronomeModel{
public:
    void setRhythm(int);
    void setTempo(int);
    void setEnable(bool);

    int getRhythm();
    int getTempo();
    bool isEnable();

private:
    int rhythm;
    int tempo;
    bool enable; 
};

#endif