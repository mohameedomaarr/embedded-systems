#include "Alarm_Monitor.h"
// global pointer
void (*AM_State)();
// the alarm state to turn it on or off

// start signal
void AM_init()
{
}
int start_alarm()
{
    Set_Alarm_actuator(0);
    Delay(600);
    stop_alarm();
    return 1;
}
int stop_alarm()
{
    Set_Alarm_actuator(1);
    Delay(600);
    return 0;
}

// states..

STATE_define(AM_AlarmOn)
{
    // state action
    AM_state_id = AM_AlarmOn;
    // Alarm is started
    start_alarm();
    // Alarm is stopped
    (high_pressure_detected(getPressureVal())) ? (AM_State = STATE(AM_AlarmOn)) : (AM_State = STATE(AM_AlarmOff));
}

STATE_define(AM_AlarmOff)
{
    // state action
    AM_state_id = AM_AlarmOff;
    // signal ..
    stop_alarm();
    // checking in case of high pressure to start the alarm
    (!high_pressure_detected(getPressureVal())) ? (AM_State = STATE(AM_AlarmOff)) : (AM_State = STATE(AM_AlarmOn));
}
