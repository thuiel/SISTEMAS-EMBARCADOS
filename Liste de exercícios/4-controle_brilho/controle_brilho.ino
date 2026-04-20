/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Controle de Brilho Cíclico

Autor: Tiago Fortunato Rosset
Data: 10/0/2026
Versão: 1.0

************************************************************************ */

const int botao = 2;
const int led = 9;
const int debounce = 50;
int contador = 0;
bool estadobotao = 1;
bool ultimoestado = 1;
unsigned long timer = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool valor = digitalRead(botao);
  if(valor != ultimoestado){
    timer = millis();
  }
  if((millis() - timer) >= debounce){
    if(estadobotao != valor){
      estadobotao = valor;
      if(estadobotao == LOW){
        if(contador == 4){
          contador = 0;
        }
        else{
          contador++;
        }
      }
    }
  }
  switch(contador){
    case 0:
      analogWrite(led, 0);
      break;

    case 1:
      analogWrite(led, 63);
      break;

    case 2:
      analogWrite(led, 127);
      break;

    case 3:
      analogWrite(led, 191);
      break;

    default:
      analogWrite(led, 255);
      break;
  }
  ultimoestado = valor;
}