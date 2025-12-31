#include "ventilation_idle_stepper_control.h"
#include "../drivers/stepper_driver.h"

extern float oxygen;
extern float volume;
extern float AFS;
extern float OFS;

void Ventilation_Init(void)
{
    Stepper_Init();
}

void Ventilation_Update(void)
{
    float AIR = (100.0f - oxygen) / 79.0f;
    float OIR = 1.0f - AIR;

    float AF = AIR * volume;
    float OF = OIR * volume;

    Stepper_ControlAir(AF, AFS);
    Stepper_ControlOxygen(OF, OFS);
}

void Ventilation_StopAll(void)
{
    Stepper_Stop();
}
