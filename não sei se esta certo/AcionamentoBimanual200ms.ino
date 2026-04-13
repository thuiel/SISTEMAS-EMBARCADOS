const int botaoA = 2;
const int botaoB = 3;
const int maquina = 5;

unsigned long tA = 0;
unsigned long tB = 0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(maquina, OUTPUT);
}

void loop() {
  if (digitalRead(botaoA) == LOW) tA = millis();
  if (digitalRead(botaoB) == LOW) tB = millis();

  if (abs((long)(tA - tB)) <= 200) {
    digitalWrite(maquina, HIGH);
  } else {
    digitalWrite(maquina, LOW);
  }
}
