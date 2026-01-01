# EEV20.1 – Emergency Electronic Ventilator

![Status](https://img.shields.io/badge/Status-Prototype-orange)
![MCU](https://img.shields.io/badge/MCU-ATmega128A-blue)
![3D](https://img.shields.io/badge/3D-Interactive-success)
![License](https://img.shields.io/badge/License-MIT-green)
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
  <img src="docs/eev20_1_model.gif" alt="EEV20.1 Model Animation"/>
</p>

The original 3D assets are available in **GLB format** inside the `docs/` directory.

---

## 📂 Repository Structure

EEV20.1/
│
├── docs/ # 3D models & visualization
│ ├── eev20_1_model.gif
│ ├── Product_vision.glb
│ └── Prototype.glb
│
├── Ventilation_Firmware_ATmega128A/ # Embedded firmware (AVR)
│ └── README.md # Firmware-specific documentation
│
├── Hardware/ # Hardware & PCB designs
│
├── Documentation/ # Reports, manuals & references
│
├── PCBs_Schematics.pdf
├── Pneumatic_circuit.jpg
├── EEV 20 ventilator User manual.pdf
│
└── README.md # This file

yaml
Copy code

---

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
