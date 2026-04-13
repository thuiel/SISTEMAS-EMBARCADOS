const int ntc = A0;
const int led = 8;

unsigned long tempoAnterior = 0;
bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(ntc);

  if (valor > 600) { // ajuste conforme necessário
    if (millis() - tempoAnterior >= 100) {
      tempoAnterior = millis();
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  } else {
    digitalWrite(led, LOW);
  }
}