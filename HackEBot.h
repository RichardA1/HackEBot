// This will allow the easy control of the two servos for the Hack-E-Bot.
// 
// Written by Richard Albritton for Hack-E-Bot Robotics, BSD license

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class HackEBot {
  public:
    HackEBot(int L, int R, int C, int W);
    void MoveF(int S); //-- to drive forward
    void MoveB(int S); //-- to drive backward
    void TurnR(int S); //-- to turn right
    void TurnL(int S); //-- to turn left
  private:
   int servoL;
   int servoR;
   int steps;
   int offsetR;
   int offsetL;
   int turnCW;
   int turnCCW;
};
