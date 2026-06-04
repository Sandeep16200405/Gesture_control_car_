# Gesture_control_car_
Gesture Controlled Robot Car using Arduino, MPU6050, HC-05 Bluetooth Master-Slave Communication and L298N Motor Driver.
# Gesture Controlled Robot Car using Arduino, MPU6050 and HC-05 Bluetooth

A wireless gesture-controlled robot car developed using Arduino Uno, MPU6050 motion sensor, HC-05 Bluetooth modules, and an L298N motor driver. The system enables intuitive vehicle control through hand movements, where a glove-mounted transmitter detects gestures and wirelessly sends commands to a robot car.

![Project Overview](images/project_overview.jpg)

---

## Project Overview

This project consists of two independent units:

### Transmitter Unit (Gesture Glove)
The transmitter is mounted on a hand glove and uses an MPU6050 accelerometer and gyroscope sensor to detect hand orientation. An Arduino Uno processes the sensor data and transmits movement commands through an HC-05 Bluetooth module configured as **Master**.

### Receiver Unit (Robot Car)
The receiver consists of an Arduino Uno connected to an HC-05 Bluetooth module configured as **Slave**. Received commands are processed and sent to the L298N motor driver to control the movement of the robot car.

---

## Features

- Wireless gesture-based control
- Real-time Bluetooth communication
- HC-05 Master-Slave pairing using AT commands
- Forward, Reverse, Left, Right, and Stop movements
- MPU6050 motion sensing
- Differential drive robot chassis
- Low-cost Arduino implementation

---

## Hardware Components

### Transmitter (Gesture Glove)

| Component | Quantity |
|------------|----------|
| Arduino Uno | 1 |
| MPU6050 Sensor | 1 |
| HC-05 Bluetooth Module (Master) | 1 |
| Battery Pack | 1 |
| Hand Glove | 1 |

### Receiver (Robot Car)

| Component | Quantity |
|------------|----------|
| Arduino Uno | 1 |
| HC-05 Bluetooth Module (Slave) | 1 |
| L298N Motor Driver | 1 |
| DC Geared Motors | 2 |
| Robot Chassis | 1 |
| Wheels | 2 |
| Caster Wheel | 1 |
| Battery Pack | 1 |

---

## System Architecture

```text
Hand Movement
      │
      ▼
 MPU6050 Sensor
      │
      ▼
 Arduino Uno
      │
      ▼
 HC-05 Bluetooth (Master)
      │
 ~~~ Wireless Communication ~~~
      │
 HC-05 Bluetooth (Slave)
      │
      ▼
 Arduino Uno
      │
      ▼
 L298N Motor Driver
      │
      ▼
 DC Motors
      │
      ▼
 Robot Car Movement
```

---

## HC-05 Configuration

### Master Module

```AT
AT
AT+ROLE=1
AT+CMODE=0
AT+BIND=<Slave_Address>
```

### Slave Module

```AT
AT
AT+ROLE=0
```

---

## Gesture Commands

| Hand Gesture | Robot Action |
|--------------|-------------|
| Tilt Forward | Move Forward |
| Tilt Backward | Move Reverse |
| Tilt Left | Turn Left |
| Tilt Right | Turn Right |
| Neutral Position | Stop |

---

## Software Requirements

- Arduino IDE
- MPU6050 DMP Library
- I2Cdev Library
- SoftwareSerial Library

---

## Repository Structure

```text
gesture-control-car-hc05-master-slave/
│
├── transmitter_glove/
│   └── glove_code.ino
│
├── receiver_car/
│   └── car_code.ino
│
├── images/
│   └── project_overview.jpg
│
├── docs/
│   ├── hc05_master_setup.md
│   ├── hc05_slave_setup.md
│   └── wiring_guide.md
│
├── LICENSE
└── README.md
```

---

## Working Principle

1. MPU6050 continuously measures the orientation of the hand.
2. Arduino processes pitch and roll values from the sensor.
3. Corresponding movement commands are generated.
4. Commands are transmitted via the HC-05 Master module.
5. The HC-05 Slave module receives the commands.
6. Arduino controls the L298N motor driver.
7. Motors move the robot car according to the detected gesture.

---

## Applications

- Human-Machine Interaction
- Robotics Education
- Gesture-Based Control Systems
- Wireless Vehicle Control
- Embedded Systems Learning

---

## Future Improvements

- ESP32-Based Wireless Communication
- Bluetooth Low Energy (BLE)
- Obstacle Avoidance System
- FPV Camera Integration
- ROS 2 Integration
- Autonomous Navigation
- Computer Vision-Based Control

---

## Project Outcome

This project provided practical experience in:

- Embedded Systems Programming
- Bluetooth Communication
- Sensor Integration
- Motion Control
- Arduino Development
- Robotics System Design

It served as an excellent introduction to wireless robotics and gesture-based control systems.

---

## Author

**Sandeep Ravutla**

Electronics and Communication Engineering

Areas of Interest:
- Robotics
- Embedded Systems
- UAV Systems
- ROS 2
- Computer Vision
- Autonomous Systems

---

## License

This project is licensed under the MIT License.
