
// PWM
int PIN_ENA = 6;
int PIN_ENB = 3;

// Digital
int PIN_IN1 = 4;
int PIN_IN2 = 5;
int PIN_IN3 = 2;
int PIN_IN4 = 7;
int PIN_BTN = 10;
int PIN_SW1 = 11;
int PIN_SW2 = 12;

// Analog
int PIN_DISTRIGHT = 0;
int PIN_DISTLEFT = 1;
int PIN_LINEFRONT = 2;
int PIN_LINEBACK = 3;

// Configure pin modes.
void configurePins() {
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_SW1, INPUT_PULLUP);
  pinMode(PIN_SW2, INPUT_PULLUP);
  pinMode(PIN_DISTRIGHT, INPUT);
  pinMode(PIN_DISTLEFT, INPUT);
}

// Get the selected tactic (two switches).
int getTactic() {
  return (digitalRead(PIN_SW1) << 1) | digitalRead(PIN_SW2);
}

// Get distance from left IR sensor.
int leftDistance() {
  return analogRead(PIN_DISTLEFT);
}

// Get distance from right IR sensor.
int rightDistance() {
  return analogRead(PIN_DISTRIGHT);
}

// Is the front sensor outside the ring?
bool isFrontOutside() {
  return analogRead(PIN_LINEFRONT) > 500;
}

// Is the back sensor outside the ring?
bool isBackOutside() {
  return analogRead(PIN_LINEBACK) > 500;
}

// Block execution until the game is started with the push button.
bool gameRunning = false;
void blockUntilGameStart() {
  if (!gameRunning) {
    while (digitalRead(PIN_BTN));
    while (!digitalRead(PIN_BTN));
    gameRunning = true;
  }
}

// Rotate left and right wheels [-255, 255].
void move(int left, int right) {
  analogWrite(PIN_ENA, abs(left));
  analogWrite(PIN_ENB, abs(right));

  if (left < 0) {
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
  } else {
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
  }
  if (right < 0) {
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
  } else {
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
  }
}
