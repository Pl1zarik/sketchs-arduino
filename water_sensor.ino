void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2) == true ){
    Serial.println(11);
  } else {
    Serial.println(12);
  }
}
