
#include "lib.h"

void setup() {
  Serial.begin(9600);
  configurePins();
}

void tacticZero() {
  
}

void tacticOne() {

}

// Prints sensor data.
void tacticTwo() {
  String str = "";
  str += digitalRead(PIN_BTN);
  str += ", ";
  str += getTactic();
  str += ", ";
  str += analogRead(PIN_LINEFRONT);
  str += ", ";
  str += analogRead(PIN_LINEBACK);
  str += ", ";
  str += analogRead(PIN_DISTRIGHT);
  str += ", ";
  str += analogRead(PIN_DISTLEFT);
  Serial.println(str);
}

// Moves in a pattern.
void tacticThree() {
  move(-130, 130);
  delay(500);
  move(130, -130);
  delay(500);
  move(130, 130);
  delay(500);
  move(-130, -130);
  delay(500);
  move(0, 0);
}

void loop() {
  
  blockUntilGameStart();
  
  switch (getTactic()) {
    case 0:
      tacticZero();
      break;
    case 1:
      tacticOne();
      break;
    case 2:
      tacticTwo();
      break;
    case 3:
      tacticThree();
      break;
  }
}

