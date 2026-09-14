// Environmental monitor: reads temperature via DHT11, displays it on an LCD,
// and triggers an LED and a pulsing buzzer alarm above a set threshold.

#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
// Pin assignments and sensor setup

int ledPin=5;
int buzzerPin=6;
float temp;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// Runs once: configure pins, start sensor, LCD, and Serial communication

void setup() {
 pinMode(ledPin,OUTPUT);
 pinMode(buzzerPin,OUTPUT);
 dht.begin();
 Serial.begin(9600);
 lcd.begin(16, 2);
}
// Runs repeatedly: read temperature, display it, and trigger alarm if too hot

void loop() {
temp=dht.readTemperature(); 
Serial.print("temperature:");
Serial.print(temp);
Serial.println("°C");
lcd.setCursor(0, 0);
lcd.print("Temp:");
lcd.print(temp);
lcd.write(223);
lcd.print("C");
// Alarm condition — pulses buzzer and lights LED while threshold is exceeded
if (temp>30){
digitalWrite(ledPin,HIGH);
digitalWrite(buzzerPin,HIGH);
delay(300);
digitalWrite(buzzerPin,LOW);
delay(300);
}
// Normal condition — alarm off
else {
  digitalWrite(ledPin,LOW);
  digitalWrite(buzzerPin,LOW);
}
delay(2000);
}

