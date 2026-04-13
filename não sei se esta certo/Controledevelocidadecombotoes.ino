const int mais = 2;
const int menos = 3;
const int led = 5;

int velocidade = 0;

void setup() {
  pinMode(mais, INPUT_PULLUP);
  pinMode(menos, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(mais) == LOW) {
    velocidade += 25;
    if (velocidade > 255) velocidade = 255;
    delay(200);
  }

  if (digitalRead(menos) == LOW) {
    velocidade -= 25;
    if (velocidade < 0) velocidade = 0;
    delay(200);
  }

  analogWrite(led, velocidade);
}