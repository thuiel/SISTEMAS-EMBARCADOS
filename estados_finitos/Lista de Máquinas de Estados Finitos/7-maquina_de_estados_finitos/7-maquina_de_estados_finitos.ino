/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 7, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 12/06/2026
Versão: 1.0

************************************************************************ */

const int b1 = 2;
const int b2 = 3;
const int S1 = 4;
const int S2 = 5;
const int S3 = 6;
const int S4 = 7;
const int S5 = 8;
const int S6 = 9;
const int M1 = 10;
const int C1 = 11;
const int C2 = 12;
const int L1 = 13;
bool valor_b2 = 0;
bool valor_S3 = 0;
bool valor_S4 = 0;
int estado = 1;

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(L1, OUTPUT);
}

void loop() {
  valor_b2 = digitalRead(b2);

  if(valor_b2){
    estado = 1;
  }

  switch (estado){
    case 1:
    digitalWrite(L1, 0);
    digitalWrite(M1, 0);
    digitalWrite(C1, 0);
    digitalWrite(C2, 0);
    if(!digitalRead(b1)){
      digitalWrite(L1, 1);
      digitalWrite(M1, 1);
      digitalWrite(C1, 1);
      estado = 2;
    }

    break;

    case 2:
    if(digitalRead(S1)){
      valor_S3 = digitalRead(S3);
      valor_S4 = digitalRead(S4);
      if(valor_S3 && valor_S4){
        estado = 3;
      }
      else if(valor_S3 && !valor_S4){
        estado = 4;
      }
      else if(!valor_S3 && valor_S4){
        estado = 1;
      }
    }

      break;

      case 3:
      if(digitalRead(S6)){
        digitalWrite(M1, 0);
        digitalWrite(C2, 0);
        estado = 1;
      }

      break;

      case 4:
      if(digitalRead(S4)){
        digitalWrite(M1, 0);
        digitalWrite(C2, 1);
        estado = 5;
      }

      break;

      case 5:
      if(digitalRead(S5)){
        digitalWrite(C1, 0);
        digitalWrite(C2, 0);
        estado = 1;
      }

      break;
    }
  }
}