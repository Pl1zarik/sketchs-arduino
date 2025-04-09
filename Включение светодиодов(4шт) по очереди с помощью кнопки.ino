bool button;
bool button_flag;
bool light_flag = true;
byte light = 9;
unsigned long last_pressed;
void setup() {
pinMode(8, INPUT_PULLUP);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
Serial.begin(9600);
}

void loop() {
button = !digitalRead(8);
if (button == true && button_flag == false && millis() - last_pressed > 100){
  // light_flag = !light_flag;
  digitalWrite(light, light_flag);
  light++;
  button_flag = !button_flag;
  last_pressed = millis();
  Serial.println(light);
  Serial.println(light_flag);

}
if (button == false && button_flag == true){
  button_flag = !button_flag;
} if (light > 13){
  light_flag = !light_flag ;
  light = 9;
}
}
