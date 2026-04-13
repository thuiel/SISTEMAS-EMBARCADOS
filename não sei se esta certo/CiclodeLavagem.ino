const int botao = 2;
const int leds[] = {5,6,7,8};

int etapa = 0;
unsigned long tempo = 0;

void setup(){
  for(int i=0;i<4;i++) pinMode(leds[i], OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(botao)==LOW && etapa==0){
    etapa=1;
    tempo=millis();
  }

  if(etapa==1){
    digitalWrite(leds[0],HIGH);
    if(millis()-tempo>=4000){
      digitalWrite(leds[0],LOW);
      etapa=2;
      tempo=millis();
    }
  }

  else if(etapa==2){
    if(millis()%500<250){
      digitalWrite(leds[1],HIGH);
      digitalWrite(leds[2],LOW);
    } else {
      digitalWrite(leds[1],LOW);
      digitalWrite(leds[2],HIGH);
    }

    if(millis()-tempo>=8000){
      digitalWrite(leds[1],LOW);
      digitalWrite(leds[2],LOW);
      etapa=3;
      tempo=millis();
    }
  }

  else if(etapa==3){
    digitalWrite(leds[3],HIGH);
    if(millis()-tempo>=4000){
      digitalWrite(leds[3],LOW);
      etapa=0;
    }
  }
}