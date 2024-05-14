#include <stdint.h>
#include <stdio.h>

#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"
#include "Pressure_sensor_driver.h"
#include "Main_Algorithm.h"
void setup()
{
    PS_init();
    AM_init();
    AM_init();

    PS_State = STATE(PS_Reading);
    AM_State = STATE(AM_AlarmOff);
    AA_State = STATE(AA_Waiting);
    MA_State = STATE(MA_High_Pressure_Detection);
}
int main()
{
    GPIO_INITIALIZATION();
    setup();
    while (1)
    {
        Set_Alarm_actuator(1);
        Delay(100);
        PS_State();
        AM_State();
        AA_State();
        MA_State();
    }
    return 0;
}
