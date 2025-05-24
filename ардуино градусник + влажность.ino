#include <iarduino_DHT.h> 
iarduino_DHT sensor(4);   

void setup(){
  Serial.begin(9600);     
  delay(1000);            
}
void loop(){        
sensor.read();         
Serial.println(sensor.hum,'%');
Serial.println(sensor.tem);
delay(8000);
}
