/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 15, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 14/06/2026
Versão: 1.0

************************************************************************ */

const int SA = 2;
const int SB = 3;
const int CR = 8;
bool valor_SA = 0;
bool valor_SB = 0;
int estado = 1;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;

void setup() {
  pinMode(SA, INPUT);
  pinMode(SB, INPUT);
  pinMode(CR, OUTPUT);
}

void loop() {
  valor_SA = digitalRead(SA);
  valor_SB = digitalRead(SB);

  switch (estado){
    case 1:
    digitalWrite(CR, 0);
    if(valor_SA && valor_SB){
      estado = 2;
    }
    else if(valor_SA && !valor_SB){
      timer1 = millis();
      estado = 3;
    }
    else if(!valor_SA && valor_SB){
      timer2 = millis();
      estado = 4;
    }

    break;

    case 2:
    digitalWrite(CR, 1);
    if(!valor_SA || !valor_SB){
      digitalWrite(CR, 0);
      timer3 = millis();
      estado = 5;
    }

    break;

    case 3:
    if((millis() - timer1) <= 3000){
      if(valor_SB){
        estado = 2;
      }
    }
    else if(!valor_SA && !valor_SB){
      estado = 1;
    }

    break;

    case 4:
    if((millis() - timer2) <= 3000){
      if(valor_SA){
        estado = 2;
      }
    }
    else  if(!valor_SA && !valor_SB){
      estado = 1;
    }

    break;

    case 5:
    if((millis() - timer3) <= 3000){
      if(valor_SA && valor_SB){
        estado = 2;
      }
    }
    else if(!valor_SA && !valor_SB){
      estado = 1;
    }

    break;
  }
}