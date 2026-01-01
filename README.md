# EEV20.1 - Emergency Electronic Ventilator
**Developed for i-Hub | COVID-19 Emergency Response**

[![Hardware](https://img.shields.io/badge/MCU-ATmega128A-blue.svg)](https://www.microchip.com/en-us/product/ATmega128A)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![3D Model](https://img.shields.io/badge/3D%20View-GLB-orange)](path/to/your/model.glb)

The **EEV20.1** is an open-source mechanical ventilator designed to assist in the global shortage of respiratory support devices during the COVID-19 pandemic. This system utilizes a stepper-motor-driven mechanism controlled by an **ATmega128A** to deliver precise tidal volumes and respiratory rates.

---

## 📐 Interactive 3D Model

Click the image below to open the **interactive 3D viewer**. You can rotate, zoom, and inspect the ventilator mechanism directly in your browser.

[![Click to Interact](https://via.placeholder.com/800x400?text=Click+Here+to+View+Interactive+3D+Model)](./path/to/your/model.glb)

> **Note:** The master CAD source files are located in the `mechanics/` directory.

---

## 📂 Firmware Architecture

The firmware is designed for safety and modularity using a Finite State Machine (FSM) architecture.

```text
Ventilation_Firmware_ATmega128A/
├── app/          # Finite State Machine (Ventilation Modes)
├── control/      # Motor Speed/Position Profiles (Stepper Logic)
├── logic/        # Respiratory Calculations (Tidal Vol, I:E, BPM)
├── safety/       # Critical Alarms & Failsafes
├── ui/           # LCD Menu System
└── drivers/      # Hardware Abstraction (Timer1, ADC, GPIO)
