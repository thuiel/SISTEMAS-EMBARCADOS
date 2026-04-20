/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Sequenciador de Partida

Autor: Tiago Fortunato Rosset
Data: 12/04/2026
Versão: 1.0

************************************************************************ */

const int botao = 2;
const int botao2 = 3;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
bool valorbotao = 1;      //Prepara a variável "valorbotao" para receber valores de 0 e 1
bool valorbotao2 = 1;      //Prepara a variável "valorbotao2" para receber valores de 0 e 1
bool ultimoestadobotao = 1;     //Prepara a variável "ultimoestadobotao" para receber valores de 0 e 1
bool ultimoestadobotao2 = 1;     //Prepara a variável "ultimoestadobotao2" para receber valores de 0 e 1
bool action = 0;
unsigned long timer = 0;     //Define "timer" como 0 e prepara para receber apenas valores positivos
unsigned long timer1 = 0;     //Define "timer1" como 0 e prepara para receber apenas valores positivos
unsigned long timer2 = 0;
const int debouncetimer = 50;     //Define o tempo do debounce como 50 milisegundos e prepara para receber apenas valores positivos

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  bool valorlido = digitalRead(botao);     //Lê o estado do botao
  bool valorlido2 = digitalRead(botao2);     //Lê o estado do botao2

  if(valorlido != ultimoestadobotao)     //Se o valor lido no pino 2 for diferente do "ultimoestadobotao"
  {
    timer = millis();     //Varia "timer" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido != valorbotao)     //Se o valor lido for diferente do valor em "valorbotao"
    {
      valorbotao = valorlido;     //"valorbotao" passa a ter o valor de "valorlido"

      if(valorbotao == LOW)     //Se "valorbotao" for LOW
      {
        timer2 = millis();
        action = 1;
      }
    }
  }
  if(valorlido2 != ultimoestadobotao2)     //Se o valor lido no pino 2 for diferente do "ultimoestadobotao"
  {
    timer1 = millis();     //Varia "timer" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer1) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido2 != valorbotao2)     //Se o valor lido for diferente do valor em "valorbotao"
    {
      valorbotao2 = valorlido2;     //"valorbotao" passa a ter o valor de "valorlido"

      if(valorbotao2 == LOW)     //Se "valorbotao" for LOW
      {
        action = 0;
      }
    }
  }
  if(action == 1){
    if((millis() - timer2) >= 4000){
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 1);
      timer2 = millis();
    }
    else if((millis() - timer2) >= 3000){
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
    }
    else if((millis() - timer2) >= 2000){
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
    else if((millis() - timer2) >= 1000){
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
  }
  else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  ultimoestadobotao = valorlido;      //Define o "ultimoestadobotao" com o valor de "valorlido"
  ultimoestadobotao2 = valorlido2;      //Define o "ultimoestadobotao2" com o valor de "valorlido2"
}