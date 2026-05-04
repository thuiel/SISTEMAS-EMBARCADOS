const int led[3] = {2,3,4};

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 3; i++){
    digitalWrite(led[i], HIGH);
    delay(1000);
    digitalWrite(led[i], LOW);
  }
  }
