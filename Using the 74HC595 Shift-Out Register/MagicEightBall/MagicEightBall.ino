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

const int BUTTON_PIN = 12;

const int waitTime = 10000;

int state = 0;
long timer = 0;
int choice = 0;

// Init ShiftOut instance with a single chip
// If you want to use more shift registers, just modify this number
ShiftOut<1> shift;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  randomSeed(analogRead(0));
  shift.begin(
    9, // data
    6, // clock
    5  // latch
  );
}

void loop() {
  if (state == 0) {
    int val = digitalRead(BUTTON_PIN);
    shift.setAllLow();
    shift.write();
    if (val == LOW) {
      state = 1;
      timer = millis();
    }
  }

  if (state == 1) {
    shift.setAllLow();
    long rnd = random(0, 8);
    shift.setHigh(rnd);
    shift.write();
    delay(100);

    if (millis() > timer + waitTime) {
      state = 2;
      timer = millis();
    }
  }

  if (state == 2) {
    blinkAll();
    if (millis() > timer + 1000) {
      state = 3;
      choice = random(0, 8);
      timer = millis();
    }
  }

  if (state == 3) {
    shift.setAllLow();
    shift.setHigh(choice);
    shift.write();

    if (millis() > timer + 2000) {
      state = 0;
      timer = millis();
    }
  }
}

void blinkAll() {
  shift.setAllLow();
  shift.write();
  delay(100);

  shift.setAllHigh();
  shift.write();
  delay(100);
}
