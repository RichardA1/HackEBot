#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// 		LeftStop = Right Servo Center
// 		RightStop = Left Servo Center
// Each servo has a number that defines its centerpoint. 
//when the correct number is used, the wheels should not move when Calibrate(); is called
// HackEBot_Move robot(LeftPin, RightPin, Speed, LeftStop, RightStop);
   HackEBot_Move robot(13, 12, 1383, 1268);

void setup()
{
}

int MoveSpeed = 200;
int TurnSpeed = 150;

void loop()
{
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, MoveSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  delay(600);
}
