
//Setup function initialize Serial monitor and Read the Analog Data
void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Welcome to Microdigisoft \n");
  pinMode(A0, INPUT);// Define pin A0 as a input
  Serial.begin(9600);
  pinMode(13, OUTPUT);// Define pin 13 as a output
}

void loop() {
  delay(500);
  Serial.println("");
  //Serial.println(digitalRead(A0));

  if (digitalRead(A0) == 0)
  {
    digitalWrite(13, HIGH);
    Serial.print("Object Found ");
  }
  else {
    digitalWrite(13, LOW);
    Serial.print("NO Object Found ");
  }

}
