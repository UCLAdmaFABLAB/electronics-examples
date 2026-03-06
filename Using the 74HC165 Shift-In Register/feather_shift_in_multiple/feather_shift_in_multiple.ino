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

const int BUTTON8 = 8;
const int BUTTON9 = 9;
const int BUTTON10 = 10;
const int BUTTON11 = 11;
const int BUTTON12 = 12;
const int BUTTON13 = 13;
const int BUTTON14 = 14;
const int BUTTON15 = 15;

// shift register pins
const int LD_PIN = 9;
const int CE_PIN = 10;
const int Q7_PIN = 11;
const int CLK_PIN = 12;


// Init ShiftIn instance with one chip.
ShiftIn<2> shift;

void setup() {
  Serial.begin(9600);
  shift.begin(LD_PIN, CE_PIN, Q7_PIN, CLK_PIN);
}

void loop() {
  if (shift.update()) {
    if (shift.state(BUTTON0)) {
      Serial.println("Button 0 was pressed.");
    }
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
    if (shift.state(BUTTON9)) {
      Serial.println("Button 9 was pressed.");
    }
    if (shift.state(BUTTON10)) {
      Serial.println("Button 10 was pressed.");
    }
    if (shift.state(BUTTON11)) {
      Serial.println("Button 11 was pressed.");
    }
    if (shift.state(BUTTON12)) {
      Serial.println("Button 12 was pressed.");
    }
    if (shift.state(BUTTON13)) {
      Serial.println("Button 13 was pressed.");
    }
    if (shift.state(BUTTON14)) {
      Serial.println("Button 14 was pressed.");
    }
    if (shift.state(BUTTON15)) {
      Serial.println("Button 15 was pressed.");
    }
    delay(1);
  }
}