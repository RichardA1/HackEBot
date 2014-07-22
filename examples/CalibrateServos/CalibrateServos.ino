#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// 		LeftStop = Right Servo Center
// 		RightStop = Left Servo Center
// Each servo has a number that defines its centerpoint. 
//when the correct number is used, the wheels should not move when Calibrate(); is called
// HackEBot_Move robot(LeftPin, RightPin, LeftStop, RightStop);
   HackEBot_Move robot(13, 12, 1383, 1268);

void setup()
{
}

void loop()
{
  robot.Calibrate();
}
