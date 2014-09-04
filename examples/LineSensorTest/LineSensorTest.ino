<<<<<<< HEAD
#include <HackEBot_Line_Sensor.h>

=======
#include <HackEBot_Move.h>
#include <HackEBot_Line_Sensor.h>

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

>>>>>>> 86dd206d720f6430031a4b8dcadedb81e1537a8b
// HackEBot_Line_Sensor Line(T); -- T = The point were White becomes Black.
   HackEBot_Line_Sensor Line(300);
   
int MoveSpeed = 50;
int TurnSpeed = 50;
int CenterLinePin = A1;
int LeftLinePin = A3;
int LineMove;

void setup()
{
}

int randNumber = 0;  // Used to choose a direction to turn

void loop()
{

  delay(10);
}
