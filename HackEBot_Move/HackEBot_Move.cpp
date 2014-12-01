/*
  HackEBot.cpp - Library for moving the Hack-E-Bot.
  Created by Richard Albritton, June 9, 2014.
  Released into the public domain.
*/
#include "Arduino.h"
#include "../Servo/Servo.h"
#include "HackEBot_Move.h"

Servo RightS;
Servo LeftS;

HackEBot_Move::HackEBot_Move(int R, int L)
{
  servoR = R;
  servoL = L;
  RightS.attach(servoR);
  LeftS.attach(servoL);
}

void HackEBot_Move::Center(){ // Calibrate the servos
  // Start to turn the left wheel CW.
  RightS.write(90);
  LeftS.write(90);
}

void HackEBot_Move::MoveF(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  driveSpeed = S;
  driveTime = T;
  RightS.write(driveSpeed);
  LeftS.write(driveSpeed + 90);
  delay(driveTime);
}

void HackEBot_Move::MoveB(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  driveSpeed = S;
  driveTime = T;
  RightS.write(driveSpeed + 90);
  LeftS.write(driveSpeed);
  delay(driveTime);
}

void HackEBot_Move::TurnL(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  driveSpeed = S;
  driveTime = T;
  RightS.write(driveSpeed);
  LeftS.write(driveSpeed);
  delay(driveTime);
}

void HackEBot_Move::TurnR(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  driveSpeed = S;
  driveTime = T;
  RightS.write(driveSpeed + 90);
  LeftS.write(driveSpeed + 90);
  delay(driveTime);
}
