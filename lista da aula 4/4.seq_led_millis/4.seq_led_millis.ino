const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

unsigned long tempoAnterior = 0;
const int intervalo = 500; // tempo entre LEDs (ms)

int estadoLED = 0; // controla qual LED está ativo

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // Apaga todos os LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    // Liga apenas um LED por vez
    if (estadoLED == 0) {
      digitalWrite(led1, HIGH);
    } else if (estadoLED == 1) {
      digitalWrite(led2, HIGH);
    } else if (estadoLED == 2) {
      digitalWrite(led3, HIGH);
    } else if (estadoLED == 3) {
      digitalWrite(led4, HIGH);
    }

    // Vai para o próximo LED
    estadoLED++;

    // Volta para o primeiro
    if (estadoLED > 3) {
      estadoLED = 0;
    }
  }
}