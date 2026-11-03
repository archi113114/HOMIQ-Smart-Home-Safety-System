# HOMIQ – ESP32 Smart Home Safety System

## Project Overview
HOMIQ is an ESP32-based smart home safety project developed and simulated using Wokwi.

## Features
- Smoke and gas detection using the MQ-2 sensor
- Fire detection using a flame sensor
- Buzzer alert when danger is detected
- Relay-based light and fan control
- Safety status monitoring

## Components
- ESP32
- MQ-2 sensor
- Flame sensor
- Buzzer
- Relay module

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




## Testing
The project has been tested in the Wokwi simulation environment. Hardware testing should be documented separately.

## Author
Archita Singh
