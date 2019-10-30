# Using the 74HC595 Shift-Out Register

This code also uses the [ShiftOut](https://github.com/InfectedBytes/ArduinoShiftOut) library to make handling the shift register easy

![Circuit Image](https://github.com/UCLAdmaFABLAB/electronics-examples/raw/trunk/Using%20the%2074HC595%20Shift-Out%20Register/Feather32u4_Shift_Out.png)


![74HC595 Pinout](https://github.com/UCLAdmaFABLAB/electronics-examples/raw/trunk/Using%20the%2074HC595%20Shift-Out%20Register/Pinout-74HC595-Shift-Register.png)


## Sample Code

```c
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
 * 11 - SRCLK (CLOCK)
 * 12 - RCLK (LATCH)
 * 13 - OE, CONNECT TO GND
 * 14 - SER (DATA)
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
```