bool button;
bool button_flag;
bool light_flag;
unsigned long last_pressed;
void setup() {
pinMode(8, INPUT_PULLUP);
pinMode(13, OUTPUT);
}

void loop() {
button = !digitalRead(8);
if (button == true && button_flag == false && millis() - last_pressed > 50){
  light_flag = !light_flag;
  digitalWrite(13, light_flag);
  button_flag = !button_flag;
  last_pressed = millis();
}
if (button == false && button_flag == true){
  button_flag = !button_flag;
}
}
