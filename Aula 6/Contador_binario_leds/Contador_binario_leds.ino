const int botao1 = 2;     //botao assume o valor da porta 2
const int botao2 = 3;     //botao assume o valor da porta 3
const int led1 = 8;     //led1 assume o valor da porta 8
const int led2 = 9;     //led2 assume o valor da porta 9
const int led3 = 10;     //led3 assume o valor da porta 10
const int led4 = 11;     //led4 assume o valor da porta 11
int contador = 0;     //Cria um contador que inicia no valor 0
bool valorbotao1 = HIGH;     //Prepara a variável "valorbotao1" para receber valores de 0 e 1
bool valorbotao2 = HIGH;     //Prepara a variável "valorbotao2" para receber valores de 0 e 1
bool ultimoestadobotao1 = 1;     //Prepara a variável "ultimoestadobotao1" para receber valores de 0 e 1
bool ultimoestadobotao2 = 1;     //Prepara a variável "ultimoestadobotao2" para receber valores de 0 e 1
unsigned long timer1 = 0;     //Define "timer1" como 0 e prepara para receber apenas valores positivos
unsigned long timer2 = 0;     //Define "timer2" como 0 e prepara para receber apenas valores positivos
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
      if(contador < 15)
      {
        contador++;     //Adiciona 1 ao contador
      }
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
      if(contador > 0)
      {
        contador--;     //Subtrai 1 ao contador
      }
    }
    }
  }
  if(contador == 0){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  if(contador == 1){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }
  if(contador == 2){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  if(contador == 3){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }
  if(contador == 4){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  if(contador == 5){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }
  if(contador == 6){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  if(contador == 7){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }
  if(contador == 8){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  if(contador == 9){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }
  if(contador == 10){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  if(contador == 11){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }
  if(contador == 12){
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  if(contador == 13){
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }
  if(contador == 14){
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  if(contador == 15){
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }
  ultimoestadobotao1 = valorlido1;      //Define o "ultimoestadobotao1" com o valor de "valorlido1"
  ultimoestadobotao2 = valorlido2;      //Define o "ultimoestadobotao2" com o valor de "valorlido2"
}
