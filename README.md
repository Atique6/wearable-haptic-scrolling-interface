# Wearable Scrolling Interface with Joystick Control and Haptic Feedback

A wearable joystick-controlled scrolling interface that allows users to scroll through digital content without using a laptop trackpad.

The system uses an Arduino Nano, HW-504 joystick, Python, and an ERM coin vibration motor to create a touch-free scrolling experience with haptic feedback.

---

## Project Overview

This project was created as a physical computing and haptics mini project.

The device is worn as a band. The user controls scrolling by moving a joystick with their thumb. The Arduino Nano reads joystick movement and sends values to a Python script through USB serial communication. The Python script then converts those values into scrolling actions on the laptop.

The prototype supports:

- Vertical scrolling
- Horizontal scrolling
- Multi-speed scrolling
- Toggle scrolling ON and OFF
- Haptic feedback through vibration

---

## Motivation

Laptop trackpads can become inconvenient when hands are dirty, messy, or occupied. They may also be difficult to use for people with certain physical disabilities.

This project explores a wearable alternative that allows users to scroll without directly touching the laptop.

---

## Features

- Wearable band design
- Vertical scrolling with adjustable speed
- Horizontal scrolling with adjustable speed
- Joystick button toggles scrolling ON and OFF
- ERM coin vibration motor provides haptic feedback
- Python script converts Arduino data into laptop scrolling actions
- Redesigned from an earlier FSR-based prototype to reduce hysteresis and improve control

---

## Hardware Components

| Component | Purpose |
|----------|---------|
| Arduino Nano | Reads joystick input and sends data to laptop |
| HW-504 Joystick | Controls vertical and horizontal scrolling |
| ERM Coin Vibration Motor | Provides haptic feedback while scrolling |
| 330 Ω Resistor | Limits current to the vibration motor |
| Jumper Wires | Connects components |
| Wearable Band | Holds the prototype on the user’s hand or wrist |

---

## Software Used

| Tool | Purpose |
|------|---------|
| Arduino IDE | Uploads code to the Arduino Nano |
| Python | Runs the scrolling control script |
| pyserial | Reads serial data from Arduino |
| pyautogui | Controls scrolling and key presses on the laptop |

---

## Project Structure

```text
wearable-scrolling-interface/
├── Arduino Code.ino
├── scroll_control.py
├── Report.pdf
├── Demo video.MOV
└── schematic.png
```

---

## How It Works

```text
Joystick movement
        ↓
Arduino Nano reads joystick values
        ↓
Arduino sends vertical and horizontal values over USB serial
        ↓
Python script receives the values
        ↓
pyautogui converts the values into scroll actions
        ↓
Laptop screen scrolls up, down, left, or right
```

---

## Wiring Summary

| Component | Pin on Component | Arduino Pin |
|----------|------------------|-------------|
| Joystick | +5V | 5V |
| Joystick | GND | GND |
| Joystick | VRy | A0 |
| Joystick | VRx | A1 |
| Joystick | SW | D4 |
| Motor | + | D3 through 330 Ω resistor |
| Motor | - | GND |

---

## How to Run

### 1. Upload Arduino Code

Open the Arduino IDE and upload:

```text
Arduino Code.ino
```

Make sure the Arduino Nano is connected to your laptop through USB.

---

### 2. Install Python Libraries

Install the required Python libraries:

```bash
pip install pyserial pyautogui
```

---

### 3. Check Arduino Port

In `scroll_control.py`, update the port if needed:

```python
arduino_port = '/dev/cu.usbserial-A5069RR4'
```

On macOS, the port may look like:

```text
/dev/cu.usbserial-XXXX
```

On Windows, the port may look like:

```text
COM3
```

---

### 4. Run the Python Script

From the project folder, run:

```bash
python scroll_control.py
```

The terminal should show that the joystick scroll controller is active.

---

### 5. Use the Wearable Band

- Press the joystick button once to turn scrolling ON
- Move joystick up or down for vertical scrolling
- Move joystick left or right for horizontal scrolling
- Move joystick slightly for slow scrolling
- Move joystick further for faster scrolling
- Press the joystick button again to turn scrolling OFF

---

## Development Process

### Initial Prototype

The first version used a Force Sensitive Resistor connected on a breadboard. Pressing lightly or strongly changed the scroll speed.

Problems with the first version:

- Hysteresis caused scrolling to continue after releasing pressure
- Pressure readings were inconsistent
- Breadboard wiring made the setup bulky
- The device was not comfortable or wearable

### Final Prototype

The final version uses a joystick-based wearable band.

Improvements:

- More reliable directional control
- Faster and smoother scrolling
- Easier ON and OFF control using joystick button
- More comfortable wearable design
- Haptic feedback added through vibration motor

---

## Results

The final prototype successfully supports:

- Vertical scrolling
- Horizontal scrolling
- Adjustable scroll speed
- Toggle-based activation
- Haptic feedback
- Wearable form factor

The system was tested using a PDF document and allowed touch-free scrolling without using the laptop trackpad.

---

## Demo Video

Watch the project demo here:

https://youtu.be/nHaVoD1YCqE?si=zoS4Ai_6ZZDlE8R9

---

## Report

The full project report is available here:

[Report.pdf](Report.pdf)

---

## Code Files

- [Arduino Code.ino](Arduino%20Code.ino)
- [scroll_control.py](scroll_control.py)

---

## Future Improvements

Future versions could include:

- ESP32 Bluetooth support
- Wireless operation
- Battery-powered design
- Improved vibration feedback patterns
- Personalized scrolling settings
- Interactive Machine Learning for adapting to user preferences

---

## Skills Demonstrated

- Embedded systems programming
- Arduino development
- Python automation
- Serial communication
- Sensor data processing
- Hardware prototyping
- Human-computer interaction
- Haptic feedback design
- Iterative prototyping and debugging

---

## Author

Atique Muhammad
