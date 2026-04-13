const int botaoPin = 3;
const int ledPin = 4;

int estadoBotao = LOW;
int ultimoEstadoBotao = LOW;

unsigned long ultimoTempoDebounce = 0;
unsigned long delayDebounce = 50; 

int estadoLed = LOW;

void setup() {
  pinMode(botaoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int leitura = digitalRead(botaoPin);

  if (leitura != ultimoEstadoBotao) {
    ultimoTempoDebounce = millis();
  }
  if ((millis() - ultimoTempoDebounce) > delayDebounce) {
    
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == HIGH) {
        estadoLed = !estadoLed; 
      }
    }
  }
  digitalWrite(ledPin, estadoLed);
  ultimoEstadoBotao = leitura;
}