#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// Adjust each servo pot until the servo stops spinning. 

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
}

void loop()
{
  robot.Calibrate();
}
