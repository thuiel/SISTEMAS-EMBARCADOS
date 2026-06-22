// motor esquerdo  
const int ma1 = 2, ma2 = 3, pwm1 = 9;
// motor direito
const int mb1 = 4, mb2 = 5, pwm2 = 10;
// sensores
const int s1 = A0, s2 = A1, s3 = A2, s4 = A3, s5 = A4;

int limiar = 960; // valor que o sensor detecta a linha 

// velocidades
const int velBase = 255; // velocidade maxima
const int velMin = 40; // velocidade mínima
const int velPivo = 150; //  velocidade quando busca a linha

bool ultimaEsquerda = false; // variavel que guarda qual foi o ultimo lado que virou

void setup() {
  pinMode(ma1, OUTPUT); pinMode(ma2, OUTPUT); pinMode(pwm1, OUTPUT);
  pinMode(mb1, OUTPUT); pinMode(mb2, OUTPUT); pinMode(pwm2, OUTPUT);
}

void loop() {
  // confirma se o sensor esta vendo a linha 
  bool S1 = analogRead(s1) > limiar;
  bool S2 = analogRead(s2) > limiar;
  bool S3 = analogRead(s3) > limiar;
  bool S4 = analogRead(s4) > limiar;
  bool S5 = analogRead(s5) > limiar;


  // peso dos sensores
  // S1 = -2
  // S2 = -1
  // S3 = 0
  // S4 = 1
  // S5 = 2
  //
  // o erro do carrinho é a soma dos pesos divido pelos sensores ativos

  int pesoEsq1 = S1 * -2;
  int pesoEsq2 = S2 * -1;
  int pesoCentro = S3 * 0;
  int pesoDir1 = S4 * 1;
  int pesoDir2 = S5 * 2; 

  int somaPesos = pesoEsq1 + pesoEsq2 + pesoCentro + pesoDir1 + pesoDir2;
  int sensoresAtivos = S1 + S2 + S3 + S4 + S5;

  // se nenhum sensor estiver ativo ele perdeu a linha 
  if (sensoresAtivos == 0) {
    // gira o carrinho para onde ele fez a ultima curva
    if (ultimaEsquerda) girarEsquerda(velPivo);
    else girarDireita(velPivo);
    return;
  }
  // calcula o erro do carrinho
  float erro = (float)somaPesos / sensoresAtivos;

  // guarda o lado da ultima curva 
  if (erro < -0.1) {
    ultimaEsquerda = true;
  }
  else if (erro > 0.1) {
    ultimaEsquerda = false;
  }

  // define a velocidade das duas rodas
  int velEsq = calcularVelocidadeInterna(erro, true);
  int velDir = calcularVelocidadeInterna(erro, false);
  // usa a velocidade nas rodas na funçao que fazer ele andar pra frente
  andarFrente(velEsq, velDir);
}

//   ladoEsquerdo = true   calcula a velocidade da roda esquerda
//   ladoEsquerdo = false  calcula a velocidade da roda direita
//   cria uma funçao que recebe o valor de erro e o lado do motor
int calcularVelocidadeInterna(float erro, bool ladoEsquerdo) {   

  bool curvaParaEsteLado = ladoEsquerdo ? (erro < 0) : (erro > 0);
  // se for ladoEsquerdo e o erro negativo a curva é para este lado 
  // se não for ladoEsquerdo e o erro positivo a curva é para este lado 

  if (!curvaParaEsteLado) {
    return velBase; // se não for a roda de dentro da curva a velocidade é maxima 
  }

  float desvio = abs(erro) * 100;        // abs remove o sinal da varialvel erro e dps multiplica por 100 
  desvio = constrain(desvio, 0, 200);        // garante que o desvio tenho o minimo de 0 e maximo de 200 
  return map(desvio, 0, 200, velBase, velMin); // faz uma regra de 3 onde quanto menor o desvio maior a velocidade 
}

// faz com que os dois motores girem para a frente e apenas precisa colocar a velocidade deles 
void andarFrente(int velEsq, int velDir) {
  digitalWrite(ma1, HIGH); digitalWrite(ma2, LOW); analogWrite(pwm1, velEsq);
  digitalWrite(mb1, HIGH); digitalWrite(mb2, LOW); analogWrite(pwm2, velDir);
}
// procura a linha para a esquerda 
void girarEsquerda(int vel) {
  digitalWrite(ma1, LOW);  digitalWrite(ma2, HIGH); analogWrite(pwm1, vel);
  digitalWrite(mb1, HIGH); digitalWrite(mb2, LOW);  analogWrite(pwm2, vel);
}
// procura a linha para a direita 
void girarDireita(int vel) {
  digitalWrite(ma1, HIGH); digitalWrite(ma2, LOW); analogWrite(pwm1, vel);
  digitalWrite(mb1, LOW);  digitalWrite(mb2, HIGH); analogWrite(pwm2, vel);
}
