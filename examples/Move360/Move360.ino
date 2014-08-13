#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// Adjust each servo pot until the servo stops spinning. 

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
robot.ServoSetup(2100, 900, 900, 2100);
}

int MoveSpeed = 100;

void loop()
{
  robot.MoveF(30, MoveSpeed);
}
