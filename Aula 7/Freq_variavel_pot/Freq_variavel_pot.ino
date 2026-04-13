int led = 3;
int pot = A0;

unsigned long tempo = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot); // lê o potenciômetro (0 a 1023)

  // Queremos transformar esse valor em um intervalo de tempo:
  // mínimo = 100 ms
  // máximo = 2000 ms
  //
  // Primeiro calculamos a diferença:
  // 2000 - 100 = 1900
  //
  // Depois aplicamos a regra:
  // intervalo = 100 + (valor * 1900 / 1023)
  //
  // Explicação:
  // - valor * 1900 → espalha o valor na faixa até 1900
  // - /1023 → ajusta para o máximo do potenciômetro
  // - +100 → garante que nunca seja menor que 100 ms

  int intervalo = 100 + (valor * 1900 / 1023);

  // verifica se já passou o tempo necessário
  if (millis() - tempo >= intervalo) {
    tempo = millis(); // atualiza o tempo

    // inverte o estado do LED (liga/desliga)
    digitalWrite(led, !digitalRead(led));
  }
}