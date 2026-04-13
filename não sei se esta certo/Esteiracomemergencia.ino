const int pot = A0;
const int emergencia = 2;
const int motor = 5;
const int status = 6;

bool falha=false;
unsigned long tempo=0;
bool pisca=false;

void setup(){
  pinMode(emergencia, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  pinMode(status, OUTPUT);
}

void loop(){
  if(digitalRead(emergencia)==LOW){
    falha=true;
  }

  if(falha){
    analogWrite(motor,0);

    if(millis()-tempo>=300){
      tempo=millis();
      pisca=!pisca;
      digitalWrite(status,pisca);
    }
  } else {
    int val=analogRead(pot);
    analogWrite(motor,map(val,0,1023,0,255));
  }
}