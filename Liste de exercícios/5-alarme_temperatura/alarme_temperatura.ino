/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Alarme de Temperatura Simples

Autor: Tiago Fortunato Rosset
Data: 11/04/2026
Versão: 1.0

************************************************************************ */

const int sensor = A0;
const int led = 8;
unsigned int timer = 0;

void setup() {
  pinMode(led, OUTPUT);
	timer = millis();
}

void loop() {
  unsigned int leitura = analogRead(sensor);
  float temp = (leitura*5.0)/1023;
  if(temp > 2.5){
    if((millis() - timer) >= 200){
      digitalWrite(led, 0);
      timer = millis();
    }
    else if((millis() - timer) >= 100){
      digitalWrite(led, 1);
    }
  }
  else{
    digitalWrite(led, 0);
  }
}
