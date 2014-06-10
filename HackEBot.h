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
    HackEBot(int L, int R);
    void MoveF(); //-- to drive forward
    void MoveB(); //-- to drive backward
    void TurnR(); //-- to turn right
    void TurnL(); //-- to turn left
  private:
   int servoL;
   int servoR;
};
