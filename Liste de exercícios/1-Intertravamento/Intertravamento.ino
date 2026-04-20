/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Intertravamento de Segurança

Autor: Tiago Fortunato Rosset
Data: 10/0/2026
Versão: 1.0

************************************************************************ */

const int botao1 = 2;      //botao1 assume o valor da porta 2
const int botao2 = 3;      //botao2 assume o valor da porta 3
const int led = 8;
bool valorbotao1 = 1;      //Prepara a variável "valorbotao1" para receber valores de 0 e 1
bool ultimoestadobotao1 = 1;     //Prepara a variável "ultimoestadobotao1" para receber valores de 0 e 1
unsigned long timer = 0;     //Define "timer" como 0
const int debouncetimer = 50;     //Define o tempo do debounce como 50 milisegundos

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool valorbotao2 = digitalRead(botao2);     //Lê o estado do botão2

  if(valorbotao2 == HIGH){

  bool valorlido = digitalRead(botao1);     //Lê o estado do botao1

  if(valorlido != ultimoestadobotao1)     //Se o valor lido no pino 2 for diferente do "ultimoestadobotao1"
  {
    timer = millis();     //Varia "timer" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido != valorbotao1)     //Se o valor lido for diferente do valor em "valorbotao1"
    {
      valorbotao1 = valorlido;     //"valorbotao1" passa a ter o valor de "valorlido"

    if(valorbotao1 == LOW)     //Se "valorbotao1" for LOW
    {
      digitalWrite(led, 1);
    }
    }
  }
  ultimoestadobotao1 = valorlido;      //Define o "ultimoestadobotao" com o valor de "valorlido"
  }
  else{
    digitalWrite(led, 0);
  }
}