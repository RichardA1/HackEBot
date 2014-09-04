#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  #include <avr/power.h>
#endif
#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif
  // ...
}

int MoveSpeed = 200;
int TurnSpeed = 150;

void loop()
{
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnR(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, MoveSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  robot.MoveF(30, MoveSpeed);
  robot.TurnL(16, TurnSpeed);
  delay(600);
}
