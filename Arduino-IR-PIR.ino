#include <LiquidCrystal.h>// Import LCD library
//Initialize Arduino pin for LCD
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int IRSensor = 8; // connect ir sensor to arduino pin 2
int ledPin = 7; // choose the pin for the LED
int ledPin1 = 2;
int PIRSensor = 10;// choose the input pin (for PIR sensor)
int pirState = LOW;// we start, assuming no motion detected
int val = 0;// variable for reading the pin status
int val1 = 0;



void setup()
{
  Serial.begin(9600); //Start Arduino Serial monitor
  lcd.begin(16, 2); //Start LCD
  lcd.clear();
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(PIRSensor, INPUT);     // declare sensor as input
  lcd.setCursor(2, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("motion detector");
  delay(500);
  lcd.clear();
}

void loop()
{

  irSensor(); // Function to Read IR sensor Data
  delay(100);
  pirSensor();// Function to Read PIR sensor Data
  delay(100);

}
void pirSensor() {
  val = digitalRead(PIRSensor);// read input value

  if (val == HIGH ) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);
    delay(100);// turn LED ON
    if (pirState == LOW)
    {
      lcd.setCursor(1, 3);
      lcd.print("Motion detected!");
      delay(100);
      pirState = HIGH;

    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH)
      lcd.setCursor(1, 3);
    lcd.print("Motion ended!  ");
    delay(100);
    // We only want to print on the output change, not state
    pirState = LOW;
  }
}
}
void irSensor() {
  val1 = digitalRead (IRSensor);

  lcd.setCursor(2, 0);
  lcd.print("ir status= ");
  lcd.print(val1);
  delay(100);

  if (val1 == 1) {
    digitalWrite(ledPin1, HIGH);
  }
  else {
    digitalWrite(ledPin1, LOW);
  }
}
