#include <HackEBot_Move.h>
#include <HackEBot_Sonar.h>
#include <HackEBot_Line_Sensor.h>

int LeftServoPin = 12;
int RightServoPin = 7;

// HackEBot_Move robot(LeftPin, RightPin, Speed, LeftStop, RightStop);
   HackEBot_Move robot(LeftServoPin, RightServoPin, 1385, 1269);
   
int SonarTrigPin = 4; // 	(Green wire)
int SonarEchoPin = 2; // 	(Blue wire)

// HackEBot_Sonar Obstacle(sonarTrigPin, sonarEchoPin);
   HackEBot_Sonar Obstacle(SonarTrigPin, SonarEchoPin);

// HackEBot_Line_Sensor Line(T); -- T = The point were White becomes Black.
   HackEBot_Line_Sensor Line(300);
   
int MoveSpeed = 50;
int TurnSpeed = 50;
int ObjDistance = 8;
int CenterLinePin = A1;
int LeftLinePin = A3;
int LineMove;

void setup()
{
  Serial.begin(9600);
}

int randNumber = 0;  // Used to choose a direction to turn

void loop()
{
  if (!Obstacle.Ping(ObjDistance)) {
    LineMove = Line.Read2Sensors(CenterLinePin, LeftLinePin);
    switch (LineMove) {
      case 'F':
        robot.MoveF(5, MoveSpeed);
        delay(10);
        break;
      case 'L':
        robot.TurnL(1, TurnSpeed);
        delay(10);
        break;
      case 'R':
        robot.TurnR(1, TurnSpeed);
        delay(10);
        break;
    }
  }
  delay(10);
}

