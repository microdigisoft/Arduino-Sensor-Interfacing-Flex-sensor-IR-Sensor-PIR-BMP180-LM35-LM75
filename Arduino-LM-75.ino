
//Import required libraries
#include <inttypes.h> 
#include <Wire.h>
#include <lm75.h>
//Initilize LM75 sensor
TempI2C_LM75 Temperature = TempI2C_LM75(0x48,TempI2C_LM75::nine_bits);
 
void setup()
{
Serial.begin(9600);  // Start Serial monitor
Serial.println("Start");
Serial.print("Actual temp ");
Serial.print(Temperature.getTemp()); // get LM75 Sensor Reading
Serial.println(" oC");
delay(2000);
}
 
void loop()
{
Serial.print(Temperature.getTemp());//Print LM75 Sensor Reading
Serial.println(" oC");
delay(2000);
}
