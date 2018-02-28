const int MOTOR_1_PIN = 3;
const int MOTOR_2_PIN = 4;
const int ENABLE_PIN = 9;


void setup() {
  pinMode(MOTOR_1_PIN, OUTPUT);
  pinMode(MOTOR_2_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, HIGH);
}

void loop() {
  digitalWrite(MOTOR_1_PIN, LOW);
  digitalWrite(MOTOR_2_PIN, HIGH);
  delay(1000);

  digitalWrite(MOTOR_1_PIN, HIGH);
  digitalWrite(MOTOR_2_PIN, LOW);
  delay(1000);
}



