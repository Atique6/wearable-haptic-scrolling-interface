// Joystick scroll controller for vertical and horizontal scrolling
// Joystick button turns scrolling on and off
// VRy to A0  vertical
// VRx to A1  horizontal
// SW  to D4  button

const int JOY_VRY_PIN = A0;
const int JOY_VRX_PIN = A1;
const int JOY_SW_PIN  = 4;

// These will hold the joystick values when it is at rest
int joyCenterY = 0;
int joyCenterX = 0;

// Highest speed level for vertical and horizontal scrolling
const int MAX_LEVEL_V = 3;
const int MAX_LEVEL_H = 3;

// Small movement near the center that we want to ignore
const int DEADZONE    = 80;

// True means scrolling is active
bool scrollingEnabled = false;

// Used to clean up noisy button presses
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_MS = 200;

// Read from an analog pin a few times and return the average
// This makes the reading smoother
int readAverage(int pin) {
  long total = 0;
  const int samples = 4;

  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(2);
  }
  return total / samples;
}

// Turn joystick distance from center into a speed level
// Returns a number from 0 up to maxLevel
int deltaToLevel(int delta, int maxLevel) {
  int mag = abs(delta);

  if (mag <= DEADZONE) {
    return 0;
  }

  mag -= DEADZONE;

  if (mag < 80) {
    return 1;
  } else if (mag < 200) {
    return 2;
  } else {
    return maxLevel;
  }
}

void setup() {
  Serial.begin(9600);

  // Button uses the internal pull up resistor
  // Not pressed gives HIGH, pressed gives LOW
  pinMode(JOY_SW_PIN, INPUT_PULLUP);

  // Find the joystick center values
  // Do not touch the joystick while this runs
  long sumY = 0;
  long sumX = 0;
  const int calibSamples = 50;

  for (int i = 0; i < calibSamples; i++) {
    sumY += analogRead(JOY_VRY_PIN);
    sumX += analogRead(JOY_VRX_PIN);
    delay(10);
  }

  joyCenterY = sumY / calibSamples;
  joyCenterX = sumX / calibSamples;

  Serial.print("Center Y ");
  Serial.println(joyCenterY);
  Serial.print("Center X ");
  Serial.println(joyCenterX);
  Serial.println("Press joystick button to toggle scrolling on or off");
}

void loop() {
  // Handle the button that turns scrolling on or off
  int buttonState = digitalRead(JOY_SW_PIN);
  unsigned long now = millis();

  if (buttonState == LOW && lastButtonState == HIGH &&
      (now - lastDebounceTime) > DEBOUNCE_MS) {

    scrollingEnabled = !scrollingEnabled;
    lastDebounceTime = now;

    Serial.print("SCROLL ");
    if (scrollingEnabled) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }
  }
  lastButtonState = buttonState;

  // Read the joystick position
  int joyY = readAverage(JOY_VRY_PIN);
  int joyX = readAverage(JOY_VRX_PIN);

  // How far we are from the center in each direction
  int deltaY = joyY - joyCenterY;
  int deltaX = joyX - joyCenterX;

  // These are the values we will send to the laptop
  int scrollV = 0;  // vertical
  int scrollH = 0;  // horizontal

  if (scrollingEnabled) {
    // Vertical scrolling
    int levelV = deltaToLevel(deltaY, MAX_LEVEL_V);
    if (levelV > 0) {
      if (deltaY < 0) {
        // Joystick up gives positive value for scroll up
        scrollV = levelV;
      } else {
        // Joystick down gives negative value for scroll down
        scrollV = -levelV;
      }
    }

    // Horizontal scrolling
    int levelH = deltaToLevel(deltaX, MAX_LEVEL_H);
    if (levelH > 0) {
      if (deltaX < 0) {
        // Joystick left gives negative value
        scrollH = -levelH;
      } else {
        // Joystick right gives positive value
        scrollH = levelH;
      }
    }
  }

  // Send the vertical and horizontal values
  // The Python script on the laptop reads these numbers
  Serial.print(scrollV);
  Serial.print(' ');
  Serial.println(scrollH);

  // Short pause so the values are sent many times each second
  delay(10);
}
