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

HackEBot::HackEBot(int L, int R, int C, int W)
{
  servoL = L;
  servoR = R;
  offsetR = C;
  offsetL = W;
  pinMode(servoL, OUTPUT);
  pinMode(servoR, OUTPUT);
  //For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
  // 604 microseconds at 30 times = CW 360%
  // 876 microseconds at 30 times = CCW 360%
  turnCW = 604;
  turnCCW = 856;
}

void HackEBot::MoveF(int S){ // Drive drive backward
  steps = S;
    while(0 < steps){
      // Start to turn the left wheel CW.
      digitalWrite(servoR, HIGH);
      delayMicroseconds(turnCW + offsetR);
      digitalWrite(servoR, LOW);
      // Start to turn the right wheel CCW.
      digitalWrite(servoL, HIGH);
      delayMicroseconds(turnCCW - offsetL);
      digitalWrite(servoL, LOW);
      delay(10);
	steps--;
  }
}

void HackEBot::MoveB(int S){ // Drive drive forward
  steps = S;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW + offsetR);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW - offsetL);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}

void HackEBot::TurnL(int S){ // Turn Left
  steps = S;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW + offsetR);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW - offsetL);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}

void HackEBot::TurnR(int S){ // Turn Right
  steps = S;
    while(0 < steps){
    // Start to turn the left wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW + offsetR);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW - offsetL);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}
