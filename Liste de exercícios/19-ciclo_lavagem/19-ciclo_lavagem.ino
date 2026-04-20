/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Ciclo de Lavagem Industrial

Autor: Tiago Fortunato Rosset
Data: 18/04/2026
Versão: 1.0

************************************************************************ */

const int botao = 2;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
bool action = 0;
bool valorbotao = 1;      //Prepara a variável "valorbotao" para receber valores de 0 e 1
bool ultimoestadobotao = 1;     //Prepara a variável "ultimoestadobotao" para receber valores de 0 e 1
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer = 0;     //Define "timer" como 0 e prepara para receber apenas valores positivos
unsigned long debouncetimer = 50;     //Define o tempo do debounce como 50 milisegundos e prepara para receber apenas valores positivos

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int valorlido = digitalRead(botao);     //Lê o estado do botao

  if(valorlido != ultimoestadobotao)     //Se o valor lido no pino 2 for diferente do "ultimoestadobotao"
  {
    timer = millis();     //Varia "timer" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido != valorbotao)     //Se o valor lido for diferente do valor em "valorbotao"
    {
      valorbotao = valorlido;     //"valorbotao" passa a ter o valor de "valorlido"

      if(valorbotao == LOW && !action)     //Se "valorbotao" for LOW
      {
        action = 1;
        timer2 = millis();
        timer3 = millis();
      }
    }
  }
  if(action){
    if((millis() - timer2) >= 16000){
    digitalWrite(led4, 0);
    action = 0;
  }
  else if((millis() - timer2) >= 12000){
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }
  else if((millis() - timer2) >= 4000){
    digitalWrite(led1, 0);
    if((millis() - timer3) >= 200){
      analogWrite(led2, 128);
      analogWrite(led3, 0);
      timer3 = millis();
    }
    else if((millis() - timer3) >= 100){
      analogWrite(led2, 0);
      analogWrite(led3, 128);
    }
  }
  else if((millis() - timer2) >= 0){
    digitalWrite(led1, 1);
  }
  }
  else{
    digitalWrite(led4, 0);
  }
  ultimoestadobotao = valorlido;      //Define o "ultimoestadobotao" com o valor de "valorlido"
}