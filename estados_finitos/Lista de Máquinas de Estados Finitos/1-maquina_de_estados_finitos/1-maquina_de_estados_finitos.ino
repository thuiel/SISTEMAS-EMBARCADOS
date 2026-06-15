/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 1, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 11/06/2026
Versão: 1.0

************************************************************************ */

const int botao_man_aut = 2;
const int botao1 = 3;
const int botao2 = 4;
const int sensor1 = 5;
const int sensor2 = 6;
const int bomba = 8;
unsigned int estado = 1;
bool man_aut = 0;
bool man_aut_ant = 0;
bool valor1 = 0;
bool valor2 = 0;
bool leitura1_ant = 0;
bool leitura2_ant = 1;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void setup() {
  pinMode(botao_man_aut, INPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(bomba, OUTPUT);
  digitalWrite(bomba, 0);
}

void loop() {
  man_aut = !digitalRead(botao_man_aut);
  valor1 = !digitalRead(botao1);
  valor2 = !digitalRead(botao2);
  bool leitura1 = digitalRead(sensor1);
  bool leitura2 = digitalRead(sensor2);

  if(man_aut != man_aut_ant){
    if(man_aut){
     estado = 1;
    }
    else{
      estado = 2;
    }
  }
  man_aut_ant = man_aut;

  switch (estado){

    case 1:
    if(valor2){
      digitalWrite(bomba, 0);
    }
    else if(valor1){
      digitalWrite(bomba, 1);
    }

    break;

    case 2:
    if(valor2){
      digitalWrite(bomba, 0);
    }
    else if(valor1){
      estado = 3;
    }

    break;

    case 3:
    if(leitura1 && !leitura1_ant){
      timer1 = millis();
      estado = 4;
    }
    else if(!leitura2 && leitura2_ant){
      timer2 = millis();
      estado = 5;
    }

    leitura1_ant = leitura1;
    leitura2_ant = leitura2;

    break;

    case 4:
    if((millis() - timer1) >= 10000){
      digitalWrite(bomba, 0);
      estado = 3;
    }

    break;

    case 5:
    if((millis() - timer2) >= 10000){
      digitalWrite(bomba, 1);
      estado = 3;
    }

    break;
  }
}