const int ntc = A0;
const int leds[] = {5,6,7,8};

void setup() {
  for(int i=0;i<4;i++) pinMode(leds[i], OUTPUT);
}

void loop() {
  int temp = analogRead(ntc);

  int nivel = map(temp, 0, 1023, 0, 4);

  for(int i=0;i<4;i++){
    if(i < nivel) digitalWrite(leds[i], HIGH);
    else digitalWrite(leds[i], LOW);
  }
}