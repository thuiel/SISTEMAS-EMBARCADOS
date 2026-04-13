const int ledPin = 9;  // LED connected to digital pin 9
const int potenciometro = 14;     //Define o pino 14(A0) como "sensor"
int valor = 0;
int valor_led = 0;

void setup() {
  digitalWrite(potenciometro, INPUT);
  Serial.begin(115200);
}

void loop() {
  valor = analogRead(potenciometro);
  valor_led = valor/4;
  analogWrite(ledPin, valor_led);
  Serial.println(valor);
  Serial.println(valor_led);
}
