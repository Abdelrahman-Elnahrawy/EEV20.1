#include "Air_Flow_Sensors_V1.h"

/* ===================== Error Flag ===================== */
int AirFlow_ERROR = 0;

/* ===================== Raw Readings ===================== */
static float CurrentReadingO = 0;
static float CurrentReadingA = 0;
static float CurrentReadingP = 0;

/* ===================== Averages ===================== */
static float SumO = 0;
static float SumA = 0;
static float SumP = 0;

static float AverageO = 0;
static float AverageA = 0;
static float AverageP = 0;

/* ===================== Flow Outputs ===================== */
float OxygenFlow  = 0;   // OF
float AirFlow     = 0;   // AF
float PatientFlow = 0;   // PF

/* ===================== 3 sec Accumulators ===================== */
static float OFSUM = 0;
static float AFSUM = 0;
static float PFSUM = 0;

static unsigned long previousMillis = 0;

/* ========================================================= */

void AirFlow_Init(void)
{
  AirFlow_ERROR = 0;
  previousMillis = millis();
}

/* ========================================================= */

void AirFlow_Update(void)
{
  unsigned long currentMillis = millis();

  /* -------- Oxygen Sensor Averaging -------- */
  SumO = 0;
  for (int i = 0; i < FLOW_AVG_SAMPLES; i++)
  {
    CurrentReadingO = analogRead(OXYGEN_SENSOR_PIN);
    SumO += CurrentReadingO;
  }
  AverageO = SumO / FLOW_AVG_SAMPLES;

  /* -------- Air Sensor Averaging -------- */
  SumA = 0;
  for (int i = 0; i < FLOW_AVG_SAMPLES; i++)
  {
    CurrentReadingA = analogRead(AIR_SENSOR_PIN);
    SumA += CurrentReadingA;
  }
  AverageA = SumA / FLOW_AVG_SAMPLES;

  /* -------- Patient Sensor Averaging -------- */
  SumP = 0;
  for (int i = 0; i < FLOW_AVG_SAMPLES; i++)
  {
    CurrentReadingP = analogRead(PATIENT_SENSOR_PIN);
    SumP += CurrentReadingP;
  }
  AverageP = SumP / FLOW_AVG_SAMPLES;

  /* -------- Accumulate for 3 sec window -------- */
  OFSUM += AverageO;
  AFSUM += AverageA;
  PFSUM += AverageP;

  /* -------- Check flow balance every 3 sec -------- */
  if (currentMillis - previousMillis >= FLOW_CHECK_TIME_MS)
  {
    previousMillis = currentMillis;

    if (PFSUM < (AFSUM + OFSUM) * 0.95 ||
        PFSUM > (AFSUM + OFSUM) * 1.05)
    {
      AirFlow_ERROR = 1;
    }
    else
    {
      AirFlow_ERROR = 0;
    }

    OFSUM = 0;
    AFSUM = 0;
    PFSUM = 0;
  }

  /* -------- Flow Calculation (NOT MEDICALLY VALID) -------- */
  OxygenFlow  = (AverageO - 68) * 0.265 + 2.7;
  AirFlow     = (AverageA - 68) * 0.265 + 2.7;
  PatientFlow = (AverageP - 68) * 0.265 + 2.7;
}
