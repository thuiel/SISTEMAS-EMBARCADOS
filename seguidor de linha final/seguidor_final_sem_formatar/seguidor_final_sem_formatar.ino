// =======================================================
//   SEGUIDOR DE LINHA - VERSÃO SIMPLIFICADA (pista em "0")
// =======================================================

// --- Motor Esquerdo (Canal A do L298N) ---
const int ma1 = 2, ma2 = 3, pwm1 = 9;
// --- Motor Direito (Canal B do L298N) ---
const int mb1 = 4, mb2 = 5, pwm2 = 10;
// --- Sensores (esquerda → direita) ---
const int s1 = A0, s2 = A1, s3 = A2, s4 = A3, s5 = A4;

int limiar = 960; // calibrar com Serial Monitor

// --- Velocidades ---
const int velBase = 255; // velocidade da roda externa / reto
const int velMin   = 40; // velocidade mínima da roda interna numa curva forte
const int velPivot = 150; // giro de busca

bool ultimaEsquerda = false; // memória da última curva, para busca

void setup() {
  pinMode(ma1, OUTPUT); pinMode(ma2, OUTPUT); pinMode(pwm1, OUTPUT);
  pinMode(mb1, OUTPUT); pinMode(mb2, OUTPUT); pinMode(pwm2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool S1 = analogRead(s1) > limiar;
  bool S2 = analogRead(s2) > limiar;
  bool S3 = analogRead(s3) > limiar;
  bool S4 = analogRead(s4) > limiar;
  bool S5 = analogRead(s5) > limiar;
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);


  // =======================================================
  //   POSIÇÃO DA LINHA
  // =======================================================
  // Cada sensor tem um peso de posição:
  //
  //     S1     S2     S3     S4     S5
  //    -2     -1      0     +1     +2
  //  (esq. máx)              (dir. máx)
  //
  // A posição final é a MÉDIA dos pesos dos sensores que
  // estão ativos (ou seja, que estão vendo a linha preta).
  // Resultado: -2 = linha bem à esquerda | 0 = centro | +2 = bem à direita

  int pesoEsq1 = S1 * -2; // peso do sensor extremo esquerdo
  int pesoEsq2 = S2 * -1; // peso do sensor interno esquerdo
  int pesoCentro = S3 * 0; // sensor central não desloca a posição
  int pesoDir1 = S4 * 1;  // peso do sensor interno direito
  int pesoDir2 = S5 * 2;  // peso do sensor extremo direito

  int somaPesos = pesoEsq1 + pesoEsq2 + pesoCentro + pesoDir1 + pesoDir2;
  int sensoresAtivos = S1 + S2 + S3 + S4 + S5;

  // Sem nenhum sensor ativo -> perdeu a linha, vai buscar
  if (sensoresAtivos == 0) {
    if (ultimaEsquerda) girarEsquerda(velPivot);
    else girarDireita(velPivot);
    return;
  }

  float posicao = (float)somaPesos / sensoresAtivos;

  // =======================================================
  //   MEMÓRIA DE DIREÇÃO (para a busca, se perder a linha)
  // =======================================================
  if (posicao < -0.1) {
    ultimaEsquerda = true;
  }
  else if (posicao > 0.1) {
    ultimaEsquerda = false;
  }

  // =======================================================
  //   VELOCIDADE DE CADA RODA
  // =======================================================
  int velEsq = calcularVelocidadeInterna(posicao, true);
  int velDir = calcularVelocidadeInterna(posicao, false);

  andarFrente(velEsq, velDir);
}

// Calcula a velocidade de uma roda com base na posição da linha.
// Se a roda for "interna" à curva, desacelera proporcionalmente
// ao desvio; se for "externa", mantém a velocidade base.
//
//   ladoEsquerdo = true  -> calcula a velocidade da roda ESQUERDA
//   ladoEsquerdo = false -> calcula a velocidade da roda DIREITA
int calcularVelocidadeInterna(float posicao, bool ladoEsquerdo) {
  bool curvaParaEsteLado = ladoEsquerdo ? (posicao < 0) : (posicao > 0);

  if (!curvaParaEsteLado) {
    return velBase; // esta roda é a externa: velocidade cheia
  }

  float desvio = abs(posicao) * 100;        // 0 a 200
  desvio = constrain(desvio, 0, 200);        // garante que fica na faixa
  return map(desvio, 0, 200, velBase, velMin); // quanto maior o desvio, mais lenta
}

void andarFrente(int velEsq, int velDir) {
  digitalWrite(ma1, HIGH); digitalWrite(ma2, LOW); analogWrite(pwm1, velEsq);
  digitalWrite(mb1, HIGH); digitalWrite(mb2, LOW); analogWrite(pwm2, velDir);
}

void girarEsquerda(int vel) {
  digitalWrite(ma1, LOW);  digitalWrite(ma2, HIGH); analogWrite(pwm1, vel);
  digitalWrite(mb1, HIGH); digitalWrite(mb2, LOW);  analogWrite(pwm2, vel);
}

void girarDireita(int vel) {
  digitalWrite(ma1, HIGH); digitalWrite(ma2, LOW); analogWrite(pwm1, vel);
  digitalWrite(mb1, LOW);  digitalWrite(mb2, HIGH); analogWrite(pwm2, vel);
}
