#include <HackEBot.h>

// Set-up the movement controls using;
// HackEBot robot(Left Servo Pin, Right Servo Pin);
   HackEBot robot(2, 0);

void setup()
{
}

void loop()
{
  robot.MoveF();
  delay(30);
}
