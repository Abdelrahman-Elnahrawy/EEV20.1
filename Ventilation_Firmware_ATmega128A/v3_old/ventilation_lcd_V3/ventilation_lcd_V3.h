#ifndef VENTILATION_LCD_V3_H
#define VENTILATION_LCD_V3_H

#include <Arduino.h>
#include <LiquidCrystal.h>

/* ================= LCD PINS ================= */
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

/* ================= External Shared Variables ================= */
extern int MP;        // Max Pressure
extern int oxygen;   // Oxygen %
extern int rate;     // Breathing rate
extern int volume;   // Volume (ml)
extern int ratio;    // I/E ratio index
extern int mode;     // Mode index
extern int ERORR;    // Error flag

/* ================= API ================= */
void VentilationLCD_Init(void);
void VentilationLCD_Update(void);

#endif // VENTILATION_LCD_V3_H
