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
    HackEBot_Move(int L, int R, int C, int W);
    void MoveF(int S, int Z); //-- to drive forward, S = repeat number, Z = Speed.
    void MoveB(int S, int Z); //-- to drive backward, S = repeat number, Z = Speed.
    void TurnR(int S, int Z); //-- to turn right, S = repeat number, Z = Speed.
    void TurnL(int S, int Z); //-- to turn left, S = repeat number, Z = Speed.
	void Calibrate(); //-- to Calibrate the servos
  private:
   int servoL;
   int servoR;
   int steps;
   int speed;
   int turnCW;
   int turnCCW;
};
