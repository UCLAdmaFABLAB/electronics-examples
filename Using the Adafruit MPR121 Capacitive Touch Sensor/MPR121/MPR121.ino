#include <Wire.h>
#include "Adafruit_MPR121.h"

const int LED = 13;

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
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

  for (uint8_t i = 0; i < 12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i))) {
      // if the "1" channel is touched, turn the LED on
      if (i == 0) {
        digitalWrite(LED, HIGH);
      } else if (i == 1) {
        // do something else
      }
    }

    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i))) {
      digitalWrite(LED, LOW);
    }
  }

  // reset our state
  lasttouched = currtouched;
}
