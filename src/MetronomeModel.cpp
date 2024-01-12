#include"MetronomeModel.h"

void MetronomeModel::setRhythm(float _rhythm)
{
    this -> rhythm = _rhythm;
}

float MetronomeModel::getRhythm()
{
    return rhythm;
}

void MetronomeModel::setTempo(float _tempo)
{
    this -> tempo = _tempo;
}

void MetronomeModel::setEnable(bool _isenable)
{
    this -> enable = _isenable;
}

float MetronomeModel::getTempo()
{
    return tempo;
}

bool MetronomeModel::isEnable()
{
    return enable;
}
