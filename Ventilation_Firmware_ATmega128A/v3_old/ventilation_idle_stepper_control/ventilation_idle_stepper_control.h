#ifndef VENTILATION_IDLE_STEPPER_CONTROL_H
#define VENTILATION_IDLE_STEPPER_CONTROL_H

#include <Arduino.h>
#include <Stepper.h>

/* ================= Configuration ================= */
#define STEPS_PER_REV 200
#define STEPPER_SPEED_RPM 60

/* ================= Public Variables ================= */
// Inputs (must be updated externally)
extern float oxygen;   // Oxygen percentage (21 → 100)
extern float volume;   // Tidal volume

extern float AFS;      // Air Flow Sensor
extern float OFS;      // Oxygen Flow Sensor

/* ================= API ================= */
void Ventilation_Init(void);
void Ventilation_Update(void);

#endif // VENTILATION_IDLE_STEPPER_CONTROL_H
