#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int ledPin=12;
int buzzerPin=11;

void setup() {
 pinMode(ledPin,OUTPUT);
 pinMode(buzzerPin,OUTPUT);
 dht.begin();
 Serial.begin(9600);
}

void loop() {
float temp=dht.readTemperature();
Serial.print("temperature:");
Serial.println(temp);
if (temp>30){
digitalWrite(ledPin,HIGH);
digitalWrite(buzzerPin,HIGH);
}
else {
  digitalWrite(ledPin,LOW);
  digitalWrite(buzzerPin,LOW);
}
delay(2000);
}

