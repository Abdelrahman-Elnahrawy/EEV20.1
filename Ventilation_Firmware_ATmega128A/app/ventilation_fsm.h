#ifndef VENTILATION_FSM_H
#define VENTILATION_FSM_H

typedef enum
{
    VENT_INIT = 0,
    VENT_STANDBY,
    VENT_INHALE,
    VENT_EXHALE,
    VENT_ALARM
}VentState_t;

void VentilationFSM_Init(void);
void VentilationFSM_Update(void);

extern VentState_t VentState;

#endif
