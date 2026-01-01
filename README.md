
# EEV20.1 – Emergency Electronic Ventilator

<p align="center">
  <img src="docs/eev20_1_model.gif" alt="EEV20.1 3D Model" width="600"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Status-Prototype-orange"/>
  <img src="https://img.shields.io/badge/MCU-ATmega128A-blue"/>
  <img src="https://img.shields.io/badge/Focus-Embedded%20%26%20Mechatronics-success"/>
  <img src="https://img.shields.io/badge/License-MIT-green"/>
</p>
</p>

---

## 📌 Overview

**EEV20.1** is an **Emergency Electronic Ventilator prototype** developed as an open-source engineering project.  
The goal of this project is to demonstrate a **complete ventilator system design**, including:

- Mechanical structure
- Pneumatic system
- Embedded firmware
- Control logic
- Documentation & 3D visualization

> ⚠️ **Disclaimer:**  
> This project is intended **for educational, research, and prototyping purposes only**.  
> It is **NOT a certified medical device** and must not be used for real patients without proper medical approvals.

---

## 🎥 3D Model Preview

The following GIF shows the **actual 3D model** included in this repository:

<p align="center">
  <img src="/Product_vision.gif" alt="EEV20.1 3D Model" width="600"/>
</p>

The original 3D assets are available in **GLB format** inside the `docs/` directory.

---
🖼️ Circuit Diagram
<p align="center"><img src="Pneumatic_circuit.jpg" alt="EEV20.1 Pneumatic Circuit" width="700"/>

*Figure 2: Pneumatic schematic showing flow paths and control valves.*

### 🔍 Operational Principle / فكرة العمل

* **Mixing Phase (مرحلة الخلط):** Controlled by stepper motors, the Air and $O_2$ valves open to a specific ratio to achieve the target $FiO_2$.
* **Delivery Phase (مرحلة الضخ):** The mixture is pressurized and delivered to the patient through a regulated flow path.
* **Exhalation (الزفير):** The system manages the exhalation valve to maintain **PEEP** (Positive End-Expiratory Pressure) if required.

---

## 📂 Repository Structure / هيكل المشروع

```text
EEV20.1/
├── docs/                                # 3D model assets and viewer files
│   ├── Product_vision.glb
│   ├── Prototype.glb
│   └── eev20_1_model.gif
├── Ventilation_Firmware_ATmega128A/     # Embedded firmware for ATmega128A
│   ├── <firmware source files…>
│   └── README.md                        # Firmware‑specific readme
├── Hardware/                            # Hardware design files
│   ├── <schematics / PCB files…>
├── Documentation/                       # Manuals & project reports
│   ├── <PDF / docs…>
├── PCBs_Schematics.pdf                  # Board schematics PDF
├── Pneumatic_circuit.jpg                # Pneumatic design image
├── EEV 20 ventilator User manual.pdf     # Main user manual
└── README.md                            # Main project readme
```

## 🛠 System Components

### 🔌 Embedded System
- **Microcontroller:** ATmega128A
- **Language:** C (Bare-metal / AVR)
- **Architecture:** Modular & layered
- **Purpose:** Motor control, timing, safety logic, system states

### 🫁 Pneumatic System
- Pressure control
- Air flow regulation
- Safety relief mechanisms  
(see `Pneumatic_circuit.jpg`)

### 🧱 Mechanical Design
- Custom enclosure
- Motor-driven compression mechanism
- Designed for manufacturability & prototyping

---

## 📘 Documentation

Available documents include:

- **User Manual**
- **Pneumatic Circuit Diagram**
- **PCB & Electrical Schematics**
- **Project Reports & Presentations**

All documents are available directly in the repository as PDFs or inside the `Documentation/` folder.

---

## 💻 Firmware

The firmware source code is located in:

Ventilation_Firmware_ATmega128A/

yaml
Copy code

It includes:
- Low-level drivers
- Control logic
- Timing & safety handling
- Modular structure suitable for extension

📄 Please refer to the **README inside the firmware folder** for:
- Build instructions
- Code architecture
- Configuration details

---

## ⚠️ Safety Notice

- ❌ Not FDA / CE approved  
- ❌ Not clinically tested  
- ❌ Not intended for real medical use  

This project is shared **for learning and engineering demonstration only**.

---

## 📜 License

This project is licensed under the **MIT License**.

MIT License

Copyright (c) 2025 Abdelrahman Elnahrawy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files...

yaml
Copy code

---

## 👤 Author

**Abdelrahman Elnahrawy**  
Embedded Systems & Mechatronics Engineer  

🔗 GitHub:  
https://github.com/Abdelrahman-Elnahrawy

---

## ⭐ Acknowledgment

If this project helped you learn or inspired your work, consider starring the repository ⭐  
and sharing it with the engineering community.
