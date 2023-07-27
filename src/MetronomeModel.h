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