/*
 * Trinket M0 + 74HC165 Shift Register Internet Keyboard
 * Uses: https://github.com/InfectedBytes/ArduinoShiftIn for the shift register
 * 
 * Created: Apr, 2018
 * 
 */

#include <ShiftIn.h>
#include "Keyboard.h"

// Init ShiftIn instance with one chip.
// The number in brackets defines the number of daisy-chained 74HC165 chips
// So if you are using two chips, you would write: ShiftIn<2> shift;
ShiftIn<1> shift;

void setup() {
  Keyboard.begin();
  // declare pins: pLoadPin, clockEnablePin, dataPin, clockPin
  shift.begin(2, 4, 3, 1);
}

void loop() {
  if (shift.update()) {
    if (shift.state(7)) {
      Keyboard.print("lol\n");
    }
    if (shift.state(6)) {
      Keyboard.print("wtf\n");
    }
    if (shift.state(5)) {
      Keyboard.print("smh\n");
    }
    if (shift.state(4)) {
      Keyboard.print("OK\n");
    }
    if (shift.state(0)) {
      Keyboard.print("omg\n");
    }
    delay(1);
  }
}
