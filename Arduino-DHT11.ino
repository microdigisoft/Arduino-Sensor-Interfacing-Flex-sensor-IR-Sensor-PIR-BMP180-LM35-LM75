#include <dht.h>// Import DHT11 sensor Library
#define dht_apin A0 // Initialize Analog pin Ao to read DHT11 data
dht DHT;// variable to handle to DHT data
void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Welcome to Microdigisoftn");
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensornn");
  delay(1000);//Wait before accessing Sensor
}
void loop() {
  DHT.read11(dht_apin);
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%  ");
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C  ");
  Serial.println("");
  delay(2000);
}
