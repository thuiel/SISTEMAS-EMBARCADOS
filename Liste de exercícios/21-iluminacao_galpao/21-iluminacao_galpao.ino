
const int sensor = A0;
const int botao = 2;
const int led = 9;
bool action = 1;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  bool estado = digitalRead(botao);
  if(!estado){
    action = 1;
  }
  else{
    action = 0;
  }

  if(action){
    unsigned int leitura = analogRead(sensor);
    float valor = leitura/4;
    float brilho = abs(valor - 255);
    analogWrite(led, brilho);
    Serial.println(valor + brilho);
  }
  else{
    analogWrite(led, 26);
  }
}
