/*
 * Feather 32u4 + 74HC165 Shift Register Internet Keyboard
 * Uses: https://github.com/InfectedBytes/ArduinoShiftIn for the shift register
 * 
 * Created: Feb, 2026
 * 
 */

#include <ShiftIn.h>

const int BUTTON0 = 0;
const int BUTTON1 = 1;
const int BUTTON2 = 2;
const int BUTTON3 = 3;
const int BUTTON4 = 4;
const int BUTTON5 = 5;
const int BUTTON6 = 6;
const int BUTTON7 = 7;

// shift register pins
const int pLoadPin = 8;
const int clockEnablePin = 9;
const int dataPin = 11;
const int clockPin = 5;



// Init ShiftIn instance with one chip.
ShiftIn<1> shift;

void setup() {
  shift.begin(pLoadPin, clockEnablePin, dataPin, clockPin);
}

void loop() {
  if (shift.update()) {
    if (shift.state(BUTTON1)) {
      Serial.println("Button 1 was pressed.");
    }
    if (shift.state(BUTTON2)) {
      Serial.println("Button 2 was pressed.");
    }
    if (shift.state(BUTTON3)) {
      Serial.println("Button 3 was pressed.");
    }
    if (shift.state(BUTTON4)) {
      Serial.println("Button 4 was pressed.");
    }
    if (shift.state(BUTTON5)) {
      Serial.println("Button 5 was pressed.");
    }
    if (shift.state(BUTTON6)) {
      Serial.println("Button 6 was pressed.");
    }
    if (shift.state(BUTTON7)) {
      Serial.println("Button 7 was pressed.");
    }
    if (shift.state(BUTTON8)) {
      Serial.println("Button 8 was pressed.");
    }
    delay(1);
  }
}