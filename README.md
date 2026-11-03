
# 🏠 HOMIQ – ESP32 Smart Home Safety System

> 🔐 An ESP32-based smart home safety system combining smoke and fire detection, relay-controlled appliance automation, and Blynk IoT integration for remote monitoring and mobile alerts.

## 📌 Project Overview

HOMIQ is an ESP32-based smart home safety project developed and simulated using Wokwi. It integrates sensors, automated alerts, relay-based appliance control, and IoT-based monitoring to enhance home safety.

## ✨ Features

- 🌫️ Smoke and combustible gas detection using the MQ-2 sensor.
- 🔥 Flame detection using a flame sensor.
- 🔔 Automatic buzzer alert during detected danger conditions.
- 💡 Relay-based light and fan control.
- 📱 Remote appliance control through the Blynk IoT application.
- 📊 Real-time safety status monitoring.
- 🔔 Mobile push notifications for smoke and fire alerts.
- 🔄 Automatic return to normal operation when the danger condition clears.

## 🔌 Hardware Components and ESP32 Pin Connections

### 1. 🔗 Component Connection Table

| Component | Component Pin | ESP32 Connection |
|---|---|---|
| MQ-2 Sensor | VCC | VIN / 5V |
| MQ-2 Sensor | GND | GND |
| MQ-2 Sensor | D0 | GPIO 27 |
| Flame Sensor (Wokwi) | VCC | 3V3 |
| Flame Sensor (Wokwi) | GND | GND |
| Flame Sensor (Wokwi) | DO | GPIO 33 |
| Buzzer | Signal (+) | GPIO 14 |
| Buzzer | GND (-) | GND |
| Relay Module | VCC | VIN / 5V |
| Relay Module | GND | GND |
| Relay Module | IN1 (Light) | GPIO 26 |
| Relay Module | IN2 (Fan) | GPIO 25 |

### 2. 🛠️ Real Hardware Sensor Connections

| Component | Component Pin | ESP32 Connection |
|---|---|---|
| Flame Sensor | VCC | 3V3 |
| Flame Sensor | GND | GND |
| Flame Sensor | AO | GPIO 34 |

### 3. ⚡ Output Devices

| Output Device | Relay Channel |
|---|---|
| 💡 5V DC Light Bulb | Relay Channel 1 (IN1) |
| 🌀 5V DC Cooling Fan | Relay Channel 2 (IN2) |

**⚠️ Important Notes:**
- GPIO connections describe the control-side wiring. Relay load-side terminal connections must be verified separately.
- MQ-2 D0 must not exceed the ESP32 GPIO input limit of 3.3V. Use a suitable level shifter or voltage divider if its output is 5V.
- Do not power the connected loads directly from ESP32 GPIO pins.

## 📱 Blynk IoT Configuration

The Blynk IoT platform is used for remote appliance control, safety monitoring, and alert notifications.

| Virtual Pin | Datastream Name | Data Type | Function |
|---|---|---|---|
| V0 | 💡 Light Control | Integer (0/1) | Controls the light through the relay module. |
| V1 | 🌀 Fan Control | Integer (0/1) | Controls the fan through the relay module. |
| V2 | 🛡️ Safety Status | String | Displays the current safety condition. |

### 🔔 Notification Event

| Event Name | Event Code | Purpose |
|---|---|---|
| Fire Smoke Alert | `fire_smoke_alert` | Sends a push notification when smoke or fire is detected. |

## 📂 Project Files

- 🧪 [Wokwi Simulation Files](Simulation/)
- 🔌 [Physical Hardware Arduino IDE Code](Hardware/HOMIQ_Hardware.ino)
## ⚙️ Working Principle

1. 🌫️ The MQ-2 sensor detects smoke and gas.
2. 🔥 The flame sensor detects fire.
3. 🔔 When smoke or fire is detected, the ESP32 activates the buzzer.
4. ⚡ The relay module turns OFF the connected light and fan.
5. 📱 The safety status is updated in the Blynk application.
6. 🚨 A push notification is sent when danger is detected.
7. 🔄 When the environment becomes safe, the system returns to normal operation.

## 🖼️ Project Gallery

### 💻 Wokwi Circuit Simulation

![HOMIQ Wokwi Simulation](images/wokwi%20simulation.png.png)

### 🏠 Hardware Prototype

![HOMIQ Hardware Prototype](images/HOMIQ%20Smart%20Home%20Safety%20Prototype.png)

## 🔗 Project Resources

- 🔬 [Wokwi Simulation](https://wokwi.com/projects/473805755748792321)
- 📊 [Project Presentation (PPT)](https://docs.google.com/presentation/d/1RDyi6VGtCwIQhXVjRRvC7lH809DfLNZZ/edit)

## 🧪 Testing & Results

### 💻 Wokwi Simulation Testing

The system was simulated and tested using Wokwi to verify its detection, alert, relay control, and Blynk integration functionalities.

| Test Case | Result |
|---|---|
| 🌫️ Smoke and gas detection | ✅ Passed |
| 🔥 Flame detection | ✅ Passed |
| 🔔 Buzzer alert | ✅ Passed |
| 💡 Light and fan relay control | ✅ Passed |
| 📱 Blynk status monitoring | ✅ Passed |
| 🚨 Mobile push notifications | ✅ Passed |
| 🔄 Return to normal operation | ✅ Passed |

### 🔧 Physical Hardware Testing

The physical HOMIQ prototype was assembled and tested using an ESP32, MQ-2 sensor, flame sensor, buzzer, relay module, 5V DC light bulb, and cooling fan. Testing was performed to evaluate sensor detection, buzzer alerts, and relay-based appliance control.

## ⚠️ Limitations & 🚀 Future Enhancements

### ⚠️ Limitations

- Sensor accuracy may vary depending on calibration and environmental conditions.
- Remote monitoring and notifications require a stable internet connection.
- The prototype is designed for academic demonstration and is not a certified fire safety system.

### 🚀 Future Enhancements

- 🎯 Improve sensor calibration and detection reliability.
- 📈 Introduce sensor data logging and historical monitoring.
- 🛡️ Integrate additional smart home safety sensors.
- 🏘️ Expand support for multiple rooms and appliances.
- 📡 Enhance remote monitoring and automation capabilities.

## 👩‍💻 Author

**Archita Singh**
