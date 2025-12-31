#include "ventilation_machine_calculations.h"

/* ================= Internal Variables ================= */
static unsigned long phaseStartTime = 0;
static unsigned long inhaleTimeMs = 0;
static unsigned long exhaleTimeMs = 0;

static enum
{
    PHASE_INHALE,
    PHASE_EXHALE
} ventilationPhase;

/* ================= Init ================= */
void VentilationTiming_Init(void)
{
    float cycleTimeSec = 60.0f / rate;

    float inhaleRatio = 1.0f;
    float exhaleRatio = ratio;

    inhaleTimeMs = (cycleTimeSec * (inhaleRatio / (inhaleRatio + exhaleRatio))) * 1000.0f;
    exhaleTimeMs = (cycleTimeSec * (exhaleRatio / (inhaleRatio + exhaleRatio))) * 1000.0f;

    ventilationPhase = PHASE_INHALE;
    phaseStartTime = millis();

    inhalePhase = true;
    exhalePhase = false;
}

/* ================= Update (NON-BLOCKING) ================= */
void VentilationTiming_Update(void)
{
    unsigned long now = millis();

    switch (ventilationPhase)
    {
        case PHASE_INHALE:
            inhalePhase = true;
            exhalePhase = false;

            if (now - phaseStartTime >= inhaleTimeMs)
            {
                ventilationPhase = PHASE_EXHALE;
                phaseStartTime = now;
            }
            break;

        case PHASE_EXHALE:
            inhalePhase = false;
            exhalePhase = true;

            if (now - phaseStartTime >= exhaleTimeMs)
            {
                ventilationPhase = PHASE_INHALE;
                phaseStartTime = now;
            }
            break;
    }
}
