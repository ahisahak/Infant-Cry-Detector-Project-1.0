# 👶 Infant Cry Detection with ESP32 and MQTT

This project implements an IoT-based **Infant Cry Detector** using an **ESP32**, a **sound sensor**, and **MQTT** for remote notification. When the system detects crying (based on sound threshold), it turns on an LED and publishes a message to an MQTT topic.

---

## 🛠️ Features

- 📶 Connects ESP32 to Wi-Fi and an MQTT broker
- 🎤 Detects loud sounds via a sound sensor or analog input
- 💡 Turns on an LED indicator when crying is detected
- 📤 Publishes "Cry Detected" messages to an MQTT topic

---

## 🔌 Hardware Requirements

- ESP32 board
- Sound sensor (e.g., analog microphone or potentiometer for simulation)
- LED + resistor
- Jumper wires and breadboard
- Internet connection

---

## 🔧 Configuration

### Wi-Fi Credentials
Update the following in the sketch:

```cpp
const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";
