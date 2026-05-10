# Smart Assistive Device for Visually Impaired Users

An Arduino-based assistive device designed to help visually 
impaired users navigate safely by detecting nearby obstacles 
in real time and alerting the user through audio and haptic feedback.

## Technologies Used
- Arduino Nano
- C/C++
- HC-SR04 Ultrasonic Sensor
- Buzzer
- Vibration Motor

## Components
| Component | Purpose |
|-----------|---------|
| Arduino Nano | Main controller |
| HC-SR04 Sensor | Obstacle detection |
| Buzzer | Audio alert |
| Vibration Motor | Haptic feedback |

## Features
- Real-time obstacle detection within 0–400cm range
- Dual-alert system with audio and haptic feedback
- Response time under 50ms
- 3-level alert intensity based on distance

## How It Works

The device uses an HC-SR04 ultrasonic sensor to continuously 
emit sound waves and measure the time it takes for them to 
bounce back from nearby obstacles.

### Distance Calculation
The sensor sends out an ultrasonic pulse every few milliseconds.
The Arduino calculates the distance using the formula:

distance = (duration × 0.034) / 2

Where duration is the time (in microseconds) for the sound 
wave to travel to the obstacle and return.

### Alert System
Based on the measured distance, the system reacts in 3 levels:

| Distance | Buzzer | Vibration Motor |
|----------|--------|-----------------|
| 0 – 50cm | Fast beeping | Strong vibration |
| 50 – 200cm | Slow beeping | Mild vibration |
| 200 – 400cm | No alert | No alert |

### Flow
1. Sensor measures distance every 100ms
2. Arduino processes the reading
3. If obstacle detected under 200cm, alerts activate
4. Alert intensity increases as obstacle gets closer
5. Alerts stop when obstacle moves away

## How to Run
1. Connect the components according to the circuit diagram
2. Open the `.ino` file in Arduino IDE
3. Select your board: **Arduino Nano**
4. Select the correct port
5. Click **Upload**

## Circuit Diagram
(Add circuit diagram image here)

## Screenshots
(Add photos of the device here)
## Screenshots
(Add photos of the device here)
