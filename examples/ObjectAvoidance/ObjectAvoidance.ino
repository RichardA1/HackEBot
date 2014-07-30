#include <HackEBot_Move.h>
#include <HackEBot_Sonar.h>

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);
   
int SonarTrigPin = 4; // 	(Green wire)
int SonarEchoPin = 2; // 	(Blue wire)

// Sonar Obstacle(sonarTrig, sonarEcho);
   HackEBot_Sonar Obstacle(SonarTrigPin, SonarEchoPin);
   
int MoveSpeed = 200;
int TurnSpeed = 150;
int ObjDistance = 8;

void setup()
{
}

int randNumber = 0;  // Used to choose a direction to turn

void loop()
{ 
  if (Obstacle.Ping(ObjDistance)){
   robot.MoveB(30, MoveSpeed);
   randNumber = random(200);
    if (randNumber < 99) {
      robot.TurnL(16, TurnSpeed);
    } else {
      robot.TurnR(16, TurnSpeed);
    }
 } else {
   robot.MoveF(1, MoveSpeed);
 }
}

