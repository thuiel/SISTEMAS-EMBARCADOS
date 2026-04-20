const int pot = A0;
const int led3 = 10;

int leituras[10];

void setup() {
  pinMode(led3, OUTPUT);
}

void loop() {
  long soma = 0;

  // Faz 10 leituras
  for (int i = 0; i < 10; i++) {
    leituras[i] = analogRead(pot);
    soma += leituras[i];
    delay(50); // pequeno intervalo entre leituras
  }

  // Calcula média
  int media = soma / 10;

  // Verifica condição
  if (media > 700) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  delay(200); // evita leitura contínua sem pausa
}