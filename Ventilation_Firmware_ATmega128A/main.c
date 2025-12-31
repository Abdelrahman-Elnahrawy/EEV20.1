#include <avr/io.h>
#include "app/ventilation_fsm.h"
#include "ui/ventilation_lcd.h"

int main(void)
{
    VentilationFSM_Init();
    VentilationLCD_Init();

    while (1)
    {
        VentilationFSM_Update();
        VentilationLCD_Update();
    }
}
