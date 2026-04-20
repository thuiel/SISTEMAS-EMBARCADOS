/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Frequência Variável

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
	int valor = analogRead(sensor);
	float speed = ((valor/1023.0)*1900.0)+100;
	if((millis() - timer) >= (2*speed)){
		digitalWrite(led, 0);
		timer = millis();
	}
  else if((millis() - timer) >= speed){
    digitalWrite(led, 1);
  }
}
