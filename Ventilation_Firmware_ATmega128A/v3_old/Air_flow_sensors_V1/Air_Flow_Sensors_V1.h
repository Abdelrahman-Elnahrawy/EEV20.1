#ifndef AIR_FLOW_SENSORS_V1_H
#define AIR_FLOW_SENSORS_V1_H

#include <Arduino.h>

/* ===================== Configuration ===================== */
#define OXYGEN_SENSOR_PIN   A5
#define AIR_SENSOR_PIN      A6
#define PATIENT_SENSOR_PIN  A7

#define FLOW_AVG_SAMPLES    10
#define FLOW_CHECK_TIME_MS  3000

/* ===================== Global Status ===================== */
extern int AirFlow_ERROR;

/* ===================== Flow Results ===================== */
extern float OxygenFlow;   // OF
extern float AirFlow;      // AF
extern float PatientFlow;  // PF

/* ===================== API ===================== */
void AirFlow_Init(void);
void AirFlow_Update(void);

#endif
