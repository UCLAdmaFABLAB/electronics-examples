const int TRIGGER_PIN = 6;
const int ECHO_PIN = 5;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2) / 29.1;

  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(100);
}
