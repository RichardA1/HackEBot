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
// Adjust each servo pot until the servo stops spinning. 

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
<<<<<<< HEAD
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
  #endif
  // ...
  // The ServoSetup() lets you set the servo parameters. This will help make the servos run more consistently.
  // ---- UpperL = the upper limit of the Left Servo
  // ---- CenterL = the center point of the Left Servo
  // ---- LowerL = the lower limit of the Left Servo
  // ---- UpperR = the upper limit of the Right Servo
  // ---- CenterR = the center point of the Right Servo// --  LowerR = the lower limit of the Right Servo
  // -- ServoSetup(UpperL, CenterL, LowerL, UpperR, CenterR, LowerR)
  robot.ServoSetup(2100,1500,900,2100,1500,900);
=======
robot.ServoSetup(1500, 1500);
>>>>>>> 86dd206d720f6430031a4b8dcadedb81e1537a8b
}

int MoveSpeed = 100;

void loop()
{
  robot.MoveF(30, MoveSpeed);
}
