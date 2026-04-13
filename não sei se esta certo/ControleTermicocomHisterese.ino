const int ntc = A0;
const int aquec = 5;

int limiteInferior = 400;
int limiteSuperior = 600;

bool ligado = false;

void setup() {
  pinMode(aquec, OUTPUT);
}

void loop() {
  int temp = analogRead(ntc);

  if (temp < limiteInferior) {
    ligado = true;
  }
  if (temp > limiteSuperior) {
    ligado = false;
  }

  digitalWrite(aquec, ligado);
}