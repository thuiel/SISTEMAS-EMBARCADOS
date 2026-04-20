/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Esteira de Triagem de Lotes

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int botao1 = 2;
const int botao2 = 3;
const int led = 8;
const int debounce = 50;
bool valor1 = 1;
bool valor2 = 1;
bool estado = 1;
bool ultimo_estado1 = 1;
bool ultimo_estado = 1;
bool action = 0;
bool pausa = 0;
unsigned int contador = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  valor1 = digitalRead(botao1);

  if(valor1 != ultimo_estado1){
    if(valor1 == 0){
      action = 1;
      contador = 0;
      pausa = 0;
    }
  }
  if(contador == 20){
    action = 0;
  }

  if(action == 1){
    valor2 = digitalRead(botao2);

    if(pausa == 0){
      digitalWrite(led, 1);
    }
    else{
      digitalWrite(led, 0);
    }

    if(valor2 != ultimo_estado){
      timer1 = millis();
    }

    if((millis() - timer1) >= debounce){
      if(valor2 != estado){
        estado = valor2;

        if(estado == 0){
          contador++;

          if(contador % 5 == 0){
            pausa = 1;
            timer2 = millis();
          }
        }
      }
    }
    ultimo_estado = valor2;

    if(pausa == 1){
      if((millis() - timer2) >= 3000){
        pausa = 0;
      }
    }
  }
  else{
    digitalWrite(led, 0);
  }
  ultimo_estado1 = valor1;
}
