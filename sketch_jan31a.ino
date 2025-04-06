byte button = 8;
byte light = 13;
bool button_sist;
bool flag;
bool light_flag = 0;
void setup() {
pinMode(button, INPUT_PULLUP);
pinMode(light, OUTPUT);
Serial.begin(9600);
}

void loop() {
button_sist = !digitalRead(button);

if (button_sist == true and flag == false){
  flag = true;
  light_flag = !light_flag;
  digitalWrite(light, light_flag);
delay(20);
}
if (button_sist == false and flag == true){
  flag = false;
}
}
