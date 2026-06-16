# Wearable Scrolling Interface with Joystick Control and Haptic Feedback

A wearable scrolling interface that lets users scroll through digital content without using a laptop trackpad.

The device uses an Arduino Nano, HW-504 joystick, Python, and an ERM coin vibration motor. The joystick controls vertical and horizontal scrolling, while the motor provides haptic feedback during scrolling.

---

## Features

* Wearable band design
* Vertical scrolling
* Horizontal scrolling
* Adjustable scroll speed based on joystick movement
* Joystick button toggles scrolling ON and OFF
* Haptic feedback using an ERM coin vibration motor
* USB serial communication between Arduino and Python

---

## Hardware

| Component                | Purpose                             |
| ------------------------ | ----------------------------------- |
| Arduino Nano             | Reads joystick input                |
| HW-504 Joystick          | Controls scroll direction and speed |
| ERM Coin Vibration Motor | Provides haptic feedback            |
| 330 Ω Resistor           | Limits current to the motor         |
| Wearable Band            | Holds the prototype in place        |

---

## Software

| Tool        | Purpose                                     |
| ----------- | ------------------------------------------- |
| Arduino IDE | Uploads code to the Arduino Nano            |
| Python      | Runs the scroll control script              |
| pyserial    | Reads Arduino serial data                   |
| pyautogui   | Sends scroll and key commands to the laptop |

---

## Project Structure

```text
wearable-scrolling-interface/
├── README.md
├── Arduino Code.ino
├── scroll_control.py
├── Wiring Diagram.png
└── demo_video_link.txt
```

---

## How It Works

```text
Joystick movement
        ↓
Arduino Nano reads joystick values
        ↓
Arduino sends values through USB serial
        ↓
Python receives the values
        ↓
pyautogui converts them into scroll actions
        ↓
Laptop scrolls up, down, left, or right
```

---

## Wiring Summary

| Component | Pin | Arduino Pin               |
| --------- | --- | ------------------------- |
| Joystick  | +5V | 5V                        |
| Joystick  | GND | GND                       |
| Joystick  | VRy | A0                        |
| Joystick  | VRx | A1                        |
| Joystick  | SW  | D4                        |
| Motor     | +   | D3 through 330 Ω resistor |
| Motor     | -   | GND                       |

See the full wiring diagram here:

[Wiring Diagram.png](Wiring%20Diagram.png)

---

## How to Run

### 1. Upload the Arduino code

Open `Arduino Code.ino` in the Arduino IDE and upload it to the Arduino Nano.

### 2. Install Python libraries

```bash
pip install pyserial pyautogui
```

### 3. Check the Arduino port

In `scroll_control.py`, update the port if needed:

```python
arduino_port = '/dev/cu.usbserial-A5069RR4'
```

On Windows, the port may look like:

```text
COM3
```

On macOS, the port may look like:

```text
/dev/cu.usbserial-XXXX
```

### 4. Run the Python script

```bash
python scroll_control.py
```

### 5. Use the band

* Press the joystick button once to turn scrolling ON
* Move the joystick up or down for vertical scrolling
* Move the joystick left or right for horizontal scrolling
* Tilt slightly for slow scrolling
* Tilt further for faster scrolling
* Press the joystick button again to turn scrolling OFF

---

## Development Process

The first prototype used a Force Sensitive Resistor on a breadboard. That version had issues with hysteresis, inconsistent pressure readings, and bulky wiring.

The final version was redesigned as a wearable joystick-based band. This improved control, responsiveness, comfort, and usability.

---

## Demo Video

Watch the demo here:

https://youtu.be/nHaVoD1YCqE?si=zoS4Ai_6ZZDlE8R9

---

## Future Changes

* ESP32 Bluetooth support
* Wireless operation
* Battery-powered design
* Improved vibration feedback patterns
* Personalized scrolling settings

---

## Skills Demonstrated

* Arduino programming
* Python automation
* Serial communication
* Sensor data processing
* Embedded systems
* Haptic feedback
* Human-computer interaction
* Iterative prototyping
