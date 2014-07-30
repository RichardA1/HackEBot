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

#include "HackEBot_Move.h"

HackEBot_Move::HackEBot_Move(int L, int R)
{
  servoL = L;
  servoR = R;
  turnCW = 1500;
  turnCCW = 1500;
  pinMode(servoL, OUTPUT);
  pinMode(servoR, OUTPUT);
}

void HackEBot_Move::MoveF(int S, int Z){ // Drive drive forward, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
      // Start to turn the left wheel CW.
      digitalWrite(servoR, HIGH);
      delayMicroseconds(turnCCW - speed);
      digitalWrite(servoR, LOW);
      // Start to turn the right wheel CCW.
      digitalWrite(servoL, HIGH);
      delayMicroseconds(turnCW + speed);
      digitalWrite(servoL, LOW);
      delay(10);
	steps--;
  }
}

void HackEBot_Move::MoveB(int S, int Z){ // Drive drive backward, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW + speed);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW - speed);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}

void HackEBot_Move::TurnL(int S, int Z){ // Turn Left, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW - speed);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW - speed);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}

void HackEBot_Move::TurnR(int S, int Z){ // Turn Right, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW + speed);
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW + speed);
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}

void HackEBot_Move::Calibrate(){ // Calibrate the servos
  // Start to turn the left wheel CW.
  digitalWrite(servoR, HIGH);
  delayMicroseconds(turnCCW);
  digitalWrite(servoR, LOW);
  // Start to turn the right wheel CCW.
  digitalWrite(servoL, HIGH);
  delayMicroseconds(turnCW);
  digitalWrite(servoL, LOW);
  delay(10);
}