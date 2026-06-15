/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Exercício 3, Máquina de estados finitos

Autor: Tiago Fortunato Rosset
Data: 11/06/2026
Versão: 1.0

************************************************************************ */

const int botao_1 = 2;
const int botao_2 = 3;
const int sensor_ST1 = 4;
const int sensor_ST2 = 5;
const int sensor_SR = 6;
const int sensor_SA = 7;
const int sensor_SP1 = 8;
const int sensor_SP2 = 9;
const int M1 = 10;
const int CR = 11;
const int alarme_FT = 12;
const int alarme_FC = 13;
bool valor_botao_1 = !digitalRead(botao_1);
bool valor_botao_2 = digitalRead(botao_2);
bool valor_sensor_ST1 = digitalRead(sensor_ST1);
bool valor_sensor_SR = digitalRead(sensor_SR);
bool valor_sensor_SA = digitalRead(sensor_SA);
int estado = 1;
unsigned int contagem = 0;
unsigned long timer = millis();

void setup() {
  pinMode(botao_1, INPUT_PULLUP);
  pinMode(botao_2, INPUT_PULLUP);
  pinMode(sensor_ST1, INPUT);
  pinMode(sensor_ST2, INPUT);
  pinMode(sensor_SR, INPUT);
  pinMode(sensor_SA, INPUT);
  pinMode(sensor_SP1, INPUT);
  pinMode(sensor_SP2, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(CR, OUTPUT);
  pinMode(alarme_FT, OUTPUT);
  pinMode(alarme_FC, OUTPUT);
}

void loop() {
  valor_botao_1 = !digitalRead(botao_1);
  valor_botao_2 = digitalRead(botao_2);
  valor_sensor_ST1 = !digitalRead(sensor_ST1);

  if(valor_botao_2){
    digitalWrite(M1, 0);
    digitalWrite(CR, 0);
    estado = 1;
  }
  if(valor_sensor_ST1){
    digitalWrite(alarme_FT, 1);
  }
  else{
    digitalWrite(alarme_FT, 0);
  }
  if(contagem == 24){
    estado = 1;
  }

  switch (estado){
    case 1:
    if(valor_botao_1){
      digitalWrite(alarme_FC, 0);
      estado = 2;
      if(contagem == 24){
        contagem = 0;
      }
    }

    break;

    case 2:
    if(!valor_sensor_ST1){
      digitalWrite(M1, 1);
      estado = 3;
    }
    else{
      digitalWrite(M1, 0);
    }

    break;

    case 3:
    if(digitalRead(sensor_SP1)){
      digitalWrite(M1, 0);
      if(digitalRead(sensor_SR)){
        digitalWrite(CR, 1);
        estado = 4;
      }
    }

    break;

    case 4:
    if(digitalRead(sensor_SA)){
      timer = millis();
      estado = 5;
    }

    break;

    case 5:
    if((millis() - timer) >= 2000){
        digitalWrite(CR, 0);
        if(digitalRead(sensor_SR)){
          estado = 6;
        }
    }

    break;

    case 6:
    if(digitalRead(sensor_SP2)){
      if(digitalRead(sensor_ST2)){
        contagem++;
        estado = 2;
      }
      else{
        digitalWrite(alarme_FC, 1);
        estado = 1;
      }
    }

    break;
  }
}