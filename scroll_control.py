import serial        # allows Python to talk to the Arduino
import pyautogui     # sends scroll and keyboard actions to the computer
import time          # used for short pauses

arduino_port = '/dev/cu.usbserial-A5069RR4'
baud_rate = 9600

VERT_MULTIPLIER = 3
HORIZ_MULTIPLIER = 1

try:
    # Open the USB connection to the Arduino
    ser = serial.Serial(arduino_port, baud_rate, timeout=1)
    time.sleep(2)     # waits a moment for the connection to be ready

    print("Connected Joystick scroll controller active")
    print("Press joystick button to toggle scrolling on or off")

    while True:
        # Only read when the Arduino has sent something
        if ser.in_waiting > 0:

            # This clears old unread lines and keeps the newest one
            while ser.in_waiting > 0:
                line = ser.readline().decode(errors="ignore").strip()

            # If the line is empty we skip it
            if not line:
                continue

            try:
                parts = line.split()

                # The Arduino sends two numbers "vertical horizontal"
                if len(parts) >= 2:
                    vert = int(parts[0])
                    horiz = int(parts[1])
                elif len(parts) == 1:
                    vert = int(parts[0])
                    horiz = 0
                else:
                    continue

                # If joystick is centered then do nothing
                if vert == 0 and horiz == 0:
                    continue

                # Vertical scrolling
                if vert != 0:
                    pyautogui.scroll(vert * VERT_MULTIPLIER)

                # Horizontal scrolling uses left or right arrow keys
                if horiz != 0:
                    key = 'right' if horiz > 0 else 'left'
                    presses = abs(horiz) * HORIZ_MULTIPLIER
                    for _ in range(presses):
                        pyautogui.press(key)

                print(f"V {vert}, H {horiz}")

            except ValueError:
                # If Arduino sends something that is not a number we ignore it
                continue

        # Short pause so the loop is smooth and not too busy
        time.sleep(0.01)

except KeyboardInterrupt:
    print("\nStopped by user")
except Exception as e:
    print(f"Error {e}")
