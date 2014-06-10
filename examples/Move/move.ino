#include <HackEBot.h>

// Set-up the movement controls using;
// 		L = Left Servo Pin
// 		R = Right Servo Pin
// 		C = Right Servo offset
// 		W = Left Servo offset
// Servo offsets should be 0 unless the robot dose not drive strait.
// HackEBot robot(L, R, C, W);
   HackEBot robot(0, 2, 0, 0);

void setup()
{
}

void loop()
{
  robot.MoveF(30);
  robot.TurnR(16);
  robot.MoveF(30);
  robot.TurnR(16);
  robot.MoveF(30);
  robot.TurnR(16);
  robot.MoveF(30);
  robot.TurnR(16);
  robot.MoveF(30);
  robot.TurnL(16);
  robot.MoveF(30);
  robot.TurnL(16);
  robot.MoveF(30);
  robot.TurnL(16);
  robot.MoveF(30);
  robot.TurnL(16);
  delay(600);
}
