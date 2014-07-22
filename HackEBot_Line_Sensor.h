// This will allow the easy get feedback from the line trace sensors for the Hack-E-Bot.
// 
// Written by Richard Albritton for Hack-E-Bot Robotics, BSD license

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class HackEBot_Line_Sensor {
  public:
    HackEBot_Line_Sensor(int T);
    boolean ReadLine(int P); //-- to take a reading from the sensor, T = the number that starts to define The Line and returns TRUE.
    char Read2Sensors(int C, int L); //-- C=Center Sensor Pin, L=Left Sensor Pin. Will return F,R, or L based on readings of the line
  private:
   int Threshold;
   int SensorPin;
   int CenterSensorPin;
   int LeftSensorPin;
   int LineSensorValue;
   int CenterSensorValue;
   int LeftSensorValue;
};
