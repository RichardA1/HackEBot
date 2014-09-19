// This will allow the easy control of the two servos for the Hack-E-Bot.
// 
// Written by Richard Albritton for Hack-E-Bot Robotics, BSD license

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class HackEBot_Move {
  public:
    HackEBot_Move(int L, int R);
    long ServoSetup(int D, int F, int G, int H, int J, int K); //-- used to manually set the servo limits
    void Calibrate(); //-- to Calibrate the servos
    void MoveF(int S, int Z); //-- to drive forward, S = repeat number, Z = Speed.
    void MoveB(int S, int Z); //-- to drive backward, S = repeat number, Z = Speed.
    void TurnR(int S, int Z); //-- to turn right, S = repeat number, Z = Speed.
    void TurnL(int S, int Z); //-- to turn left, S = repeat number, Z = Speed.

  private:
   int servoL;
   int servoR;
   int steps;
   int speed;
   int UpperL;
   int CenterL;
   int LowerL;
   int UpperR;
   int CenterR;
   int LowerR;
   int LShift;
   int RShift;
};
