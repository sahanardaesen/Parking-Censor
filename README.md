# 🚗 Smart Ultrasonic Parking Sensor System

A professional-grade Arduino project that simulates a real-world vehicle parking assistance system. This project uses an **HC-SR04** ultrasonic sensor to measure distance and provides multi-layered feedback via an **I2C LCD**, **RGB LED**, and a **Dynamic Buzzer** algorithm.

---

## 🚀 Key Features

* **Dynamic Alert Logic:** The buzzer's frequency and pulse duration change proportionally as the object gets closer, mimicking high-end automotive sensors.
* **Visual Interface:** Real-time distance data is displayed on a 16x2 I2C LCD screen with automated buffer clearing to prevent character ghosting.
* **LED Color Status:**
    * 🔴 **Red (Stop):** Critical proximity (<20cm).
    * 🟡 **Yellow (Caution):** Approaching obstacle (20cm - 50cm).
    * 🟢 **Green (Clear):** Path is clear (>50cm).
    * 🔵 **Blue (Error):** System is **Out of Limits**. This alerts the user to sensor blind spots (closer than 2cm) or distances beyond the reliable range (greater than 330cm).

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno (or compatible)
* **Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Display:** 16x2 LCD with I2C Module (0x27)
* **Output:** Common Cathode RGB LED & Active Piezo Buzzer

---

## 📋 Connection Diagram

| Component | Arduino Pin |
| :--- | :--- |
| **HC-SR04 Trig** | Pin 9 |
| **HC-SR04 Echo** | Pin 10 |
| **RGB Red** | Pin 3 (PWM) |
| **RGB Green** | Pin 5 (PWM) |
| **RGB Blue** | Pin 6 (PWM) |
| **Buzzer** | Pin 11 (PWM) |
| **LCD SDA** | Pin A4 |
| **LCD SCL** | Pin A5 |

---

<img width="632" height="565" alt="image" src="https://github.com/user-attachments/assets/4bd4b499-e0f2-4f58-bed1-2defc547a345" />

---

<img width="906" height="699" alt="image" src="https://github.com/user-attachments/assets/c2429feb-7f85-4e14-a02e-622f6ed1d73b" />

---

<img width="1791" height="345" alt="image" src="https://github.com/user-attachments/assets/fd49db0d-f8c8-478c-a148-5e88249bb0e1" />

---
