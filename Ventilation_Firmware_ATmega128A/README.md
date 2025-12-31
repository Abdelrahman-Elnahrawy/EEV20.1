# 🫁 Ventilation Machine Firmware (ATmega128A)
![License](https://img.shields.io/badge/License-MIT-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Platform](https://img.shields.io/badge/Platform-ATmega128A-orange)
![Build](https://img.shields.io/badge/Build-AVR--GCC-brightgreen)
![Status](https://img.shields.io/badge/Status-Prototype-yellow)
![Issues](https://img.shields.io/github/issues/yourusername/yourrepo)
![Stars](https://img.shields.io/github/stars/yourusername/yourrepo?style=social)

A modular, non-blocking firmware architecture for a microcontroller-based mechanical ventilation system, designed for **ATmega128A**.

This project focuses on **clean separation of concerns**, **safety**, and **real-time behavior**, making it suitable for research, academic, and prototype medical devices.

---

## 📌 Features

- ✅ Non-blocking architecture (millis / timers)
- ✅ Finite State Machine (FSM) control
- ✅ Safety & alarm layer (leakage detection)
- ✅ Stepper-based air & oxygen valve control
- ✅ LCD-based user interface (16x4)
- ✅ Expandable and RTOS-ready structure
- ✅ Medical-oriented design separation

---

## 🧠 System Architecture

The firmware is divided into clear functional layers:

UI (LCD)
│
FSM (Application Logic)
│
Control (Stepper / Valves)
│
Logic (Breathing Timing & Calculations)
│
Safety (Flow Validation & Alarms)
│
Drivers (LCD / Stepper)

yaml
Copy code

Each layer is **independent**, testable, and reusable.

---

## 📁 Folder Structure

Ventilation_Firmware_ATmega128A/
│
├── main.c
│
├── app/
│ ├── ventilation_fsm.h
│ ├── ventilation_fsm.c
│
├── control/
│ ├── ventilation_idle_stepper_control.h
│ ├── ventilation_idle_stepper_control.c
│
├── logic/
│ ├── ventilation_machine_calculations.h
│ ├── ventilation_machine_calculations.c
│
├── ui/
│ ├── ventilation_lcd.h
│ ├── ventilation_lcd.c
│
├── safety/
│ ├── ventilation_safety.h
│ ├── ventilation_safety.c
│
├── drivers/
│ ├── stepper_driver.h
│ ├── stepper_driver.c
│ ├── lcd_driver.h
│ ├── lcd_driver.c
│
├── config/
│ └── ventilation_config.h
│
└── README.md

yaml
Copy code

---

## ⚙️ Hardware Requirements

- **Microcontroller:** ATmega128A  
- **Display:** 16x4 LCD (HD44780 compatible)  
- **Actuators:** Stepper motors (Air & Oxygen idle valves)  
- **Sensors:**  
  - Air flow sensor  
  - Oxygen flow sensor  
- **Drivers:** ULN2003 / A4988 (or similar)

---

## 🔄 Finite State Machine (FSM)

The ventilation cycle is controlled using an FSM:

| State | Description |
|------|------------|
| INIT | System initialization |
| STANDBY | Idle state |
| INHALE | Active air & oxygen delivery |
| EXHALE | Passive exhalation |
| ALARM | Safety fault detected |

State transitions are **time-based and safety-driven**.

---

## 🛡️ Safety Mechanism

The safety layer continuously verifies:

Patient Flow ≈ Air Flow + Oxygen Flow

yaml
Copy code

If deviation exceeds ±5%:
- Alarm state is triggered
- Valve motion stops
- LCD shows leakage warning

---

## 🧮 Breathing Calculations

- Inhale / Exhale timing derived from:
  - Respiratory rate
  - I:E ratio
- All timing is **non-blocking**
- Ready for pressure-based termination upgrade

---

## 📺 User Interface (LCD)

The LCD displays:

- Maximum Pressure
- Oxygen %
- Respiratory Rate
- Tidal Volume
- I/E Ratio
- Ventilation Mode
- Alarm Messages

---

## 🔧 Stepper Control Logic

Stepper motors regulate:
- Air valve opening
- Oxygen valve opening

Control is based on:
- Required flow (calculated)
- Measured flow (sensor feedback)

> Structure is PID-ready (future upgrade).

---

## 🚀 How to Build

- Toolchain: **AVR-GCC**
- IDEs:
  - MPLAB X
  - Atmel Studio
  - PlatformIO

Compile and flash to ATmega128A using your preferred programmer.

---

## ⚠️ Disclaimer

> **This project is for educational and research purposes only.**  
>  
> The algorithms and calculations are **NOT medically certified** and **must not** be used in life-support systems without proper validation, certification, and regulatory approval.

---

## 👨‍💻 Author

**Abdelrahman Elnahrawy**  
Embedded Systems & R&D Engineer  

---

## 📜 License

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy  
of this software and associated documentation files (the "Software"), to deal  
in the Software without restriction.

---

## 🔮 Future Improvements

- PID-based flow control
- Pressure-triggered inhale termination
- EEPROM patient profiles
- FreeRTOS port
- MQTT / Telemetry support
- SD card data logging

---

⭐ If you find this project useful, feel free to star the repository.