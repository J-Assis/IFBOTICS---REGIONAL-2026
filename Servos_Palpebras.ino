#include <Servo.h>

Servo olho[2];                        //olho[0] = esquerdo, olho[1] = direito
const int pinos[] = {7, 8};

void setup() {
  for (int i = 0; i < 2; i++)
    olho[i].attach(pinos[i]);
}

void piscar(int i) {

  olho[0].write(180); 
  olho[1].write(180); 
    delay(150);
  olho[0].write(0);   
  olho[1].write(0);   
    delay(2000);
}
/* pisca um olho específico (0 = esquerdo, 1 = direito)
void piscar(int i) {
  olho[i].write(180); //fecha
  delay(150);
  olho[i].write(0);   //abre
  delay(2000);        //tempo com olho aberto
} */

void loop() {
  piscar(0); //pisca olho esquerdo
  piscar(1); //pisca olho direito

  //piscar os dois juntos: 
  //olho[0].write(180); olho[1].write(180); delay(150);
  //olho[0].write(0);   olho[1].write(0);   delay(2000);
}
