/*
Stepper Motor Control with DRV8880 using https://github.com/laurb9/StepperDriver
Install the library by searching for StepperDriver and installing the one by
Laurentiu Badea

  B1 -> red
  B2 -> yellow
  A2 -> gray
  A1 -> green

*/
#include <Arduino.h>
#include "DRV8880.h"

const int MOTOR_STEPS = 200;
const int RPM = 120;

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
const int MICROSTEPS = 8;

const int DIR = 5;
const int STEP = 6;

DRV8880 stepper(MOTOR_STEPS, DIR, STEP);

void setup() {
    stepper.begin(RPM, MICROSTEPS);
}

void loop() {  
    // Moving motor one full revolution using the degree notation
    stepper.rotate(360);

    // Moving motor to original position using steps
    stepper.move(-MOTOR_STEPS*MICROSTEPS);

    delay(5000);
}
