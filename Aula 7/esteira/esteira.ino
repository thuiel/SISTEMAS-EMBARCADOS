int esteira = 2;   // LED que representa a esteira
int botaoA = 3;    // Botão A → iniciar/resetar sistema
int botaoB = 4;    // Botão B → sensor de caixas

int contagemLote = 0; // conta caixas dentro de um lote (até 5)
int total = 0;        // conta total de caixas (até 20)

bool ligada = false;  // indica se a esteira está funcionando
bool pausada = false; // indica se está na pausa de 3 segundos

unsigned long tempoParada = 0; // guarda o momento em que a pausa começou

void setup() {
  pinMode(esteira, OUTPUT); // define LED como saída
  pinMode(botaoA, INPUT);   // botão A como entrada
  pinMode(botaoB, INPUT);   // botão B como entrada
}

void loop() {

  // ===============================
  // BOTÃO A → INICIAR OU RESETAR
  // ===============================
  if (digitalRead(botaoA) == HIGH) {
    ligada = true;        // liga a esteira
    total = 0;            // zera total de caixas
    contagemLote = 0;     // zera contagem do lote
    pausada = false;      // garante que não está pausada
  }

  // =========================================
  // SE ATINGIR 20 CAIXAS → PARA COMPLETAMENTE
  // =========================================
  if (total >= 20) {
    ligada = false;               // desliga sistema
    digitalWrite(esteira, LOW);   // apaga LED (esteira parada)
    return; // sai do loop (fica travado até apertar botão A)
  }

  // =========================================
  // SE A ESTEIRA ESTIVER LIGADA
  // =========================================
  if (ligada) {

    // -----------------------------------------
    // VERIFICA SE ESTÁ EM PAUSA (3 SEGUNDOS)
    // -----------------------------------------
    if (pausada) {

      // verifica se já passaram 3 segundos
      if (millis() - tempoParada >= 3000) {
        pausada = false; // fim da pausa → volta a funcionar
      } else {
        digitalWrite(esteira, LOW); // mantém esteira parada
        return; // não executa o resto do código
      }
    }

    // -----------------------------------------
    // ESTEIRA FUNCIONANDO NORMALMENTE
    // -----------------------------------------
    digitalWrite(esteira, HIGH); // liga LED (esteira em movimento)

    // -----------------------------------------
    // DETECÇÃO DE CAIXAS (BOTÃO B)
    // -----------------------------------------
    if (digitalRead(botaoB) == HIGH) {

      contagemLote++; // soma 1 caixa no lote
      total++;        // soma 1 no total geral

      delay(200); // evita múltiplas leituras do botão (debounce simples)

      // -----------------------------------------
      // A CADA 5 CAIXAS → FAZ PAUSA
      // -----------------------------------------
      if (contagemLote == 5) {
        pausada = true;          // ativa modo pausa
        tempoParada = millis();  // registra início da pausa
        contagemLote = 0;        // reinicia contagem do lote
      }
    }
  }
}