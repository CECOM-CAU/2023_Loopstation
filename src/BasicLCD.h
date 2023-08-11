#ifndef __BASIC_LCD_H__
#define __BASIC_LCD_H__

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "IUpdatable.h"

class BasicLCD: public IUpdatable {
private:
    const int address;
    const int row;
    const int col;
    const int num_of_layer;

    void init();

protected:
    String* str = nullptr;
    LiquidCrystal_I2C* lcd = nullptr;

public: 
    BasicLCD(int addr, int _row, int _col, int _layer): 
        address(addr), row(_row), col(_col), 
        num_of_layer(_layer){
        str = new String[row];
        init();
    }
    BasicLCD(int addr, int _row, int _col): 
        address(addr), row(_row), col(_col), 
        num_of_layer(1) {
        str = new String[row];
        init();
    };

    BasicLCD(): address(0x3F), row(2), col(16), num_of_layer(1){
        str = new String[row];
        init();
    }

    virtual void update()=0;
};

#endif