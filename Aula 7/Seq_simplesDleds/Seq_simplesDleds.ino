int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

int atual = 1;
unsigned long tempo = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  if (millis() - tempo >= 200) {
    tempo = millis();                 //isso é basicamento o delay

    // Desliga todos
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    // Liga um por vez
    if (atual == 1) digitalWrite(led1, HIGH);
    if (atual == 2) digitalWrite(led2, HIGH);
    if (atual == 3) digitalWrite(led3, HIGH);
    if (atual == 4) digitalWrite(led4, HIGH);

    atual++;

    if (atual > 4) atual = 1;
  }
}