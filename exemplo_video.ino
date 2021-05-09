#include <Servo.h>

#define PINO_27 27
#define PINO_14 14
#define PINO_33 33

float posicao = 0;

Servo servo1;

void setup() {
  pinMode(PINO_27, INPUT); 
  pinMode(PINO_14, INPUT); 
  servo1.attach(PINO_33);

  Serial.begin(115200);
}

void loop() {
  int valor_pino27 = digitalRead(PINO_27);
  int valor_pino14 = digitalRead(PINO_14);

  if(valor_pino14 == LOW && posicao < 5){
    Serial.println("botao mais apertado");
    printInt("valor_pino27: %d", valor_pino27);
    printInt("valor_pino14: %d", valor_pino14);
    posicao++;
    printInt("posicao: %d", posicao);
    int angulo = (posicao/5) * 180;
    atualizarposicao(angulo);
    delay(300);
  }

  if(valor_pino27 == LOW && posicao > 0){
    Serial.println("botao menos apertado");
    printInt("valor_pino27: %d", valor_pino27);
    printInt("valor_pino14: %d", valor_pino14);
    posicao--;
    printInt("posicao: %d", posicao);
    int angulo = (posicao/5) * 180;
    atualizarposicao(angulo); 
    delay(300);
  }

  
}

void atualizarposicao(int angulo){
  printInt("angulo: %d", angulo);
  servo1.write(angulo);
}

void printInt(char *text, int number){
  char buffer[30];
  sprintf(buffer, text, number);
  Serial.println(buffer);
}
