// #include "BasicRotaryEncoder.h"

// int BasicRotaryEncoder::getRotate(){
//     int clk_val = getCLK();
//     int dt_val = getDT();
//     int ret = NONE;
//     if(clk_val != prev_clk_val){
//         Serial.print(clk_val);
//         Serial.print("\t");
//         Serial.println(dt_val);

//         if(dt_val != clk_val){
//             ret = CLOCK_WISE;
//         }
//         else{
//             ret = COUNTER_CLOCK_WISE;
//         }
//         prev_clk_val = clk_val;
//     }
//     return ret;
// }
