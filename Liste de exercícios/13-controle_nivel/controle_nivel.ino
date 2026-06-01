
const int sensor = A0;
const int led1 = 8;
const int led2 = 9;
unsigned long timer = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  timer = millis();
}

void loop() {
  int leitura = analogRead(sensor);
  float porcentagem = (leitura/1023.0)*100;
  if(porcentagem >= 95){
    digitalWrite(led1, 0);
    if((millis() - timer) >= 200){
      digitalWrite(led2, 1);
      timer = millis();
   }
   else if((millis() - timer) >= 100){
      digitalWrite(led2, 0);
   }
  }
  else{
    digitalWrite(led2, 0);
  }
  if(porcentagem <= 30){
    digitalWrite(led1, 1);
  }
}
