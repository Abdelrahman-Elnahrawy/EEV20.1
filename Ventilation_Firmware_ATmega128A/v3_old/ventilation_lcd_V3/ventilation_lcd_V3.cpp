#include "ventilation_lcd_V3.h"

/* ================= LCD OBJECT ================= */
static LiquidCrystal lcd(
    LCD_RS, LCD_EN,
    LCD_D4, LCD_D5,
    LCD_D6, LCD_D7
);

/* ================= TEXT TABLES ================= */
static const char *modeStrings[] =
{
    "Pressure A",
    "Pressure",
    "Volume A",
    "Volume"
};

static const char *ratioStrings[] =
{
    "1:1",
    "1:2",
    "1:3"
};

/* ================= Internal Timing ================= */
static unsigned long lastRefresh = 0;
#define LCD_REFRESH_MS 200   // refresh rate

/* ================= Init ================= */
void VentilationLCD_Init(void)
{
    lcd.begin(16, 4);

    lcd.print(
        "pressure:  cm.H2O"
        "O2%:  % rate:   "
        "V:    ml       "
        "I/E:           "
    );
}

/* ================= Update (NON-BLOCKING) ================= */
void VentilationLCD_Update(void)
{
    unsigned long now = millis();
    if (now - lastRefresh < LCD_REFRESH_MS)
        return;

    lastRefresh = now;

    /* ---- Error Screen ---- */
    if (ERORR == 1)
    {
        lcd.setCursor(0, 0);
        lcd.print("!!! AIR LEAK !!! ");
        lcd.setCursor(0, 1);
        lcd.print("CHECK SYSTEM    ");
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(0, 3);
        lcd.print("                ");
        return;
    }

    /* ---- Normal Display ---- */
    lcd.setCursor(9, 0);
    lcd.print("    ");
    lcd.setCursor(9, 0);
    lcd.print(MP);

    lcd.setCursor(5, 1);
    lcd.print("          ");
    lcd.setCursor(5, 1);
    lcd.print(modeStrings[mode]);

    lcd.setCursor(4, 2);
    lcd.print("   ");
    lcd.setCursor(4, 2);
    lcd.print(oxygen);

    lcd.setCursor(13, 2);
    lcd.print("   ");
    lcd.setCursor(13, 2);
    lcd.print(rate);

    lcd.setCursor(2, 3);
    lcd.print("    ");
    lcd.setCursor(2, 3);
    lcd.print(volume);

    lcd.setCursor(13, 3);
    lcd.print(ratioStrings[ratio]);
}
