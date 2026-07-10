# 📡 ESP32 Ultrasonic Sensor with UART Communication

An embedded systems project that measures distance using an HC-SR04 ultrasonic sensor connected to an ESP32 and transmits detection events to a PIC microcontroller through UART serial communication.

This project demonstrates sensor integration, real-time distance measurement, and communication between two microcontrollers.

---

## 📖 Overview

The ESP32 continuously measures the distance to nearby objects using an ultrasonic sensor.

When an object is detected within the configured threshold, the ESP32 sends a command through UART to a PIC microcontroller. The PIC can then perform any required action such as activating outputs, alarms, or actuators.

---

## ✨ Features

- Distance measurement using HC-SR04
- UART communication between ESP32 and PIC
- Real-time obstacle detection
- Serial monitoring for debugging
- Embedded C++ programming

---

## 🛠 Hardware

| Component | Description |
|-----------|-------------|
| ESP32 | Main microcontroller |
| HC-SR04 | Ultrasonic distance sensor |
| PIC Microcontroller | External controller |
| UART Interface | Serial communication |
| Voltage Divider | ESP32 RX protection |

---

## 💻 Software

- Arduino IDE
- Arduino C++
- ESP32 Core
- Embedded Systems Programming

---

## ⚙ System Operation

1. Measure the distance using the HC-SR04 sensor.
2. Calculate the distance in centimeters.
3. Compare the measured distance against the configured threshold.
4. Send `'1'` through UART when an object is detected.
5. Send `'0'` when no object is detected.
6. Receive and display responses from the PIC microcontroller.

---

## 🔄 Communication Flow

```text
        HC-SR04
           │
           ▼
      Measure Distance
           │
           ▼
         ESP32
           │
        UART TX/RX
           │
           ▼
  PIC Microcontroller
           │
           ▼
      External Device
```

---

## 📂 Repository Structure

```text
esp32-ultrasonic-pic-uart
│
├── src
│   └── Esp_ultrasonido.ino
│
├── docs
│
├── images
│
├── LICENSE
│
└── README.md
```

---

## 📌 Pin Configuration

### HC-SR04

| Signal | ESP32 Pin |
|---------|----------:|
| Trigger | GPIO 5 |
| Echo | GPIO 18 |

### UART

| Signal | ESP32 Pin |
|---------|----------:|
| RX | GPIO 16 |
| TX | GPIO 17 |

---

## 🧠 Algorithm

```text
Start
   │
   ▼
Read Distance
   │
   ▼
Distance < Threshold?
   │
 ├── Yes
 │      │
 │      ▼
 │ Send '1'
 │
 └── No
        │
        ▼
      Send '0'
        │
        ▼
Read PIC Response
        │
        ▼
Repeat
```

---

## 🚀 Skills Demonstrated

- Embedded Systems
- ESP32 Programming
- Arduino C++
- UART Communication
- Serial Communication
- Sensor Integration
- HC-SR04
- Real-Time Programming
- Microcontroller Communication
- Hardware Integration

---

## 🔮 Future Improvements

- Interrupt-driven UART communication
- FreeRTOS task implementation
- Non-blocking ultrasonic measurements
- Configurable detection threshold
- OLED display integration
- Wi-Fi monitoring
- MQTT communication
