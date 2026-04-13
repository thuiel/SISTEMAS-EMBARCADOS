const int botaoA = 2;
const int botaoB = 3;
const int led1 = 13;

void setup() {
  pinMode(botaoA, INPUT);
  pinMode(botaoB, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  int estadoA = digitalRead(botaoA);
  int estadoB = digitalRead(botaoB);

  // Intertravamento de segurança
  if (estadoA == HIGH && estadoB == HIGH) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}