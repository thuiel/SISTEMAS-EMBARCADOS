const int pot = A0;
const int leds[] = {5, 6, 7, 8};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int valor = analogRead(pot);

  // Apaga todos
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }

  if (valor > 256) digitalWrite(leds[0], HIGH);
  if (valor > 512) digitalWrite(leds[1], HIGH);
  if (valor > 768) digitalWrite(leds[2], HIGH);
  if (valor > 921) digitalWrite(leds[3], HIGH);
}