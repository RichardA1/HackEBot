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
    HackEBot(uint8_t servoR, uint8_t servoL);
    void moveF(); //-- to drive forward
    void moveB(); //-- to drive backward
    void TurnR(); //-- to turn right
    void TurnL(); //-- to turn left
  private:
   uint8_t servoR;
   uint8_t servoL;
};
