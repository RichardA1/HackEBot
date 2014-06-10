/*
  HackEBot.cpp - Library for moving the Hack-E-Bot.
  Created by Richard Albritton, June 9, 2014.
  Released into the public domain.
*/

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "HackEBot.h"

HackEBot::HackEBot(int L, int R)
{
  servoL = L;
  servoR = R;
  pinMode(servoL, OUTPUT);
  pinMode(servoR, OUTPUT);
  //For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
  // 604 microseconds at 30 times = CW 360%
  // 876 microseconds at 30 times = CCW 360%
  //const int turnCW = 604;
  //const int turnCCW = 856;
}

void HackEBot::MoveF(){ // Drive drive backward
    // Start to turn the left wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(604);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(856);
    digitalWrite(servoL, LOW);
    delay(10);
}

void HackEBot::MoveB(){ // Drive drive forward
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(856);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(604);
    digitalWrite(servoL, LOW);
    delay(10);
}

void HackEBot::TurnL(){ // Turn Right
    // Start to turn the left wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(604);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(604);
    digitalWrite(servoL, LOW);
    delay(10);
}

void HackEBot::TurnR(){ // Turn Left
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(856);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(856);
    digitalWrite(servoL, LOW);
    delay(10);
}
