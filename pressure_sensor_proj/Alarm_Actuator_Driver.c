#include "Alarm_Actuator_Driver.h"

// global Pointer
void (*AA_State)();
// Alarm Intialization
void AA_init()
{
}
// states..
STATE_define(AA_Waiting)
{
    // state action
    AA_state_id = AA_Waiting;
    // check signal
    (stop_alarm()) ? (AA_State = STATE(AA_AlarmOff)) : (STATE(AA_AlarmOn));
}
STATE_define(AA_AlarmOn)
{
    // state action
    AA_state_id = AA_AlarmOn;
    // return to waiting state
    AA_State = AA_Waiting;
}
STATE_define(AA_AlarmOff)
{
    // state action
    AA_state_id = AA_AlarmOff;
    // return to waiting state
    AA_State = AA_Waiting;
}