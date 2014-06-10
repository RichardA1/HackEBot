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

HackEBot::HackEBot(uint8_t servoR, uint8_t servoL)
{
  pinMode(servoR, OUTPUT);
  pinMode(servoL, OUTPUT);
  //For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
  // 604 microseconds at 30 times = CW 360%
  // 876 microseconds at 30 times = CCW 360%
  //const int turnCW = 604;
  //const int turnCCW = 856;
}

void HackEBot::moveF(){ // Drive drive forward
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
void HackEBot::moveB(){ // Drive drive backward
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
void HackEBot::TurnL(){ // Turn Left
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
void HackEBot::TurnR(){ // Turn Right
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
