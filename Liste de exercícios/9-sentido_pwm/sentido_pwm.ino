/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Indicador de Sentido PWM

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int sensor = A0;
const int led = 9;

void setup() {

}

void loop() {
  int leitura = ((analogRead(sensor))/2)-255;
  int brilho = abs(leitura);
  analogWrite(led, brilho);
}
