const int sensor[4] = {A0, A1, A2, A3};

void setup() {
  for(int i = 0; i < 4; i++){
    pinMode(sensor[i], INPUT);
  }
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i < 4; i++){
    int valor = analogRead(sensor[i]);

    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(valor);
  }

  delay(1000);
}