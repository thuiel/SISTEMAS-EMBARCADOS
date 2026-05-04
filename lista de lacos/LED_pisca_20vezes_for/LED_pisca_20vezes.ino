int led1 = 2;
void setup() {
  pinMode(led1, OUTPUT);
  Serial.begin(115200);
  for(int i=0; i<20; i++){
    Serial.println(i+1);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
  }

}

void loop() {
}
