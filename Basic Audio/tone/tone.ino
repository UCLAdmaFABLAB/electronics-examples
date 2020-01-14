const int PIEZO_PIN = 9;

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // pin to use, frequency, duration
  tone(PIEZO_PIN, 1000, 500);
}
