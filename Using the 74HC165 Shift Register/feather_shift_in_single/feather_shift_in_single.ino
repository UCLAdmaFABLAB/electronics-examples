/*
 * Feather 32u4 + 74HC165 Shift Register Internet Keyboard
 * Uses: https://github.com/InfectedBytes/ArduinoShiftIn for the shift register
 * 
 * Whenever a button state changes, will print the state of all buttons
 * Created: Feb, 2026
 * 
 * If using platformio, be sure to add:
 * lib_deps = https://github.com/InfectedBytes/ArduinoShiftIn
 * to the platformio.ini
 *
 */

#include <Arduino.h>
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
const int pLoadPin = 9;
const int clockEnablePin = 10;
const int dataPin = 11;
const int clockPin = 12;


// Init ShiftIn instance with one chip.
ShiftIn<1> shift;

void setup() {
  Serial.begin(9600);
  shift.begin(pLoadPin, clockEnablePin, dataPin, clockPin);
}

void loop() {
  if (shift.update()) {
    if (shift.state(BUTTON0)) {
      Serial.println("Button 0 is pressed.");
    }
    if (shift.state(BUTTON1)) {
      Serial.println("Button 1 is pressed.");
    }
    if (shift.state(BUTTON2)) {
      Serial.println("Button 2 is pressed.");
    }
    if (shift.state(BUTTON3)) {
      Serial.println("Button 3 is pressed.");
    }
    if (shift.state(BUTTON4)) {
      Serial.println("Button 4 is pressed.");
    }
    if (shift.state(BUTTON5)) {
      Serial.println("Button 5 is pressed.");
    }
    if (shift.state(BUTTON6)) {
      Serial.println("Button 6 is pressed.");
    }
    if (shift.state(BUTTON7)) {
      Serial.println("Button 7 is pressed.");
    }
    delay(1);
  }
}