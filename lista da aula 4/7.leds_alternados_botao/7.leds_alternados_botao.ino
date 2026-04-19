const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

const int botao1 = 2;
const int botao2 = 3;

unsigned long tempoAnterior = 0;
const int intervalo = 300;

bool modoEfeito = false; // controla se está ativo
bool estadoPar = false;  // controla qual par está ligado

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  // Leitura dos botões
  if (digitalRead(botao1) == LOW) {
    modoEfeito = true;
  }

  if (digitalRead(botao2) == LOW) {
    modoEfeito = false;

    // apaga tudo ao sair do modo
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // Se modo efeito estiver ativo
  if (modoEfeito) {
    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      // alterna entre os pares
      estadoPar = !estadoPar;

      if (estadoPar) {
        // LED1 + LED3
        digitalWrite(led1, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led4, LOW);
      } else {
        // LED2 + LED4
        digitalWrite(led1, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led4, HIGH);
      }
    }
  }
}