const int botao = 2;
const int led1 = 8;

void setup() {
  pinMode(botao, INPUT_PULLUP); //pullup liga apenas o negativo no botao sem resisto ou 5v
  pinMode(led1, OUTPUT);
}

void loop() {
  int valorlido = digitalRead(botao);

  if(valorlido == 0) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}