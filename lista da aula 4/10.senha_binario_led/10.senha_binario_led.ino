const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

const int botao0 = 2; // bit 0
const int botao1 = 3; // bit 1

int senha[4] = {1, 0, 1, 0}; // 1 = botao1 | 0 = botao0
int entrada[4];

int indice = 0;

// controle de botão
bool ultimoB0 = HIGH;
bool ultimoB1 = HIGH;

// estados
bool verificando = false;
bool sucessoAtivo = false;
bool erroAtivo = false;

// tempo
unsigned long tempoAnterior = 0;
int piscadas = 0;
bool estadoLED = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(botao0, INPUT_PULLUP);
  pinMode(botao1, INPUT_PULLUP);
}

void loop() {

  if (!verificando && !sucessoAtivo && !erroAtivo) {
    lerEntrada();
  }

  if (verificando) {
    verificarSenha();
  }

  if (sucessoAtivo) {
    sucesso();
  }

  if (erroAtivo) {
    erro();
  }
}

// ================= ENTRADA =================
void lerEntrada() {
  bool b0 = digitalRead(botao0);
  bool b1 = digitalRead(botao1);

  if (ultimoB0 == HIGH && b0 == LOW) {
    entrada[indice] = 0;
    indice++;
  }

  if (ultimoB1 == HIGH && b1 == LOW) {
    entrada[indice] = 1;
    indice++;
  }

  ultimoB0 = b0;
  ultimoB1 = b1;

  if (indice == 4) {
    verificando = true;
  }
}

// ================= VERIFICAÇÃO =================
void verificarSenha() {
  bool correto = true;

  if (entrada[0] != senha[0]) correto = false;
  if (entrada[1] != senha[1]) correto = false;
  if (entrada[2] != senha[2]) correto = false;
  if (entrada[3] != senha[3]) correto = false;

  verificando = false;

  if (correto) {
    sucessoAtivo = true;
    tempoAnterior = millis();
  } else {
    erroAtivo = true;
    tempoAnterior = millis();
    piscadas = 0;
  }
}

// ================= SUCESSO =================
void sucesso() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);

  if (millis() - tempoAnterior >= 2000) {
    apagar();
    resetar();
  }
}

// ================= ERRO =================
void erro() {
  if (millis() - tempoAnterior >= 150) {
    tempoAnterior = millis();

    estadoLED = !estadoLED;

    digitalWrite(led1, estadoLED);
    digitalWrite(led2, estadoLED);
    digitalWrite(led3, estadoLED);
    digitalWrite(led4, estadoLED);

    piscadas++;

    if (piscadas > 10) {
      apagar();
      resetar();
    }
  }
}

// ================= AUX =================
void apagar() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void resetar() {
  indice = 0;
  sucessoAtivo = false;
  erroAtivo = false;
}