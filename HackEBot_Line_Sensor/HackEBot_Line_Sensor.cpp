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

HackEBot_Line_Sensor::HackEBot_Line_Sensor(int T)
{
  Threshold = T; //      The point were White becomes Black.
}

boolean HackEBot_Line_Sensor::ReadLine(int P){
  SensorPin = P; //      The Pin that the sensor is connected to (Purple Wire)
  delay(10);
  LineSensorValue = analogRead(SensorPin);
  if (LineSensorValue > Threshold){ 
    return true; // is on the Line
  } else {
    return false; // is not on the Line
  }
}

char HackEBot_Line_Sensor::Read2Sensors(int C, int L){
  CenterSensorPin = C;
  LeftSensorPin = L;
  CenterSensorValue = analogRead(CenterSensorPin);
  LeftSensorValue = analogRead(LeftSensorPin);
  delay(10);
  
  if (CenterSensorValue > Threshold){ // Line
    if (LeftSensorValue < Threshold){ // Paper
      return 'F';
    }else{ // Line - LeftSensor
      return 'L';
    }
  }else{ // Paper - CenterSensor
    if (LeftSensorValue < Threshold){ // Paper
      return 'R';
    }else{  // Line - LeftSensor
      return 'L';
    }
  }
}
