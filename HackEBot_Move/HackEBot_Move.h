// This will allow the easy control of the two servos for the Hack-E-Bot.
// 
// Written by Richard Albritton for Hack-E-Bot Robotics, BSD license


class HackEBot_Move {
  public:
    HackEBot_Move(int R, int L);
    void Center(); //-- Dose servo.write(90) to test if the servo is centered.
    void MoveF(int S, int T); //-- to drive forward, S = driveSpeed, T = driveTime.
    void MoveB(int S, int T); //-- to drive backward, S = driveSpeed, T = driveTime.
    void TurnR(int S, int T); //-- to turn right, S = driveSpeed, T = driveTime.
    void TurnL(int S, int T); //-- to turn left, S = driveSpeed, T = driveTime.

  private:
   int servoR;
   int servoL;
   int driveSpeed;
   int driveTime;

};
