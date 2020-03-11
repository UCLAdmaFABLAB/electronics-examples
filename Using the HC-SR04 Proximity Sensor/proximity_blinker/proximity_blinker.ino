const int TRIGGER_PIN = 6;
const int ECHO_PIN = 5;
const int LED_PIN = 13;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2) / 29.1;

  if (distance < 200 && distance > 0) {
    digitalWrite(LED_PIN, HIGH);
    delay(distance);
    digitalWrite(LED_PIN, LOW);
    delay(distance);
  }
}
