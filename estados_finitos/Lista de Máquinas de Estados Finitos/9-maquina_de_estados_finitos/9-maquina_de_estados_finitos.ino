/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 9, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 13/06/2026
Versão: 1.0

************************************************************************ */

const int b1 = 2;
const int b2 = 3;
const int S1 = 4;
const int S2 = 5;
const int S3 = 6;
const int S4 = 7;
const int M1 = 9;
const int C1 = 10;
const int C2 = 11;
const int L1 = 12;
int estado = 1;
unsigned long timer = 0;

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(L1, OUTPUT);
}

void loop() {
  if(digitalRead(b2)){
    estado = 1;
  }

  switch (estado){
    case 1:
    digitalWrite(L1, 0);
    digitalWrite(M1, 0);
    digitalWrite(C1, 0);
    digitalWrite(C2, 1);
    
    if(!digitalRead(b1)){
      digitalWrite(L1, 1);
      digitalWrite(M1, 1);
      digitalWrite(C1, 1);
      estado = 2;
    }

    break;

    case 2:
    if(digitalRead(S1)){
      digitalWrite(C1, 0);
      estado = 3;
    }

    break;

    case 3:
    if(digitalRead(S2)){
      digitalWrite(M1, 0);
      digitalWrite(C2, 0);
      estado = 4;
    }

    break;

    case 4:
    if(digitalRead(S3)){
      timer = millis();
      estado = 5;
    }

    break;

    case 5:
    if((millis() - timer) >= 6000){
      digitalWrite(C2, 1);
      if(!digitalRead(S3)){
        digitalWrite(M1, 1);
        estado = 6;
      }
    }

    break;

    case 6:
    if(digitalRead(S4)){
      digitalWrite(M1, 0);
      estado = 7;
    }

    break;

    case 7:
    if(!digitalRead(S4)){
      estado = 1;
    }
  }
}