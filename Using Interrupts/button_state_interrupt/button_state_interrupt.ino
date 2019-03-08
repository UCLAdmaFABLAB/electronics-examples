const int BUTTON_PIN = 0;
const int LED_PIN = 13;

// this has to be marked as volatile because its value will change
// outside of the main code
volatile int state = 1;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  /*
  tell the arduino to listen for interrupts on a specific pin
  
  1) Pin Number
      only some pins support this! look here: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
      or on the reference pinout for your board.
      the Feather 32u4 supports them on pins 0, 1, 2, 3

  2) Function to call when the value changes on the pin
  3) Type of change
      Possible values are:  
        LOW to trigger the interrupt whenever the pin is low,
        CHANGE to trigger the interrupt whenever the pin changes value
        RISING to trigger when the pin goes from low to high,
        FALLING for when the pin goes from high to low.

  For more on interrupts: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  */
   
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onPress, RISING);
}

void onPress() {
  state++;
  if (state > 3) {
    state = 0;
  }
}

void loop() {  
  switch (state) {
    case 1:
      blink(1000);
      break;

    case 2:
      blink(500);
      break;

    case 3:
      blink(100);
      break;

    default:
      digitalWrite(LED_PIN, LOW);
      break;
  }
}

void blink(int time) {
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}
