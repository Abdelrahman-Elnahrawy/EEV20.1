#include "Ventilator_Keypad_V1.h"
#include <math.h>

/* ===================== Keypad Configuration ===================== */
const byte ROWS = 4;
const byte COLS = 4;

static char keys[ROWS][COLS] = {
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
};

static byte rowPins[ROWS] = {9, 8, 7, 6};
static byte colPins[COLS] = {5, 4, 3, 2};

static Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* ===================== Internal Variables ===================== */
static int IT = 0;      // Input type
static int x  = 2;
static int S  = 0;
static unsigned long previousMillis = 0;

/* ===================== Public Parameters ===================== */
float VK_Oxygen = 21;
float VK_MP     = 25;
float VK_Rate   = 15;
float VK_Volume = 500;
int   VK_Mode   = 1;
int   VK_Ratio  = 1;

/* ============================================================= */

void VentilatorKeypad_Init(void)
{
  IT = 0;
  x  = 2;
  S  = 0;
  previousMillis = millis();
}

/* ============================================================= */

void VentilatorKeypad_Update(void)
{
  unsigned long currentMillis = millis();

  char keyChar = keypad.getKey();
  if (!keyChar) return;

  int key = keyChar - 48;

  /* -------- Parameter Selection -------- */
  if (key == 49) { IT = 1; x = 2; S = 0; previousMillis = currentMillis; } // Oxygen
  if (key == 50) { IT = 2; x = 2; S = 0; previousMillis = currentMillis; } // MP
  if (key == 51) { IT = 3; x = 2; S = 0; previousMillis = currentMillis; } // Rate
  if (key == 52) { IT = 4; x = 2; S = 0; previousMillis = currentMillis; } // Volume

  /* -------- Mode & Ratio -------- */
  if (key == 42) { VK_Mode++;  if (VK_Mode  > 4) VK_Mode  = 1; }
  if (key == 35) { VK_Ratio++; if (VK_Ratio > 3) VK_Ratio = 1; }

  /* -------- Oxygen Input -------- */
  if (IT == 1 && key >= 0 && key <= 9)
  {
    S = S + 1 + key * pow(10, x);
    S = (S / 10) * 10;
    x--;
    VK_Oxygen = S / 10;

    if (VK_Oxygen < 21)  VK_Oxygen = 21;
    if (VK_Oxygen > 100) VK_Oxygen = 100;

    previousMillis = currentMillis;
  }

  /* -------- Pressure Input -------- */
  if (IT == 2 && key >= 0 && key <= 9)
  {
    S = S + 1 + key * pow(10, x);
    S = (S / 10) * 10;
    x--;
    VK_MP = S / 10;

    if (VK_MP < 10) VK_MP = 10;
    if (VK_MP > 37) VK_MP = 37;

    previousMillis = currentMillis;
  }

  /* -------- Rate Input -------- */
  if (IT == 3 && key >= 0 && key <= 9)
  {
    S = S + 1 + key * pow(10, x);
    S = (S / 10) * 10;
    x--;
    VK_Rate = S / 10;

    if (VK_Rate < 10) VK_Rate = 10;
    if (VK_Rate > 30) VK_Rate = 30;

    previousMillis = currentMillis;
  }

  /* -------- Volume Input -------- */
  if (IT == 4 && key >= 0 && key <= 9)
  {
    S = S + 1 + key * pow(10, x);
    S = (S / 10) * 10;
    x--;
    VK_Volume = S;

    if (VK_Volume < 270) VK_Volume = 270;
    if (VK_Volume > 800) VK_Volume = 800;

    previousMillis = currentMillis;
  }

  /* -------- Input Timeout -------- */
  if (currentMillis - previousMillis >= 1500)
  {
    IT = 0;
    x  = 2;
    S  = 0;
  }
}
