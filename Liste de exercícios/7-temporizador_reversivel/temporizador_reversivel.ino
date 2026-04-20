/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Temporizador Reversível

Autor: Tiago Fortunato Rosset
Data: 11/04/2026
Versão: 1.0

************************************************************************ */

const int botao1 = 2;
const int botao2 = 3;
const int led = 8;
unsigned int timer = 0;
bool estado1 = 1;
bool estado2 = 1;
bool tempo = 0;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
	pinMode(botao2, INPUT_PULLUP);
	pinMode(led, OUTPUT);
}

void loop() {
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);
  if(estado1 == LOW){
    tempo = 1;
    timer = millis();
  }
  if(estado2 == LOW){
  	tempo = 0;
  }
  if(tempo == 1){
 	  if((millis() - timer) >= 5000){
      digitalWrite(led, 0);
    }
    else{
    digitalWrite(led,1);
    }
  }
  else{
    digitalWrite(led, 0);
  }

}
