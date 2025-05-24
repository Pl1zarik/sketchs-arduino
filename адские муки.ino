#include <Wire.h> 
#include <iarduino_DHT.h>  
#include <LiquidCrystal_I2C.h>  
iarduino_DHT sensor(4);                                  
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup(){
Serial.begin(9600);  
lcd.init();                       
lcd.backlight(); 
lcd.scrollDisplayRight();
lcd.setCursor(5,0);
lcd.print("hello");
delay(5000);
lcd.clear();
lcd.print("Temperature:");
lcd.setCursor(0,1);
lcd.print("Humidity:");
}
void loop(){
info();

}

void info(){
sensor.read();
lcd.setCursor(12,0);
lcd.print(int(sensor.tem));
lcd.setCursor(14,0);
lcd.print("C");
lcd.setCursor(9,1);
lcd.print(int(sensor.hum));
lcd.setCursor(11,1);
lcd.print("%");
}
