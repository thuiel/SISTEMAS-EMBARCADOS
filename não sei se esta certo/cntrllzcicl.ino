const int botao = 2;
const int led = 5;

int nivel = 0;
bool estadoAnterior = HIGH;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool estadoAtual = digitalRead(botao);

  if (estadoAnterior == HIGH && estadoAtual == LOW) {
    nivel += 51; // 0, 51, 102, 153, 204, 255
    if (nivel > 255) nivel = 0;
    analogWrite(led, nivel);
  }

  estadoAnterior = estadoAtual;
}