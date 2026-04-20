/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Sistema de Exaustão Termo-Controlado 

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int sensor = A0;
const int led1 = 8;
const int led2 = 9;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int leitura = analogRead(sensor);
  float valor_volts = (leitura/1023.0)*5;
  if(valor_volts < 1.5){
    analogWrite(led2, 51);
  }
  if(valor_volts >= 1.5){
    int brilho = (valor_volts*58)-35;
    analogWrite(led2, brilho);
    if(valor_volts == 5){
     digitalWrite(led1, 1);
    }
    else{
      digitalWrite(led1, 0);
    }
  }
}