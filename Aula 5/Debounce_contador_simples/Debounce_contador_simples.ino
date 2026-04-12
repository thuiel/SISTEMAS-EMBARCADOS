
const int botao = 2;      //botao assume o valor da porta 2
unsigned long int contador = 0;      //Inicia a variável contador com o valor de 0 e prepara para receber muitos valores positivos
bool valorbotao = 1;      //Prepara a variável "valorbotao" para receber valores de 0 e 1
bool ultimoestadobotao = 1;     //Prepara a variável "ultimoestadobotao" para receber valores de 0 e 1
unsigned long timer = 0;     //Define "timer" como 0 e prepara para receber apenas valores positivos
unsigned long debouncetimer = 50;     //Define o tempo do debounce como 50 milisegundos e prepara para receber apenas valores positivos

void setup() {
  pinMode(botao, INPUT_PULLUP);     //Define botao como entrada com pull up
  Serial.begin(115200);     //Inicializa o monitor serial com a velocidade de 1152200
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

      if(valorbotao == LOW)     //Se "valorbotao" for LOW
      {
       contador++;     //Adiciona 1 ao contador
       Serial.print("contagem: ");     //Imprime no monitor serial "contagem: "
       Serial.println(contador);     //Imprime no monitor serial o valor do contador
      }
    }
  }
  ultimoestadobotao = valorlido;      //Define o "ultimoestadobotao" com o valor de "valorlido"
}
