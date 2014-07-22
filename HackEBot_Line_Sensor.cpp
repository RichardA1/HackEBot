/*
  Sonar.cpp - Library for moving the Hack-E-Bot.
  Created by Richard Albritton, June 9, 2014.
  Released into the public domain.
*/

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "HackEBot_Line_Sensor.h"

HackEBot_Line_Sensor::HackEBot_Line_Sensor(int P, int T)
{
  SensorPin = P; //      The Pin that the sensor is connected to (Purple Wire)
  Threshold = T; //      The point were White becomes Black.
}

boolean HackEBot_Line_Sensor::ReadLine(){
  LineSensorValue = analogRead(SensorPin);
  if (LineSensorValue > Threshold){ 
    Return true; // is on the Line
    } else {
    return false; // is not on the Line
    }
}
