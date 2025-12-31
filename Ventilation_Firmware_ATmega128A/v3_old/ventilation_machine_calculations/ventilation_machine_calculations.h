#ifndef VENTILATION_MACHINE_CALCULATIONS_H
#define VENTILATION_MACHINE_CALCULATIONS_H

#include <Arduino.h>

/* ================= External Inputs ================= */
extern float rate;     // Breaths per minute
extern float ratio;    // I:E ratio (1,2,3...)

extern bool inhalePhase;
extern bool exhalePhase;

/* ================= API ================= */
void VentilationTiming_Init(void);
void VentilationTiming_Update(void);

#endif // VENTILATION_MACHINE_CALCULATIONS_H
