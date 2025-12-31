#ifndef VENTILATION_MACHINE_CALC_H
#define VENTILATION_MACHINE_CALC_H

#include <stdint.h>

extern float inhale_time;
extern float exhale_time;

void VentilationTiming_Init(void);
void VentilationTiming_Update(void);

uint8_t Ventilation_InhaleFinished(void);
uint8_t Ventilation_ExhaleFinished(void);
uint8_t Ventilation_ShouldStart(void);

#endif
