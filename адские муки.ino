#include <Wire.h> 
#include <iarduino_DHT.h>  
#include <LiquidCrystal_I2C.h>      
#include "GyverEncoder.h"
Encoder enc(10, 11, 12);
int value = 0;
iarduino_DHT sensor(4);                          
LiquidCrystal_I2C lcd(0x27,16,2); 
unsigned long  lastLCDUpdate = 0;
void setup() {
  Serial.begin(9600); 
  enc.setType(TYPE2); 
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("hello");
  delay(2000);
  lcd.clear();
}

void loop() {
  enc.tick();
  lcd.setCursor(0,0);
  sensor.read();
  encoder();
  if (millis() - lastLCDUpdate > 100) {  // Обновляем LCD раз в 100 мс
    // menu();
    lastLCDUpdate = millis();
  }

}

void menu() {
  lcd.setCursor(0,0);
  lcd.print(" info");
  lcd.setCursor(0,1);
  lcd.print(" settings");
  // if (value <= 1){
  //   lcd.setCursor(0,0);
  //   lcd.write(126);
  // }


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


int encoder(){
  enc.tick();
  if (enc.isRight()) value++;
  if (enc.isLeft()) value--;
  if (enc.isTurn()) {       
    Serial.println(value);  
  }  
}
