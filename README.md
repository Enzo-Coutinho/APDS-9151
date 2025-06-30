# APDS-9151 Color & Proximity Sensor for ESP32

This is a C/C++ firmware project for an ESP32 microcontroller that reads color (RGB + IR) and proximity data using the Broadcom **APDS-9151** sensor via I²C. The project supports both ESP‑IDF and Arduino frameworks and is developed using PlatformIO.

---

## 🎯 Overview

- **Supported frameworks**: ESP‑IDF 5.4.1 and Arduino-ESP32 3.2.0
- **Build system**: PlatformIO
- **Sensor**: Broadcom APDS‑9151 (RGB + IR + proximity)
- **Objective**: Provide a portable, robust foundation for color/proximity sensing with ESP32

---

## ⚙️ Key Features

1. **I²C Initialization**: Configurable gain, integration time, and flicker suppression
2. **Continuous Non‑blocking Reads**: Retrieves raw R/G/B/IR channel values
3. **Dual‑framework Portability**: Compile with ESP‑IDF or Arduino using PlatformIO

---

## 🧪 Usage Example: REV Robotics Color Sensor V3

This project can be used with the **REV Robotics Color Sensor V3** (REV-31-1557), which is built around the APDS‑9151 chip. The V3 sensor:

- Measures Red, Green, Blue, Alpha (clear), and proximity
- Includes a built-in white LED (switchable)
- Supports standard (100 kHz) and high-speed (400 kHz) I²C
- Optimized for robotics applications, particularly in FIRST Robotics competitions

**Real-world use-cases include**:

- Robot vision tasks (detecting colored objects)
