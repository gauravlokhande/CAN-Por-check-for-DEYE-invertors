# 🚗 ESP32 CAN Communication using TWAI Driver (TJA1050 Transceiver)

This project demonstrates how to transmit CAN frames using an ESP32 and a TJA1050 CAN transceiver module via the built-in TWAI (Two-Wire Automotive Interface) driver.

## 📋 Features

- Uses ESP32's internal TWAI peripheral (CAN 2.0)
- Communicates over standard 11-bit CAN ID (0x351)
- Sends 8-byte data frames at 500 kbps
- Fully compatible with common CAN transceivers like TJA1050
- Clean and modular code structure for easy integration
- Serial output for debugging and validation

## 🔧 Hardware Used

- ESP32 WROOM-32E
- TJA1050 CAN Transceiver Module
- CAN analyzer (e.g. Waveshare CAN to USB/RS485) – optional for monitoring
- 120Ω termination resistor across CAN_H and CAN_L if bus length > 1 meter

## 🧪 Setup

1. Wire ESP32 to TJA1050 module:

| ESP32 GPIO | TJA1050 Pin     |
|------------|-----------------|
| GPIO5      | TXD (Transmit)  |
| GPIO4      | RXD (Receive)   |
| 3.3V       | VCC             |
| GND        | GND             |

2. Connect CAN_H and CAN_L to another CAN node or CAN analyzer.

3. Flash the code using Arduino IDE.

## 📦 Library / Tools

- Arduino Core for ESP32 (v2.0+)
- Uses native driver: `driver/twai.h`

## 📁 File Structure

- `main.ino` – main source file with CAN initialization and transmission
- `README.md` – project documentation

## 🧰 How It Works

- Initializes the TWAI peripheral with 500 kbps baud rate
- Sends a standard CAN frame with ID 0x351 and 8 bytes of hex data
- Prints TX status and payload to Serial Monitor for verification
- Can be extended to support message reception or loopback testing

## 🧠 Learnings & Highlights

- Working with low-level ESP32 TWAI driver
- Understanding CAN framing, DLC, and compliance flags
- Debugging with serial print and external CAN analyzers
- Integrating embedded C logic with real-time bus protocols

## 🧑‍💻 Author

Gaurav Lokhande  
Embedded Systems Engineer | Pune, India  
