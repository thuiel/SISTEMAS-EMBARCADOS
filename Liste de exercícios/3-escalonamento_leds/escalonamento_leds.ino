
const int sensor = A0;
const int led1 = 8;
const int led2 = 9;
const int led3= 10;
const int led4 = 11;
unsigned int valorsensor = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  valorsensor = analogRead(sensor);

  if(valorsensor >= 921){ 
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }
  else if(valorsensor >= 768){ 
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  else if(valorsensor >= 512){ 
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  else if(valorsensor >= 256){ 
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
}
