const int pot = A0;
const int ntc = A1;
const int botao = 2;

const int valvula = 5;
const int aquecedor = 6;
const int alarme = 7;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(valvula, OUTPUT);
  pinMode(aquecedor, OUTPUT);
  pinMode(alarme, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == HIGH) return;

  int nivel = analogRead(pot);
  int temp = analogRead(ntc);

  // Nível
  if (nivel < 300) digitalWrite(valvula, HIGH);
  else digitalWrite(valvula, LOW);

  // Temperatura
  if (temp < 400) {
    analogWrite(aquecedor, 255);
    digitalWrite(alarme, LOW);
  } 
  else if (temp > 700) {
    analogWrite(aquecedor, 0);
    digitalWrite(alarme, HIGH);
  }
}