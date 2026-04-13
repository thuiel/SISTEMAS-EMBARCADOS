const int sensor = 14;     //Define o pino 14(A0) como "sensor"
unsigned int valor_sensor = 0;     //Define "valor_sensor" como uma variável que recebe valores positivos
float valor_volts = 0;     //Define "valor_volts" como uma variável que recebe valores com casa decimal

void setup() {
  pinMode(sensor, INPUT);     //Define "sensor" como uma entrada
  Serial.begin(115200);     //Liga o monitor serial na velocidade de 115200
}

void loop() {
  valor_sensor = analogRead(sensor);     //Define "valor_sensor" com um valor analógico lido em "sensor"
  valor_volts = (valor_sensor*5.00)/1023;     //Converte o valor em bits do "valor_sensor" para volts e atualiza "valor_volts" com esse valor
  Serial.print("Valor analógico = ");     //Escreve "Valor analógico = " no monitor serial
  Serial.println(valor_sensor);     //Escreve o valor em "valor_sensor" no monitor serial
  Serial.print("Valor volts = ");     //Escreve "Valor volts = " no monitor serial
  Serial.println(valor_volts);     //Escreve o valor em "valor_volts" no monitor serial

  delay(200);     //Define uma pausa de 200 milisegundos
}