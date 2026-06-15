// =====================
// DEFINIÇÃO DOS PINOS
// =====================
const int modo = 2;          // Botão para selecionar modo (Manual / Automático)
const int liga = 3;          // Botão LIGA (modo manual)
const int desliga = 4;       // Botão DESLIGA (modo manual)
const int nivel_baixo = 5;   // Sensor de nível baixo
const int nivel_alto = 6;    // Sensor de nível alto

const int bomba = 7;         // Saída da bomba (LED)

// =====================
// VARIÁVEIS DE CONTROLE
// =====================
unsigned int estado = 0;     // Variável que guarda o estado atual da máquina
unsigned long timer = 0;     // Variável para controle de tempo (millis)

// =====================
// CONFIGURAÇÃO INICIAL
// =====================
void setup()
{
  // Entradas com pull-up interno
  pinMode(modo, INPUT_PULLUP);
  pinMode(liga, INPUT_PULLUP);
  pinMode(desliga, INPUT_PULLUP);
  pinMode(nivel_baixo, INPUT_PULLUP);
  pinMode(nivel_alto, INPUT_PULLUP);

  // Saída
  pinMode(bomba, OUTPUT);
}

// =====================
// LOOP PRINCIPAL
// =====================
void loop()
{
  // Leitura dos botões e sensores
  // (!digitalRead) porque INPUT_PULLUP inverte lógica:
  // pressionado = LOW → vira TRUE com !
  bool MODO = !digitalRead(modo);
  bool LIGA = !digitalRead(liga);
  bool DESL = !digitalRead(desliga);
  bool NB = !digitalRead(nivel_baixo);
  bool NA = !digitalRead(nivel_alto);

  // =====================
  // MÁQUINA DE ESTADOS
  // =====================
  switch(estado)
  {
    // =====================
    // ESTADO 0 → DESLIGADO / ESPERA
    // =====================
    case 0:
      digitalWrite(bomba, LOW); // bomba desligada

      // Se estiver em modo MANUAL (MODO = 0) e pressionar LIGA
      if(MODO == 0 && LIGA) 
        estado = 1;

      // Se estiver em modo AUTOMÁTICO (MODO = 1) e detectar nível baixo
      if(MODO == 1 && NB) {
        estado = 2;
        timer = millis(); // inicia contagem de tempo
      }
    break;

    // =====================
    // ESTADO 1 → MANUAL LIGADO
    // =====================
    case 1:
      digitalWrite(bomba, HIGH); // liga bomba

      // Se pressionar DESLIGA no modo manual
      if(MODO == 0 && DESL) 
        estado = 0;

      // Se mudar para modo automático, volta para estado inicial
      if(MODO == 1) 
        estado = 0;
    break;

    // =====================
    // ESTADO 2 → AUTOMÁTICO (LIGOU COM NÍVEL BAIXO)
    // =====================
    case 2:
      digitalWrite(bomba, HIGH); // bomba ligada

      // Após 10 segundos
      if(millis() - timer >= 10000) 
        estado = 3;
    break;

    // =====================
    // ESTADO 3 → ESPERANDO NÍVEL ALTO
    // =====================
    case 3:
      digitalWrite(bomba, HIGH); // mantém ligada

      // Quando detectar nível alto
      if(NA) {
        estado = 4;
        timer = millis(); // inicia tempo para desligar
      }
    break;

    // =====================
    // ESTADO 4 → DESLIGANDO APÓS NÍVEL ALTO
    // =====================
    case 4:
      digitalWrite(bomba, LOW); // desliga bomba

      // Após 10 segundos, volta ao início
      if(millis() - timer >= 10000) 
        estado = 0;
    break;
  }
}
