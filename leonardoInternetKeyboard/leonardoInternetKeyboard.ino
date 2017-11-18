#include "Keyboard.h"

const int button1 = 10;
const int button2 = 11;
const int button3 = 12;

int lastButton1 = HIGH;
int lastButton2 = HIGH;
int lastButton3 = HIGH;

void setup() {
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  int val1 = digitalRead(button1);
  int val2 = digitalRead(button2);
  int val3 = digitalRead(button3);

  if (val1 != lastButton1 && val1 == LOW) {
    Keyboard.print("omg\n");
    delay(100);
  }

  if (val2 != lastButton2 && val2 == LOW) {
    Keyboard.print("wtf\n");
    delay(100);
  }

  if (val3 != lastButton3 && val3 == LOW) {
    Keyboard.print("lol\n");
    delay(100);
  }

  lastButton1 = val1;
  lastButton2 = val2;
  lastButton3 = val3;

}