# EEV20.1 - Emergency Electronic Ventilator
**Developed for i-Hub | COVID-19 Emergency Response**

[![Hardware](https://img.shields.io/badge/MCU-ATmega128A-blue.svg)](https://www.microchip.com/en-us/product/ATmega128A)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![3D Model](https://img.shields.io/badge/3D%20View-GLB-orange)](path/to/your/model.glb)

The **EEV20.1** is an open-source mechanical ventilator designed to assist in the global shortage of respiratory support devices during the COVID-19 pandemic. This system utilizes a stepper-motor-driven mechanism controlled by an **ATmega128A** to deliver precise tidal volumes and respiratory rates.

---

## 📐 Interactive 3D Model
<div align="center">
  <h3>Mechanical Explosion View (Assembly Sequence)</h3>
  <video src="product_vision.mp4" width="100%" muted autoplay loop playsinline>
    Your browser does not support the video tag.
  </video>
  <p align="right">
    <i>Click the video for playback controls or <a href="./Product_vision.glb">view the 3D model here</a>.</i>
  </p>
</div>
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
```

🔌 Hardware Specifications
```text
MCU: Microchip ATmega128A (8-bit AVR)

Actuation: High-torque NEMA Stepper Motor

Driver: Industrial Stepper Driver (DIR/PUL Interface)

Sensors: Flow & Pressure Differential Sensors

User Interface: 20x4 Character LCD + Rotary Encoder
```
🚀 Build & Flash
Prerequisites
```text
Microchip Studio (formerly Atmel Studio) or PlatformIO.

AVR-GCC Toolchain.
```
Compilation
Clone the repository:

```Bash

git clone [https://github.com/Abdelrahman-Elnahrawy/EEV20.1.git](https://github.com/Abdelrahman-Elnahrawy/EEV20.1.git)
```
Open the solution file.

Build for Release to enable compiler optimizations.

Flash via ISP (USBasp or AVRISP mkII).

⚠️ Medical Disclaimer
This device is an emergency prototype. It is intended for research and educational purposes in the context of critical supply shortages. It has not been certified by any organization for clinical use on human patients without further validation.

🤝 Contributors
Abdelrahman Elnahrawy 

### 🛑 Critical Step: Fix the Link
In the code above, look for this line:

`[![Click to Interact](...)] (./path/to/your/model.glb)`

You **must** change `./path/to/your/model.glb` to the actual location of your file.
* **Example:** If your file is named `ventilator.glb` and is in the main folder, change it to `./ventilator.glb`.
* **Example:** If it is inside a folder named `cad`, change it to `./cad/ventilator.glb`.
