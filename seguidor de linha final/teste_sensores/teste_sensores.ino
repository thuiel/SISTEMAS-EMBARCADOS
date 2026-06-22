const int s1 = A0, s2 = A1, s3 = A2, s4 = A3, s5 = A4;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int S1 = analogRead(s1);
  int S2 = analogRead(s2);
  int S3 = analogRead(s3);
  int S4 = analogRead(s4);
  int S5 = analogRead(s5);
  
  Serial.println(S1);
  
  Serial.println(S2);

  Serial.println(S3);

  Serial.println(S4);

  Serial.println(S5);
  delay(2000);

}
