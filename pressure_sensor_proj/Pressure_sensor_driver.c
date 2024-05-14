#include "Pressure_sensor_driver.h"
// global pointer
void (*PS_State)();
static int PS_val;

// Intialization Function prototype
void PS_init()
{
}
// states..
STATE_define(PS_Waiting)
{
    // state action
    PS_state_id = PS_Waiting;
    // Pull Timer
    Delay(1000);
    // Timer Expired
    PS_State = STATE(PS_Reading);
}
STATE_define(PS_Reading)
{
    // state action
    PS_state_id = PS_Reading;
    // read from ps
    PS_val = getPressureVal();
    // change state
    PS_State = STATE(PS_Waiting);
}
