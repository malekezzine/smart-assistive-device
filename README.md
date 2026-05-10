# Smart Assistive Device for Visually Impaired Users
### Lunettes Intelligentes d'Assistance

An Arduino-based assistive device designed as smart glasses to help blind and visually impaired users detect head-level obstacles in real time and alert them through audio and haptic feedback — without the use of cameras, ensuring full privacy.

> Developed by **Ezzine Malek**  
> IT Business School — Academic Year 2025–2026  
> Supervisor: Mme Gabsi Ines

---

## Problem Statement

Traditional mobility aids like the white cane fail to detect obstacles at head level (signs, branches, open doors). Existing camera-based solutions are expensive, energy-intensive, and raise privacy concerns. This project addresses that gap with a simple, affordable, and privacy-respecting alternative.

---

## Proposed Solution

Smart glasses integrating an HC-SR04 ultrasonic sensor for real-time obstacle detection, processed by an Arduino Nano, with a progressive dual-alert system (audio + haptic) based on distance thresholds.

---

## Technologies Used

- Arduino Nano (ATmega328P)
- C/C++ — Arduino IDE
- HC-SR04 Ultrasonic Sensor
- Active Buzzer
- Vibrating Motor
- NPN Transistor 2N2222
- Li-on Battery 3.7V 4800mAh
- Proteus (circuit simulation)
- Fritzing (wiring diagrams)

---

## Components

| Component | Role |
|-----------|------|
| Arduino Nano | Main controller — data processing |
| HC-SR04 Sensor | Real-time obstacle detection (2–400cm) |
| Active Buzzer | Progressive audio alert |
| Vibrating Motor | Haptic feedback alert |
| NPN Transistor 2N2222 | Electronic switch for motor control |
| Resistor R1 (220Ω) | Current limiter for transistor base |
| Freewheeling Diode D1 | Protection against inductive voltage spikes |
| Li-on Battery 3.7V 4800mAh | Autonomous portable power supply |
| ON/OFF Switch | Power control |

---

## Circuit Architecture

The system is distributed across two breadboards:

**Board 1 — Control & Power Unit:**
Arduino Nano + Buzzer + Switch + Li-on Battery

**Board 2 — Vibrating Motor Control Circuit:**
Transistor 2N2222 + Resistor 220Ω + Freewheeling Diode D1

---

## How It Works

### Distance Calculation
The HC-SR04 sensor emits an ultrasonic pulse every few milliseconds.
The Arduino calculates the distance using:

```
distance = (duration × 0.034) / 2
```

Where `duration` is the echo return time in microseconds.

### Pin Mapping

| Pin | Component | Direction |
|-----|-----------|-----------|
| D2 | HC-SR04 Trigger | OUTPUT |
| D3 | HC-SR04 Echo | INPUT |
| D4 | Buzzer | OUTPUT |
| D5 | Vibrating Motor (via transistor) | OUTPUT |

### Progressive Alert System

| Distance | Buzzer | Vibrating Motor |
|----------|--------|-----------------|
| > 100 cm | Silent | OFF |
| 50–100 cm | Slow beeping (600ms interval) | OFF |
| 10–50 cm | Fast beeping (50ms interval) | ON |
| < 10 cm | Very fast beeping | ON (strong) |

The `map()` function converts distance (10–100cm) to beep delay (50–600ms) proportionally.

### System Flow
1. Battery powers the Arduino Nano via the ON/OFF switch
2. HC-SR04 measures distance every ~100ms
3. Arduino processes the reading with progressive threshold logic
4. If obstacle < 100cm → buzzer activates with proportional beep speed
5. If obstacle < 50cm → vibrating motor activates via transistor 2N2222
6. Alerts stop when obstacle moves away

---

## Code Structure

The Arduino code is structured in 4 main parts:

1. **Pin & Variable Declaration** — defines trigPin, echoPin, buzzerPin, motorPin
2. **setup()** — configures pin modes, initializes actuators to LOW, starts Serial monitor
3. **getDistanceCm()** — sends ultrasonic pulse, measures echo duration, converts to cm
4. **loop()** — continuously calls distance measurement, triggers alerts based on thresholds

### Native Libraries Used

| Library | Usage |
|---------|-------|
| `Arduino.h` | Core functions: pinMode, digitalWrite, delay |
| `tone() / noTone()` | Buzzer control at 2000 Hz |
| `pulseIn()` | Measures HC-SR04 echo pulse duration |
| `map()` | Maps distance to proportional beep delay |
| `Serial` | Real-time distance display for debugging |

---

## How to Run

1. Wire the components according to the circuit diagram
2. Open the `.ino` file in **Arduino IDE**
3. Select board: **Arduino Nano**
4. Select processor: **ATmega328P**
5. Select the correct COM port
6. Click **Upload**
7. Open Serial Monitor (9600 baud) to view real-time distance readings

---

## Key Advantages

- No camera — fully respects user privacy
- Low cost — uses standard components available on the Tunisian market
- Lightweight and portable — Arduino Nano's compact size
- No learning curve — simple ON/OFF switch operation
- Low power consumption — extended battery life for daily use

---

## Future Improvements

- Multiple sensors for 180° lateral + frontal coverage
- Voice alerts via audio module for directional guidance
- Bluetooth connectivity with smartphone app for GPS and emergency calls
- USB recharging module and smart power management
- Custom PCB to replace breadboards for miniaturization
- Embedded AI for obstacle classification and trajectory prediction

---

## Screenshots

### Device Prototype
![Prototype](screenshots/prototype.png)

### Circuit Simulation (Proteus)
![Proteus Simulation](screenshots/diagramme.png)

---

## Authors

- **Ezzine Malek** 

IT Business School, Nabeul — 2025–2026
