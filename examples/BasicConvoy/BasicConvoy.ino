#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  #include <avr/power.h>
#endif
#include <HackEBot_Move.h>
#include <HackEBot_Sonar.h>
#include <HackEBot_Line_Sensor.h>

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);
   
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
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif
  // ...
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

