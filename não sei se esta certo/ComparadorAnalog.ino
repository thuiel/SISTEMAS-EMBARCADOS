const int pot = A0;
const int led = 5;

unsigned long tempoAnterior = 0;
bool estado = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  float tensao = valor * (5.0 / 1023.0);

  if (tensao <= 2.0) {
    digitalWrite(led, LOW);
  }
  else if (tensao < 4.0) {
    if (millis() - tempoAnterior >= 500) {
      tempoAnterior = millis();
      estado = !estado;
      digitalWrite(led, estado);
    }
  }
  else {
    digitalWrite(led, HIGH);
  }
}