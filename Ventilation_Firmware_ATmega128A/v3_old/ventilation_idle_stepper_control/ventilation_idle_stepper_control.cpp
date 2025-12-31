#include "ventilation_idle_stepper_control.h"

/* ================= Internal Variables ================= */
static float AIR;   // Air Idle Ratio
static float OIR;   // Oxygen Idle Ratio

static float AF;    // Required Air Flow
static float OF;    // Required Oxygen Flow

/* ================= Stepper Objects ================= */
static Stepper AirValve   (STEPS_PER_REV, 4, 5, 6, 7);
static Stepper OxygenValve(STEPS_PER_REV, 8, 9, 10, 11);

/* ================= Initialization ================= */
void Ventilation_Init(void)
{
    AirValve.setSpeed(STEPPER_SPEED_RPM);
    OxygenValve.setSpeed(STEPPER_SPEED_RPM);
}

/* ================= Main Update (NON-BLOCKING) ================= */
void Ventilation_Update(void)
{
    /* ---- Calculate Ratios ---- */
    AIR = (100.0f - oxygen) / 79.0f;
    OIR = 1.0f - AIR;

    /* ---- Required Flow ---- */
    AF = AIR * volume;
    OF = OIR * volume;

    /* ---- Air Valve Control ---- */
    if (AFS < AF)
    {
        AirValve.step(1);     // open slightly
    }
    else if (AFS > AF)
    {
        AirValve.step(-1);    // close slightly
    }

    /* ---- Oxygen Valve Control ---- */
    if (OFS < OF)
    {
        OxygenValve.step(1);
    }
    else if (OFS > OF)
    {
        OxygenValve.step(-1);
    }
}
