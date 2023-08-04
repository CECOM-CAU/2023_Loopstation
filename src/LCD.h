#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "IUpdatable.h"

class LCD: public IUpdatable {
private:
    const int address;
    const int row;
    const int col;
    const int num_of_layer;

    void init();

protected:
    String* str;
    LiquidCrystal_I2C lcd;

public: 
    LCD(int addr, int _row, int _col, int _layer): 
        address(addr), row(_row), col(_col), 
        lcd(LiquidCrystal_I2C(address, row, col)),
        num_of_layer(_layer){
        str = new String[row];
        init();
    }
    LCD(int addr, int _row, int _col): 
        address(addr), row(_row), col(_col), 
        lcd(LiquidCrystal_I2C(address, row, col)),
        num_of_layer(1) {
        str = new String[row];
        init();
    };

    LCD(): address(0x3F), row(2), col(16), lcd(LiquidCrystal_I2C(address, row, col)), num_of_layer(1){
        str = new String[row];
        init();
    }

    virtual void update()=0;
};