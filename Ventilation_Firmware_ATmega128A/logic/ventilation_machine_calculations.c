#include "ventilation_machine_calculations.h"
#include <avr/io.h>
#include <util/delay.h>

extern float rate;
extern float ratio;

static uint32_t phaseStart = 0;
static uint8_t inhaleActive = 0;

float inhale_time;
float exhale_time;

uint32_t millis(void); // implemented via timer ISR

void VentilationTiming_Init(void)
{
    inhale_time = (60.0f / rate) / ratio;
    exhale_time = (60.0f / rate) - inhale_time;
}

void VentilationTiming_Update(void)
{
    uint32_t now = millis();

    if (!inhaleActive)
    {
        phaseStart = now;
        inhaleActive = 1;
    }
}

uint8_t Ventilation_InhaleFinished(void)
{
    return (millis() - phaseStart) >= (uint32_t)(inhale_time * 1000);
}

uint8_t Ventilation_ExhaleFinished(void)
{
    return (millis() - phaseStart) >= (uint32_t)(exhale_time * 1000);
}

uint8_t Ventilation_ShouldStart(void)
{
    return 1;
}
