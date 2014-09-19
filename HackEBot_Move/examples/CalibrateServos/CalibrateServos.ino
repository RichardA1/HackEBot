#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  #include <avr/power.h>
#endif
#include <HackEBot_Move.h>

// Set-up the movement controls using;
// 		LeftPin = Left Servo Pin
// 		RightPin = Right Servo Pin
// Adjust each servo pot until the servo stops spinning. 

// HackEBot_Move robot(LeftPin, RightPin);
   HackEBot_Move robot(12, 7);

void setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif
  // ...
}

void loop()
{
  robot.Calibrate();
}
