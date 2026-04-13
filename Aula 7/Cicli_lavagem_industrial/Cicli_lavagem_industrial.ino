// LEDs
int led1 = 2; // Enchimento
int led2 = 3; // Lavagem
int led3 = 5; // Lavagem (PWM)
int led4 = 6; // Drenagem

int botaoA = 7;

// Controle de tempo
unsigned long tempo = 0;

// Estados do sistema
int etapa = 0; // 0 = parado, 1 = enchimento, 2 = lavagem, 3 = drenagem

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botaoA, INPUT);
}

void loop() {

  // =====================================
  // INICIAR CICLO (somente se estiver parado)
  // =====================================
  if (digitalRead(botaoA) == HIGH && etapa == 0) {
    etapa = 1;            // vai para enchimento
    tempo = millis();     // marca o início
  }

  // =====================================
  // ETAPA 1 → ENCHIMENTO (4 segundos)
  // =====================================
  if (etapa == 1) {
    digitalWrite(led1, HIGH); // LED 1 ligado

    if (millis() - tempo >= 4000) {
      digitalWrite(led1, LOW); // desliga
      etapa = 2;               // próxima etapa
      tempo = millis();        // reinicia tempo
    }
  }

  // =====================================
  // ETAPA 2 → LAVAGEM (8 segundos)
  // LEDs piscando alternado com PWM (50%)
  // =====================================
  if (etapa == 2) {

    // alterna a cada 500 ms
    if ((millis() / 500) % 2 == 0) {
      analogWrite(led2, 128); // 50% brilho
      analogWrite(led3, 0);
    } else {
      analogWrite(led2, 0);
      analogWrite(led3, 128); // 50% brilho
    }

    if (millis() - tempo >= 8000) {
      analogWrite(led2, 0);
      analogWrite(led3, 0);
      etapa = 3;           // próxima etapa
      tempo = millis();
    }
  }

  // =====================================
  // ETAPA 3 → DRENAGEM (4 segundos)
  // =====================================
  if (etapa == 3) {
    analogWrite(led4, 255); // LED 4 ligado

    if (millis() - tempo >= 4000) {
      analogWrite(led4, 0);
      etapa = 0; // volta para estado parado
    }
  }
}