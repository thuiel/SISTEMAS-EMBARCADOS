int led = 3;
int pot = A0;

unsigned long tempo = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot); // 0 a 1023

  // Conversão precisa de tensão para leitura analógica:
  int nivel1 = 1023 * 2.0 / 5.0; // 2,0 V
  int nivel2 = 1023 * 4.0 / 5.0; // 4,0 V

  if (valor <= nivel1) {
    // ≤ 2V → LED desligado
    digitalWrite(led, LOW);
  }
  else if (valor < nivel2) {
    // entre 2V e 4V → LED piscando
    if (millis() - tempo >= 500) {
      tempo = millis();
      digitalWrite(led, !digitalRead(led));
    }
  }
  else {
    // ≥ 4V → LED ligado
    digitalWrite(led, HIGH);
  }
}