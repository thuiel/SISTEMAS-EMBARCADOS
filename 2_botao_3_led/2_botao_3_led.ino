const int b1 = 3;
const int a2 = 2;
bool botaoa = false;
bool botaob = false;
const int led_vermelho = 5;			//
const int led_verde = 6;			//
const int led_amarelo = 7;
void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(a2, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop() {
  botaob = digitalRead(b1);
  botaoa = digitalRead(a2);
  if(botaob == 0 && botaoa == 0){
    digitalWrite(led_vermelho, 1);
  }else{
    digitalWrite(led_vermelho, 0);
    }
  if(botaob == 0 || botaoa == 0){
    digitalWrite(led_verde, 1);
  }else{
    digitalWrite(led_verde, 0);
    }
    if(botaoa ^ botaob){
    digitalWrite(led_amarelo, 1);
  }else{
    digitalWrite(led_amarelo, 0);
    }
  }

