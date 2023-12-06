/*
 * Pin Order, counterclockwise, starting on bottom left with notch facing left
 * 1 - OUTPUT 2
 * 2 - OUTPUT 3
 * 3 - OUTPUT 4
 * 4 - OUTPUT 5
 * 5 - OUTPUT 6
 * 6 - OUTPUT 7
 * 7 - OUTPUT 8
 * 8 - GND
 * 9 - 
 * 10 - SRCLR, CONNECT TO VCC
 * 11 - CLOCK
 * 12 - LATCH
 * 13 - OE, CONNECT TO GND
 * 14 - DATA
 * 15 - OUTPUT 1
 * 16 - VCC
 * 
 */

#include <ShiftOut.h>

// Init ShiftOut instance with a single chip
// If you want to use more shift registers, just modify this number
ShiftOut<1> shift;

// this variable will keep track of which pin is being toggled
// every time through loop it'll increment to make the next LED turn on
int led = 0;

void setup() {
  shift.begin(
    9, // data
    6, // clock
    5  // latch
  );
}

void loop() {
  shift.setAllLow();  // turn all pins off
  shift.setHigh(led); // set led pin to high
  shift.write();      // write out to 74HC595. You have to do this after you've set everything

  // increment led var
  led++;

  // if led var is bigger than 7, wrap around to 0
  if (led > 7) {
    led = 0;
  }
  delay(250);
}
