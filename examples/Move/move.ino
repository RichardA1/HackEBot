<<<<<<< HEAD
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  #include <avr/power.h>
#endif
=======
>>>>>>> 86dd206d720f6430031a4b8dcadedb81e1537a8b
#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
<<<<<<< HEAD
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif
  // ...
=======
>>>>>>> 86dd206d720f6430031a4b8dcadedb81e1537a8b
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
