const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

const int botao1 = 2;
const int botao2 = 3;

// sequência fixa
int sequencia[3] = {1, 3, 2};
int entradaUsuario[3];

int indiceEntrada = 0;

bool jogando = false;

// controle de botões
bool ultimoB1 = HIGH;
bool ultimoB2 = HIGH;

// controle de tempo
unsigned long tempoAnterior = 0;
int etapa = 0;

// controle duplo clique
bool aguardandoSegundoClique = false;
unsigned long tempoClique = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  if (!jogando) {
    mostrarSequencia();
  } else {
    lerEntrada();
  }
}

// ================= MOSTRAR SEQUÊNCIA =================
void mostrarSequencia() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= 700) {
    tempoAnterior = tempoAtual;

    apagarLeds();

    if (etapa < 3) {
      acenderLed(sequencia[etapa]);
      etapa++;
    } else {
      etapa = 0;
      jogando = true;
    }
  }
}

// ================= LER ENTRADA =================
void lerEntrada() {
  bool b1 = digitalRead(botao1);
  bool b2 = digitalRead(botao2);

  // botão 1 = LED1
  if (ultimoB1 == HIGH && b1 == LOW) {
    registrarEntrada(1);
  }

  // ===== BOTÃO 2 (duplo clique corrigido) =====
  if (ultimoB2 == HIGH && b2 == LOW) {
    if (!aguardandoSegundoClique) {
      aguardandoSegundoClique = true;
      tempoClique = millis();
    } else {
      registrarEntrada(3); // duplo clique
      aguardandoSegundoClique = false;
    }
  }

  // verifica clique simples
  if (aguardandoSegundoClique && millis() - tempoClique > 400) {
    registrarEntrada(2);
    aguardandoSegundoClique = false;
  }

  ultimoB1 = b1;
  ultimoB2 = b2;
}

// ================= REGISTRAR =================
void registrarEntrada(int valor) {
  acenderLed(valor);
  delay(200); // aqui pode usar (feedback visual curto)
  apagarLeds();

  entradaUsuario[indiceEntrada] = valor;
  indiceEntrada++;

  if (indiceEntrada == 3) {
    verificar();
  }
}

// ================= VERIFICAR =================
void verificar() {
  bool correto = true;

  for (int i = 0; i < 3; i++) {
    if (entradaUsuario[i] != sequencia[i]) {
      correto = false;
      break;
    }
  }

  if (correto) {
    sucesso();
  } else {
    erro();
  }

  // reset
  indiceEntrada = 0;
  jogando = false;
}

// ================= FEEDBACK =================
void sucesso() {
  for (int i = 0; i < 3; i++) {
    todosHIGH();
    delay(300);
    apagarLeds();
    delay(300);
  }
}

void erro() {
  for (int i = 0; i < 5; i++) {
    todosHIGH();
    delay(100);
    apagarLeds();
    delay(100);
  }
}

// ================= FUNÇÕES AUX =================
void acenderLed(int n) {
  if (n == 1) digitalWrite(led1, HIGH);
  if (n == 2) digitalWrite(led2, HIGH);
  if (n == 3) digitalWrite(led3, HIGH);
}

void apagarLeds() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void todosHIGH() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}