/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Sequência simples de LEDs

Autor: Tiago Fortunato Rosset
Data: 10/0/2026
Versão: 1.0

************************************************************************ */

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
unsigned long timer = 0;

void setup() {
  pinMode(led1, 8);
  pinMode(led2, 9);
  pinMode(led3, 10);
  pinMode(led4, 11);
  timer = millis();
}

void loop() {
  if((millis() - timer) >= 800){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
    timer = millis();
  }
  else if((millis() - timer) >= 600){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 2);
    digitalWrite(led4, 0);
  }
  else if((millis() - timer) >= 400){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  else if((millis() - timer) >= 200){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
}
