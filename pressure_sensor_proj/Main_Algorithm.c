#include "Main_Algorithm.h"
// global pointer
void (*MA_State)();
// variables
int threshold = 20;
int MA_PVal;

int high_pressure_detected(int val)
{
    return (val > threshold);
}

STATE_define(MA_High_Pressure_Detection)
{
    // state action
    MA_State = MA_High_Pressure_Detection;
    // get pressure value
    MA_PVal = getPressureVal();
    // check if the value is more than threshold or not
    if (MA_PVal > threshold)
        high_pressure_detected(MA_PVal);
    else
        (MA_State = STATE(MA_High_Pressure_Detection));
}
