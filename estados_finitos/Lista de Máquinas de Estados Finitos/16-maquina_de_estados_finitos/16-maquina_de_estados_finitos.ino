/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 16, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 14/06/2026
Versão: 1.0

************************************************************************ */

const int bL = 2;
const int bD = 3;
const int SPe = 4;
const int SM = 5;
const int SG = 6;
const int SA = 7;
const int SB = 8;
const int SC = 9;
const int ME = 10;
const int AL = 11;
bool valor_SA = 0;
bool valor_SB = 0;
bool valor_SC = 0;
int estado = 1;

void setup() {
  pinMode(bL, INPUT_PULLUP);
  pinMode(bD, INPUT_PULLUP);
  pinMode(SPe, INPUT);
  pinMode(SM, INPUT);
  pinMode(SG, INPUT);
  pinMode(SA, INPUT);
  pinMode(SB, INPUT);
  pinMode(SC, INPUT);
  pinMode(ME, OUTPUT);
  pinMode(AL, OUTPUT);
}

void loop() {
  valor_SA = digitalRead(SA);
  valor_SB = digitalRead(SB);
  valor_SC = digitalRead(SC);

  if(digitalRead(bD)){
    digitalWrite(AL, 0);
    estado = 1;
  }

  switch (estado){
    case 1:
    if(!digitalRead(bL)){
      digitalWrite(AL, 0);
      digitalWrite(ME, 1);
      if(digitalRead(SPe)){
        estado = 2;
      }
      else if(digitalRead(SM)){
        estado = 3;
      }
      else if(digitalRead(SG)){
        estado  = 4;
      }
    }

    break;

    case 2:
    if(valor_SC || valor_SB){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }

    break;

    case 3:
    if(valor_SC){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }
    else if(valor_SA && !valor_SB){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }
    else if(!valor_SA && valor_SB){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }

    break;

    case 4:
    if(valor_SA && (!valor_SB || !valor_SC)){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }
    else if((valor_SB || valor_SC) && !valor_SA){
      digitalWrite(AL, 1);
      digitalWrite(ME, 0);
      estado = 1;
    }
  }
}