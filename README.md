# Intelligent Gas Leak Detection and Prevention System

## Description

This project is designed to develop an intelligent system that detects flammable gas leaks and responds automatically to enhance safety. It is based on the **ESP32 microcontroller**, integrates with the **Blynk IoT platform** for real-time notifications, and includes an **automated ventilation system** controlled via a transistor.

## Features

- 🔥 **Gas Leak Detection** using a gas sensor (e.g., MQ-2/MQ-135)
- 📲 **Real-time alerts** sent to a mobile app via **Blynk**
- 🌬️ **Automatic activation of a fan** using a transistor for ventilation
- 💡 User-friendly mobile interface for monitoring
- 🔌 Based on the **ESP32** microcontroller
- 📅 Project completed in **August 2023**

## Technologies Used

- **ESP32**
- **Blynk IoT Platform**
- **Arduino IDE**
- **Gas Sensor (MQ-series)**
- **Transistor (for fan control)**
- **Mobile App (Blynk)**

## Schematic Overview
you will faind everything at the presenattion

## How It Works

1. The gas sensor continuously monitors air quality.
2. If a gas concentration threshold is exceeded:
   - A notification is sent to the user's smartphone via Blynk.
   - The system automatically powers on a fan using a transistor to ventilate the area.
3. The user can also monitor the system status in real-time through the mobile app.

## Installation & Usage

1. Upload the Arduino code to your ESP32 using Arduino IDE.
2. Connect the gas sensor and fan circuit as per the schematic.
3. Set up your Blynk project and configure authentication tokens.
4. Power on the device and monitor gas levels from the Blynk app.

## Author

👨‍💻 Developed by a second-year engineering student at **INPT (Institut National des Postes et Télécommunications)**, passionate about embedded systems and IoT.

---

Feel free to modify or add additional sections like `License`, `Acknowledgements`, or `Contributing` based on your needs.
