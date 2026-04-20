/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Comparador analógico com dois níveis

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int sensor = A0;
const int led = 13;
unsigned long timer = 0;

void setup() {
  pinMode(led, OUTPUT);
  timer = millis();
}

void loop() {
  int leitura = analogRead(sensor);
  float valor_volt = (leitura/1023.0)*5;
  if(valor_volt >=4){
    digitalWrite(led, 1);
  }
  else if(valor_volt > 2){
   if((millis() - timer) >= 200){
     digitalWrite(led, 1);
     timer = millis();
    }
    else if((millis() - timer) >= 100){
      digitalWrite(led, 0);
    }
  }
  else if(valor_volt >= 0){
    digitalWrite(led, 0);
  }
}