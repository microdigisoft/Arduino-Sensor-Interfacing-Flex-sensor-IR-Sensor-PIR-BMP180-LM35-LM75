const int flexPin = A0; //Analog input to read flex sensor data
const int ledPin = 13; //Digital Out to connect LED

void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop() 
{ 
  int flexValue;
  flexValue = analogRead(flexPin);
  Serial.print("Flex Sensor Bend Value: ");
  Serial.println(flexValue);
  
  if(flexValue>300)
     digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
  
  delay(20);
} 
