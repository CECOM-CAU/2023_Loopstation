#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "IUpdatable.h"

class LCD: public IUpdatable {
private:
    const int address;
    const int row;
    const int col;
    const LiquidCrystal_I2C lcd;
    const int num_of_layer;

    String* str;

public: 
    LCD(int addr, int _row, int _col, int _layer): 
        address(addr), row(_row), col(_col), 
        lcd(LiquidCrystal_I2C(address, row, col)),
        num_of_layer(_layer){
        
    }
    LCD(int addr, int _row, int _col): 
        address(addr), row(_row), col(_col), 
        lcd(LiquidCrystal_I2C(address, row, col)),
        num_of_layer(1) {
        
    };

    virtual void update() = 0;
};
