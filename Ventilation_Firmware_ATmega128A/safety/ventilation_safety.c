#include "ventilation_safety.h"
#include "../config/ventilation_config.h"

extern float AFS;
extern float OFS;
extern float volume;

uint8_t Safety_CheckFault(void)
{
    float total = AFS + OFS;

    if (total < volume * (1.0f - FLOW_TOLERANCE)) return 1;
    if (total > volume * (1.0f + FLOW_TOLERANCE)) return 1;

    return 0;
}
