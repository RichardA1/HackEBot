#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  #include <avr/power.h>
#endif
#include <HackEBot_Move.h>
#include <HackEBot_Sonar.h>

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(1, 0);
   
int SonarTrigPin = 2; // 	(Blue wire)
int SonarEchoPin = 3; // 	(Green wire)

// Sonar Obstacle(sonarTrig, sonarEcho);
   HackEBot_Sonar Obstacle(SonarTrigPin, SonarEchoPin);
   
int MoveSpeed = 100;
int TurnSpeed = 50;
int ObjDistance = 10;

void setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif
  // ...
  robot.ServoSetup(900, 1500, 2100, 900, 1500, 2100);
}

int randNumber = 0;  // Used to choose a direction to turn

void loop()
{ 
  if (Obstacle.Ping(ObjDistance)){
   robot.MoveB(150, MoveSpeed);
   randNumber = random(200);
    if (randNumber < 99) {
      robot.TurnL(100, TurnSpeed);
    } else {
      robot.TurnR(100, TurnSpeed);
    }
 } else {
   robot.MoveF(1, MoveSpeed);
 }
}
