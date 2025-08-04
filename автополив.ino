#define DRYSIL 700
#define DRYSIGH 300
#define Water 150
int val;
unsigned long now;
void setup() {
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);

}

void loop() {
if(analogRead(0) >= DRYSIL and analogRead(2) > Water){
  digitalWrite(3, HIGH); //светодиот и релеха
  digitalWrite(2, LOW);
}
if(analogRead(0) < DRYSIL){
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);

}
// Serial.println(analogRead(0));
delay(100);
val = analogRead(0);
Serial.println(analogRead(2));

}
