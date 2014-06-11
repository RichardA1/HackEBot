// This will allow the easy control of the two servos for the Hack-E-Bot.
// 
// Written by Richard Albritton for Hack-E-Bot Robotics, BSD license

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Sonar {
  public:
    Sonar(int T, int E);
	void Ping(int D=8);
	long duration;
	long inches;
	long cm;
	boolean wall = false;
  private:
   int sonarTrig;
   int sonarEcho;
   int obstacle; // Number in cm when the rover will reverse and try to navigate around.
   int randNumber = 0;
};
