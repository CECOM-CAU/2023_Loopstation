#include "Neopixel.h"
#include <Adafruit_NeoPixel.h>


Neopixel::Neopixel(int _pin, int _rgb, MetronomeModel* _model, unsigned long* time){
    model = _model;
    pin = _pin;
    pixels = new Adafruit_NeoPixel(NUM_LEDS, _pin, NEO_GRBW + NEO_KHZ800);
    pixels->begin();
    pixels->show();
    startTime = *time;
    this->time = time;

}

void Neopixel::update(){

    int bpm = model -> getTempo();
    int rhythm = model -> getRhythm();
    unsigned long tempo = 60000/static_cast<unsigned long>(bpm); //밀리세컨드로 변환한 템포

    //여기까지 초기설정
    //여기서부터 업데이트

    int cycle = (*time - startTime)/tempo; //몇박째인지 (0박 시작)
    int current = (*time - startTime)%tempo; //한 박 안에서 시간이 얼마나 지났는지

    int i = current*16/tempo; //픽셀 위치

    Serial.println(i);
    if (cycle%rhythm == 0) { 
        pixels->setPixelColor(i, Adafruit_NeoPixel::Color(255, 255, 255)); //리듬 첫박은 하얀색 빛
        pixels->setBrightness(0xff);
        pixels->show();
    }
    else {
        pixels->setPixelColor(i, Adafruit_NeoPixel::Color(255, 0, 0)); //나머지 박은 빨간색 빛
        pixels->setBrightness(0xff);
        pixels->show();
    }
    pixels->setPixelColor((i-2+16)%16, Adafruit_NeoPixel::Color(0, 0, 0));
    // pixels->setBrightness(0x0);
    pixels->show();
}

