const int led1 = 8;
bool estado = 0;
unsigned long tempo = 0;


void setup() {
   pinMode(led1, OUTPUT);
   Serial.begin(115200);

}

void loop() {
  unsigned long tempoatual = millis();
  if(tempoatual - tempo >=500)
  {
    tempo = tempoatual;
    estado = !estado;
    digitalWrite (led1, estado);
    Serial.print(tempoatual/1000.0);
    Serial.println("s");
  }

}
