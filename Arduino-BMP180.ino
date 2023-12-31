//import all required libraries
#include <SFE_BMP180.h>
#include <Wire.h>

// You will need to create an SFE_BMP180 object, here called "pressure":

SFE_BMP180 pressure;

#define ALTITUDE 1655.0 // Altitude of SparkFun's HQ in Boulder, CO. in meters

void setup()
{
  Serial.begin(9600);
  Serial.println("MICRODIGISOFT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (pressure.begin())
    Serial.println("BMP180 Sensor");
  else
  {
    

    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
}

void loop()
{
  char status;
  double T,P,p0,a;
  
  Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.println(" meters, ");
  Serial.print("                : ");
  Serial.print(ALTITUDE*3.28084,0);
  Serial.println(" feet");
  


  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);

  
    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // Print out the measurement:
      Serial.print("temperature: ");
      Serial.print(T,2);
      Serial.println(" deg C, ");
      Serial.print("                : ");
      Serial.print((9.0/5.0)*T+32.0,2);
      Serial.println(" deg F");
      
    

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          // Print out the measurement:
          Serial.print("absolute pressure: ");
          Serial.print(P,2);
          Serial.println(" mb, ");
          Serial.print("                : ");
          Serial.print(P*0.0295333727,2);
          Serial.println(" inHg");

          

          p0 = pressure.sealevel(P,ALTITUDE); // we're at 1655 meters (Boulder, CO)
          Serial.print("relative (sea-level) pressure: ");
          Serial.print(p0,2);
          Serial.println(" mb, ");
          Serial.print("                : ");
          Serial.print(p0*0.0295333727,2);
          Serial.println(" inHg");

         a = pressure.altitude(P,p0);
          Serial.print("computed altitude: ");
          Serial.print(a,0);
          Serial.println(" meters, ");
          Serial.print("                : ");
          Serial.print(a*3.28084,0);
          Serial.println(" feet");
        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");

  delay(1000);  // Pause for 1 seconds.
}
