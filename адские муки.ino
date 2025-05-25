#include <Wire.h> 
#include <iarduino_DHT.h>  
#include <LiquidCrystal_I2C.h>      

iarduino_DHT sensor(4);                          
LiquidCrystal_I2C lcd(0x27,16,2); 
int a = 0;
void setup() {
  Serial.begin(9600);  
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("hello");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  // menu();
  sensor.read();
  info();
}

void info() {
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(12,0);
  lcd.print(int(sensor.tem));
  lcd.print("C   ");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.setCursor(9,1);
  lcd.print(int(sensor.hum));
  lcd.print("%   ");
}

void menu() {
  lcd.setCursor(0,0);
  lcd.print(" info");
  lcd.setCursor(0,1);
  lcd.print(" settings");
}
