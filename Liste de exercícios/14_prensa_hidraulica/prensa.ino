/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Prensa Hidráulica com Comando Bi-manual

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int botao1 = 2;
const int botao2 = 3;
const int led1 = 8;
const int led2 = 9;
bool estado1 = 1;
bool estado2 = 1;
bool ultimo1 = 1;
bool ultimo2 = 1;
bool press1 = 0;
bool press2 =0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);

  if(estado1 == 0 && ultimo1 == 1){
    timer1 = millis();
    press1 = 1;
  }
  if(estado2 == 0 && ultimo2 == 1){
    timer2 = millis();
    press2 = 1;
  }

  if(press1 && press2){
    int diferenca = abs(timer1 - timer2);

    if(diferenca <= 500){
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
    }
    else{
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
    }
    press1 = 0;
    press2 = 0;
  }
  else if(press1){
    if(!press2 && (millis() - timer1 >= 500)){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      press1 = 0;
    }
  }
  else if(press2){
    if(!press1 && (millis() - timer2 >= 500)){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      press2 = 0;
    }
  }
  else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
  }
  ultimo1 = estado1;
  ultimo2 = estado2;
}