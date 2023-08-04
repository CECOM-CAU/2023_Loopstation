#include"MetronomeModel.h"

void MetronomeModel::setRhythm(int _rhythm)
{
    this -> rhythm = _rhythm;
}

int MetronomeModel::getRhythm()
{
    return rhythm;
}

void MetronomeModel::setTempo(int _tempo)
{
    this -> tempo = _tempo;
}

void MetronomeModel::setEnable(bool _isenable)
{
    this -> enable = _isenable;
}

int MetronomeModel::getTempo()
{
    return tempo;
}

bool MetronomeModel::isEnable()
{
    return enable;
}
