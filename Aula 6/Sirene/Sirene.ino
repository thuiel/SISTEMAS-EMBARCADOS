const int botao1 = 2;     //botao assume o valor da porta 2
const int botao2 = 3;     //botao assume o valor da porta 3
const int led1 = 8;     //led1 assume o valor da porta 8
const int led2 = 9;     //led2 assume o valor da porta 9
const int led3 = 10;     //led3 assume o valor da porta 10
const int led4 = 11;     //led4 assume o valor da porta 11
bool teste = 0;      //Cria uma variável booleana chamada teste
bool valorbotao1 = HIGH;     //Prepara a variável "valorbotao1" para receber valores de 0 e 1
bool valorbotao2 = HIGH;     //Prepara a variável "valorbotao2" para receber valores de 0 e 1
bool ultimoestadobotao1 = 1;     //Prepara a variável "ultimoestadobotao1" para receber valores de 0 e 1
bool ultimoestadobotao2 = 1;     //Prepara a variável "ultimoestadobotao2" para receber valores de 0 e 1
unsigned long timer1 = 0;     //Define "timer1" como 0 e prepara para receber apenas valores positivos
unsigned long timer2 = 0;     //Define "timer2" como 0 e prepara para receber apenas valores positivos
unsigned long timer3 = 0;     //Define "timer3" como 0 e prepara para receber apenas valores positivos
unsigned long debouncetimer = 50;     //Define o tempo do debounce como 50 milisegundos e prepara para receber apenas valores positivos

void setup() {
  pinMode(botao1, INPUT_PULLUP);     //Define botao1 como entrada com pull up
  pinMode(botao2, INPUT_PULLUP);     //Define botao2 como entrada com pull up
  pinMode(led1, OUTPUT);     //Define led1 como saída
  pinMode(led2, OUTPUT);     //Define led2 como saída
  pinMode(led3, OUTPUT);     //Define led3 como saída
  pinMode(led4, OUTPUT);     //Define led4 como saída
}

void loop() {
  int valorlido1 = digitalRead(botao1);     //Lê o estado do botao1
  int valorlido2 = digitalRead(botao2);     //Lê o estado do botao2

  if(valorlido1 != ultimoestadobotao1)     //Se o valor lido no pino 3 for diferente do "ultimoestadobotao1"
  {
    timer1 = millis();     //Varia "timer1" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer1) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer1" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido1 != valorbotao1)     //Se o valor lido for diferente do valor em "valorbotao"
    {
      valorbotao1 = valorlido1;     //"valorbotao" passa a ter o valor de "valorlido"

    if(valorbotao1 == LOW)     //Se "valorbotao" for LOW
    {
      teste = 1;      //Define a variável "teste" como 1
      timer3 = millis();      //"timer3" tem seu valor atualizado para o de millis()
    }
    }
  }
  if(valorlido2 != ultimoestadobotao2)     //Se o valor lido no pino 2 for diferente do "ultimoestadobotao2"
  {
    timer2 = millis();     //Varia "timer2" de acordo com um cronômetro em milisegundos
  }
  
  if((millis() - timer2) > debouncetimer)      //Se do valor de um cronômetro em milisegundos é subtraido o valor de "timer2" e o resultado for maior que o tempo definido no "debouncetimer"
  {
    if(valorlido2 != valorbotao2)     //Se o valor lido for diferente do valor em "valorbotao2"
    {
      valorbotao2 = valorlido2;     //"valorbotao2" passa a ter o valor de "valorlido2"

    if(valorbotao2 == LOW)     //Se "valorbotao2" for LOW
    {
      teste = 0;      //Define a variável "teste" como 0
    }
    }
  }
  if(teste == 1){      //Se "teste" for 1
      if((millis() - timer3) == 300){
        digitalWrite(led1, 0);      //Define o valor do led1 como LOW
        digitalWrite(led2, 1);      //Define o valor do led2 como HIGH
        digitalWrite(led3, 0);      //Define o valor do led3 como LOW
        digitalWrite(led4, 1);      //Define o valor do led4 como HIGH
      }
      if((millis() - timer3) >= 600){
        digitalWrite(led1, 1);      //Define o valor do led1 como HIGH
        digitalWrite(led2, 0);      //Define o valor do led2 como LOW
        digitalWrite(led3, 1);      //Define o valor do led3 como HIGH
        digitalWrite(led4, 0);      //Define o valor do led4 como LOW
        timer3 = millis();
      }
   }
  if(teste == 0){      //Se "teste" for 0
      digitalWrite(led1, 0);      //Define o valor do led1 como LOW
      digitalWrite(led2, 0);      //Define o valor do led2 como LOW
      digitalWrite(led3, 0);      //Define o valor do led3 como LOW
      digitalWrite(led4, 0);      //Define o valor do led4 como LOW
    }
  ultimoestadobotao1 = valorlido1;      //Define o "ultimoestadobotao1" com o valor de "valorlido1"
  ultimoestadobotao2 = valorlido2;      //Define o "ultimoestadobotao2" com o valor de "valorlido2"
}
