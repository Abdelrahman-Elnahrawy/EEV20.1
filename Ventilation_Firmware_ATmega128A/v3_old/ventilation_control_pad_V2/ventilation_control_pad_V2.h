#ifndef VENTILATOR_KEYPAD_V1_H
#define VENTILATOR_KEYPAD_V1_H

#include <Arduino.h>
#include <Keypad.h>

/* ===================== Public Parameters ===================== */
extern float VK_Oxygen;     // Oxygen %
extern float VK_MP;         // Max Pressure
extern float VK_Rate;       // Respiratory rate
extern float VK_Volume;     // Tidal volume
extern int   VK_Mode;       // Ventilation mode
extern int   VK_Ratio;      // I/E ratio

/* ===================== API ===================== */
void VentilatorKeypad_Init(void);
void VentilatorKeypad_Update(void);

#endif
