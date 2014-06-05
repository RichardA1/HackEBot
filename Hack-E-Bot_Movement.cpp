/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Hack-E-Bot_Movement.h"

Hack-E-Bot_Movement::Hack-E-Bot_Movement(int servoR, int servoL)
{
  pinMode(servoR, OUTPUT);
  pinMode(servoL, OUTPUT);
  _servoR = servoR;
  _servoL = servoL;
  //For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
  // 604 microseconds at 30 times = CW 360%
  // 876 microseconds at 30 times = CCW 360%
  const int turnCW = 604;
  const int turnCCW = 856;
}

void Hack-E-Bot_Movement::Go_forward(){ // Drive drive forward
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
void Hack-E-Bot_Movement::Go_backward(){ // Drive drive backward
    // Start to turn the left wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
void Hack-E-Bot_Movement::TurnL(){ // Turn Left
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
void Hack-E-Bot_Movement::TurnR(){ // Turn Right
    // Start to turn the left wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
