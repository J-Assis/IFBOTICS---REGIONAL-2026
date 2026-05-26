#include <Servo.h>

Servo servos[5];
const int pinos[] = {2, 3, 4, 5, 6};

void setup() {
  for (int i = 0; i < 5; i++)
    servos[i].attach(pinos[i]);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    servos[i].write(180);
    delay(500);
    servos[i].write(0);
    delay(500);
  }
}
