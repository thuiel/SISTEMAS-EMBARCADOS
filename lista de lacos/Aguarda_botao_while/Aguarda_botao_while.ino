int botao = 2;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(115200);

  while(digitalRead(botao) == HIGH){
    Serial.println("Aguardando botão...");
    delay(500);
  }

  Serial.println("Botão pressionado");
}

void loop() {}
