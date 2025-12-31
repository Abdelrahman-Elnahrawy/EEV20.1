#include "ventilation_fsm.h"
#include "../logic/ventilation_machine_calculations.h"
#include "../control/ventilation_idle_stepper_control.h"
#include "../safety/ventilation_safety.h"

VentState_t VentState = VENT_INIT;

void VentilationFSM_Init(void)
{
    VentState = VENT_STANDBY;
}

void VentilationFSM_Update(void)
{
    switch (VentState)
    {
        case VENT_STANDBY:
            if (Ventilation_ShouldStart())
                VentState = VENT_INHALE;
        break;

        case VENT_INHALE:
            Ventilation_Update();
            if (Ventilation_InhaleFinished())
                VentState = VENT_EXHALE;
        break;

        case VENT_EXHALE:
            if (Ventilation_ExhaleFinished())
                VentState = VENT_INHALE;
        break;

        case VENT_ALARM:
            Ventilation_StopAll();
        break;

        default:
            VentState = VENT_ALARM;
        break;
    }

    if (Safety_CheckFault())
        VentState = VENT_ALARM;
}
