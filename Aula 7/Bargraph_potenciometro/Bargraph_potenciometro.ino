const int potenciometro = 14;
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
unsigned int valor_sensor = 0;
float valor_volts = 0;

void setup() {
  pinMode(potenciometro, INPUT);     //Define "potenciometro" como uma entrada
  pinMode(led1, OUTPUT);     //Define "led1" como uma saída
  pinMode(led2, OUTPUT);     //Define "led2" como uma saída
  pinMode(led3, OUTPUT);     //Define "led3" como uma saída
  Serial.begin(115200);     //Liga o monitor serial na velocidade de 115200
}

void loop() {
  valor_sensor = analogRead(potenciometro);     //Define "valor_sensor" com um valor analógico lido em "potenciometro"
  valor_volts = (valor_sensor*5.00)/1023;     //Converte o valor em bits do "valor_sensor" para volts e atualiza "valor_volts" com esse valor
  Serial.print("Valor analógico = ");     //Escreve "Valor analógico = " no monitor serial
  Serial.println(valor_sensor);     //Escreve o valor em "valor_sensor" no monitor serial
  Serial.print("Valor volts = ");     //Escreve "Valor volts = " no monitor serial
  Serial.println(valor_volts);     //Escreve o valor em "valor_volts" no monitor serial
  
  if(valor_volts < 1){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  }
  if((valor_volts >= 1) && (valor_volts < 2)){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  }
  if((valor_volts >= 2) && (valor_volts < 3)){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
  }
  if((valor_volts >= 3) && (valor_volts < 4)){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
  }
  if(valor_volts >= 4){
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
  }
}
