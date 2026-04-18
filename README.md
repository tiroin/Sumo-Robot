# Sumo-Robot
🤖 Sumo Robot (Arduino)

Autonomous sumo robot using Arduino, designed for competitive robot sumo matches. The robot detects opponents and avoids leaving the arena using sensor-based decision logic.

🚀 Overview

This project implements a self-controlled sumo robot capable of:

Detecting opponents using sensors
Avoiding ring boundaries
Making real-time decisions to attack or retreat
Controlling motors for movement strategies

The system is built on Arduino platform, focusing on embedded control logic and real-time response.

⚙️ Features
🤖 Autonomous movement control
🎯 Opponent detection (e.g., IR / ultrasonic sensors)
⚠️ Edge detection to avoid falling out of the ring
🔄 Strategy switching (attack / search / escape)
⚡ Real-time motor control
🧠 System Logic

Basic behavior flow:
Start
  │
  ├── Detect opponent?
  │       ├── YES → Attack (move forward / push)
  │       └── NO  → Search (rotate / scan)
  │
  ├── Detect edge?
  │       ├── YES → Retreat / turn
  │       └── NO  → Continue
  │
  └── Loop continuously
  🛠️ Hardware Components
  | Component                        | Description         |
| -------------------------------- | ------------------- |
| Arduino (Uno/Nano/...)           | Main controller     |
| DC Motors                        | Robot movement      |
| Motor Driver (L298N / TB6612...) | Motor control       |
| IR Sensors                       | Line/edge detection |
| Ultrasonic / IR Sensors          | Opponent detection  |
| Battery                          | Power supply        |
| Chassis                          | Robot frame         |
🔌 Pin Configuration
| Pin           | Function               |
| ------------- | ---------------------- |
| Motor IN1/IN2 | Left motor             |
| Motor IN3/IN4 | Right motor            |
| Sensor pins   | IR / ultrasonic inputs |
📦 Installation
Install Arduino IDE
Open file:
sumo.ino
Select board and COM port
Upload code to Arduino
▶️ Usage
Power on robot
Place inside sumo ring
Robot will:
  Scan for opponent
  Move toward target
  Avoid boundary
  Repeat continuously
  Key Concepts
Embedded control system
Real-time decision making
Sensor fusion (edge + opponent detection)
Motor control logic
Finite state behavior
Possible Improvements
PID control for smoother movement
Better opponent tracking algorithm
Faster sensor response
Machine learning strategy (advanced)
Wireless debugging (Bluetooth / WiFi)
👤 Author

Nguyễn Văn Quý
