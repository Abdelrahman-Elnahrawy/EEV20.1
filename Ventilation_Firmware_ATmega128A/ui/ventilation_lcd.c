#include "ventilation_lcd.h"
#include "../drivers/lcd_driver.h"

extern int MP, oxygen, rate, volume, ratio, ERORR;

void VentilationLCD_Init(void)
{
    LCD_Init();
}

void VentilationLCD_Update(void)
{
    if (ERORR)
        LCD_ShowAlarm();
    else
        LCD_ShowValues(MP, oxygen, rate, volume, ratio);
}
