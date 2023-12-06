#include <Wire.h>
#include "Adafruit_MPR121.h"

const int LED = 13;

Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  pinMode(LED, OUTPUT);
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    while (1)
      ;
  }
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();

  // this is just a silly example to show how the code can be used
  // isTouched(currtouched, 0) will tell you if channel 0 is touched in the current state
  // so when a channel is touched, but wasn't before, do an action

  // when channel 0 is first touched, blink once
  if (isTouched(currtouched, 0) && !isTouched(lasttouched, 0)) {
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
  }

  // when channel 1 is first touched, blink twice
  if (isTouched(currtouched, 0) && !isTouched(lasttouched, 0)) {
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
  }

  // when channel 2 is first touched, blink three times
  if (isTouched(currtouched, 0) && !isTouched(lasttouched, 0)) {
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
  }


  // store the current state for next time
  lasttouched = currtouched;
}

bool isTouched(uint16_t touched, uint8_t num) {
  return (touched & (1 << (num)));
}