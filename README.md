# HOMIQ – ESP32 Smart Home Safety System

## Project Overview
HOMIQ is an ESP32-based smart home safety project developed and simulated using Wokwi.

## Features
- Smoke and gas detection using the MQ-2 sensor
- Fire detection using a flame sensor
- Buzzer alert when danger is detected
- Relay-based light and fan control
- Safety status monitoring


## Hardware Components and ESP32 Pin Connections

### 1. Component Connection Table

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

### 2. Real Hardware Sensor Connections

| Component | Component Pin | ESP32 Connection |
|---|---|---|
| Flame Sensor | VCC | 3V3 |
| Flame Sensor | GND | GND |
| Flame Sensor | AO | GPIO 34 |

### 3. Output Devices

| Output Device | Relay Channel |
|---|---|
| 5V DC Light Bulb | Relay Channel 1 (IN1) |
| 5V DC Cooling Fan | Relay Channel 2 (IN2) |

**Note:** GPIO connections describe the control-side wiring. Relay load-side terminal connections must be verified separately. MQ-2 D0 must not exceed the ESP32 GPIO input limit of 3.3V; use a suitable level shifter or voltage divider if its output is 5V. Do not power the loads directly from ESP32 GPIO pins.


## Blynk IoT Configuration

The Blynk IoT platform is used for remote appliance control, safety monitoring and alert notifications.

| Virtual Pin | Datastream Name | Data Type | Function |
|---|---|---|---|
| V0 | Light Control | Integer (0/1) | Controls the light through the relay module. |
| V1 | Fan Control | Integer (0/1) | Controls the fan through the relay module. |
| V2 | Safety Status | String | Displays the current safety condition. |

### Notification Event

| Event Name | Event Code | Purpose |
|---|---|---|
| Fire Smoke Alert | `fire_smoke_alert` | Sends a push notification when smoke or fire is detected. |


## Project Files
- `sketch.ino` – Main Arduino simulation code
- `diagram.json` – Circuit configuration
- `libraries.txt` – Required libraries

 ## Working Principle

1. The MQ-2 sensor detects smoke and gas.
2. The flame sensor detects fire.
3. When smoke or fire is detected, the ESP32 activates the buzzer.
4. The relay module turns OFF the connected light and fan.
5. The safety status is updated in the Blynk application.
6. A push notification is sent when danger is detected.
7. When the environment becomes safe, the system returns to normal operation.

## Wokwi Simulation
**Project link:**[Open HOMIQ Wokwi Simulation](https://wokwi.com/projects/473805755748792321)

## Project Images


### Wokwi Simulation
![HOMIQ Wokwi Simulation](images/wokwi%20simulation.png.png)

### Hardware Prototype
![HOMIQ Hardware Prototype](images/HOMIQ%20Smart%20Home%20Safety%20Prototype.png)


**PROJECT PPT LINK :**[ Take a look ](https://docs.google.com/presentation/d/1RDyi6VGtCwIQhXVjRRvC7lH809DfLNZZ/edit?usp=sharing&ouid=115488542656342462056&rtpof=true&sd=true)





## Testing and Results

### Wokwi Simulation Testing

The HOMIQ system was tested in the Wokwi simulation environment.

| Test Case | Expected Result | Status |
|---|---|---|
| Normal condition | System displays Normal - Safe | Passed |
| Smoke detection | Buzzer ON and relay outputs OFF | Passed |
| Fire detection | Buzzer ON and relay outputs OFF | Passed |
| Light control through Blynk | Light responds to app control | Passed |
| Fan control through Blynk | Fan responds to app control | Passed |
| Safety status monitoring | Status displayed in Blynk | Passed |
| Push notification | Alert notification received | Passed |
| Return to safe condition | System restores normal operation | Passed |


## Limitations

- **Simulation-Based Validation:** The current implementation has been primarily developed and validated in the Wokwi simulation environment. Complete physical hardware validation is pending.
- **Sensor Dependency:** Detection accuracy depends on sensor sensitivity, calibration, placement, and surrounding environmental conditions.
- **Connectivity Requirement:** Blynk-based remote monitoring and notifications require a stable internet connection.
- **Prototype Scope:** HOMIQ is an academic prototype and is not certified for use as an independent life-safety or fire protection system.

## Future Scope

- **Hardware Implementation:** Complete the physical prototype and perform systematic testing under controlled conditions.
- **Enhanced Detection:** Incorporate improved sensor calibration and detection mechanisms to minimize false alarms.
- **Real-Time Monitoring:** Introduce sensor data logging and historical monitoring through the Blynk dashboard.
- **Advanced Connectivity:** Explore additional communication technologies for improved reliability and remote accessibility.
- **System Expansion:** Integrate additional safety sensors, such as temperature, LPG leakage, and water leakage sensors.
- **Scalability:** Extend the platform to support multiple rooms and additional smart home appliances.



## Author
Archita Singh
