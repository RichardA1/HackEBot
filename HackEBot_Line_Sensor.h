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
    HackEBot_Line_Sensor(int P, int T);
    boolean ReadLine(); //-- to take a reading from the sensor, T = the number that starts to define The Line and returns TRUE.
  private:
   int SensorPin;
   int Threshold;
   int LineSensorValue;
};
