/*|--janela--|
2:30  ──●══════════○── 2:31
        ↑          ↑
     executa    não executa mais*/

#include <Servo.h>

Servo olho[2];
const int pinos[] = {2, 3};

#define TEMPO(min, seg) ((unsigned long)(min)*60000 + (seg)*1000)

// momento em que o próximo piscar vai acontecer
unsigned long proximoPiscar = 0;

// apresentação ativa entre 2:30 e 3:00
#define INICIO TEMPO(2, 30)
#define FIM    TEMPO(3, 00)

void piscar() {
  olho[0].write(180); olho[1].write(180);
  delay(150);                              // fecha rápido
  olho[0].write(0);   olho[1].write(0);
  delay(50);                               // abre um pouco mais devagar

  // agenda o próximo piscar: entre 3 e 8 segundos
  proximoPiscar = millis() + random(3000, 8000);
}

void setup() {
  randomSeed(analogRead(0));               // semente aleatória real
  for (int i = 0; i < 2; i++)
    olho[i].attach(pinos[i]);
  delay(5000);

  // agenda o primeiro piscar logo no início da janela
  proximoPiscar = INICIO;
}

void loop() {
  unsigned long agora = millis();

  // só pisca dentro da janela da apresentação
  if (agora >= INICIO && agora < FIM) {
    if (agora >= proximoPiscar) {
      piscar();
    }
  }
}
