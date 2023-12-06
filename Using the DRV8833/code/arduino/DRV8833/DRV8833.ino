const int MOTOR_FORWARD_PIN = 11;
const int MOTOR_REVERSE_PIN = 10;

void setup() {
  pinMode(MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_REVERSE_PIN, OUTPUT);
}

void loop() {
  digitalWrite(MOTOR_FORWARD_PIN, HIGH);
  digitalWrite(MOTOR_REVERSE_PIN, LOW);
  delay(1000);

  digitalWrite(MOTOR_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_REVERSE_PIN, LOW);
  delay(1000);

  digitalWrite(MOTOR_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_REVERSE_PIN, HIGH);
  delay(1000);

  digitalWrite(MOTOR_FORWARD_PIN, LOW);
  digitalWrite(MOTOR_REVERSE_PIN, LOW);
  delay(1000);
}
