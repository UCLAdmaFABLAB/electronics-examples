/* Stepper Motor Control with DRV8880
 *  
 *  Make one revolution using 1/8 microstepping (default)
 *  then reverse direction.
 *  
 *  Created 3 Mar. 2019
 *  by Ben Lerchin
 *  
 *  Adapted from
 *  https://github.com/laurb9/StepperDriver/blob/master/src/BasicStepperDriver.h
 *
 *  B1 -> red
 *  B2 -> yellow
 *  A2 -> gray
 *  A1 -> green
 */
 
const int DIR_PIN = 5;
const int STEP_PIN = 6;

const int STEPS_PER_ROTATION = 200;
const int MICROSTEPS = 8; //M0 floating, M1 Low. This should match microstepping pin config.
const int RPM = 150; // Change this to adjust speed of movement. Acceptable range is about 10 - 200;

const int MICROSTEPS_PER_ROTATION = STEPS_PER_ROTATION * MICROSTEPS;

//That's 60 * 1m :)
const int PULSE_DURATION = 60.0 * 1000000L/MICROSTEPS_PER_ROTATION/RPM;

bool dirBackward = false;
int numSteps = 0;

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW);
  digitalWrite(STEP_PIN, LOW);
}

void loop() {
  digitalWrite(DIR_PIN, dirBackward);
  
  if (numSteps < MICROSTEPS_PER_ROTATION) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(PULSE_DURATION);
    digitalWrite(STEP_PIN, LOW);
    numSteps++;
  } else {
    delay(1000);
    // dirBackward = !dirBackward;
    numSteps = 0;
  }
}
