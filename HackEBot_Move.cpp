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
  CenterL = 1500;
  CenterR = 1500;
  pinMode(servoL, OUTPUT);
  pinMode(servoR, OUTPUT);
}

long HackEBot_Move::ServoSetup(int L, int l, int R, int r){ // Calibrate the servos
  //-- L  the forward limit of the Left Servo
  //-- l  the backward limit of the Left Servo
  //-- R  the forward limit of the Right Servo
  //-- r  the backward limit of the Right Servo
  
  LShift = abs(L - l)/2; // Find the center pulse for the Left Servo
  CenterL = LShift + max(L, l);
  
  RShift = abs(R - r)/2; // Find the center pulse for the Right Servo
  CenterR = RShift + max(R, r);
  delay(10);
  
  speedL = round(LShift/100);
  speedR = round(RShift/100);
}

void HackEBot_Move::Calibrate(){ // Calibrate the servos
  // Start to turn the left wheel CW.
  digitalWrite(servoR, HIGH);
  delayMicroseconds(CenterR);
  digitalWrite(servoR, LOW);
  // Start to turn the right wheel CCW.
  digitalWrite(servoL, HIGH);
  delayMicroseconds(CenterL);
  digitalWrite(servoL, LOW);
  delay(10);
}

void HackEBot_Move::MoveF(int S, int Z){ // Drive drive forward, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
      // Start to turn the left wheel CW.
      digitalWrite(servoR, HIGH);
      delayMicroseconds(CenterR - (speedR * speed));
      digitalWrite(servoR, LOW);
      // Start to turn the right wheel CCW.
      digitalWrite(servoL, HIGH);
      delayMicroseconds(CenterL + (speedL * speed));
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
    delayMicroseconds(CenterR + (speedR * speed));
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL - (speedL * speed));
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
    delayMicroseconds(CenterR - (speedR * speed));
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL - (speedL * speed));
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
    delayMicroseconds(CenterR + (speedR * speed));
    digitalWrite(servoR, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL + (speedL * speed));
    digitalWrite(servoL, LOW);
    delay(10);
	steps--;
  }
}
