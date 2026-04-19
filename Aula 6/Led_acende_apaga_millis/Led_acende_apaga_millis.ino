const int led = 8;     //Define a porta 13 com o nome led
bool estado = 0;     //Define a variável estadoled como 0 e prapara para aceitar 0 e 1
unsigned long tempo = 0;     //Define a variável tempo como 0 e prepara para aceitar apenas valores positivos

void setup() {
  pinMode(led, OUTPUT);     //Define led como uma saída
  Serial.begin(115200);
}

void loop() {
  unsigned long tempoatual = millis();
  if(tempoatual - tempo >= 1000)     //Se o tempo que o programa está rodando menos a variável tempo for maior que 1000 milisegundos
  {
    tempo = tempoatual;
    estado = !estado;
    digitalWrite(led, estado);
    Serial.println("1 segundo");
  }
}
