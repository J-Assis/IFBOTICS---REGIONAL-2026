#include <Servo.h>

// criação dos servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// pinos digitais usados no Mega
const int pino1 = 2;
const int pino2 = 3;
const int pino3 = 4;
const int pino4 = 5;
const int pino5 = 6;

void setup() {
  // associa cada servo ao seu pino
  servo1.attach(pino1);
  servo2.attach(pino2);
  servo3.attach(pino3);
  servo4.attach(pino4);
  servo5.attach(pino5);
}

// função pra mover um servo
void moverServo(Servo &s) {
  s.write(180); // fecha o dedo
  delay(500);

  s.write(0);   // abre o dedo
  delay(500);
}

void loop() {
  moverServo(servo1);
  moverServo(servo2);
  moverServo(servo3);
  moverServo(servo4);
  moverServo(servo5);
}
