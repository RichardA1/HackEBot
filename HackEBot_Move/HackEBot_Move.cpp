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
  UpperL = 2100; //-- Upper pulse for the FS90R Servo from Data Sheet (2100us)
  CenterL = 1500; //-- Center pulse for the FS90R Servo from Data Sheet (between 900us and 2100us)
  LowerL = 900; //-- Lower pulse for the FS90R Servo from Data Sheet (900us)
  UpperR = 2100; //-- Upper pulse for the FS90R Servo from Data Sheet (2100us)
  CenterR = 1500; //-- Center pulse for the FS90R Servo from Data Sheet (between 900us and 2100us)
  LowerR = 900; //-- Lower pulse for the FS90R Servo from Data Sheet (900us)
  pinMode(servoL, OUTPUT);
  pinMode(servoR, OUTPUT);
  //speedL = 2; // From Data Sheet (1500 - 900)/100 gives us the number we add to center in order to reach 1% speed.
  //speedR = 2;
}

long HackEBot_Move::ServoSetup(int D, int F, int G, int H, int J, int K){ // This is used to tell the Arduino exactly what the pulse range is for each servo.
  
  UpperL = D;  //-- D  the upper limit of the Left Servo
  CenterL = F;  //-- F  the center point of the Left Servo
  LowerL = G;  //-- G  the lower limit of the Left Servo
  
  UpperR = H;  //-- H  the upper limit of the Right Servo
  CenterR = J;  //-- J  the center point of the Right Servo
  LowerR = K;  //-- K  the lower limit of the Right Servo

  //Left Servo Forward -- map(speed, CenterL, UpperL, 0, 100);
  //Left Servo Backward -- map(speed, LowerL, CenterL, 0, 100);
  //Right Servo Forward -- map(speed, CenterR, UpperR, 0, 100);
  //Right Servo Backward -- map(speed, LowerR, CenterR, 0, 100);

}

void HackEBot_Move::Calibrate(){ // Calibrate the servos
  // Start to turn the left wheel CW.
  digitalWrite(servoL, HIGH);
  delayMicroseconds(CenterL);
  digitalWrite(servoL, LOW);
  // Start to turn the right wheel CCW.
  digitalWrite(servoR, HIGH);
  delayMicroseconds(CenterR);
  digitalWrite(servoR, LOW);
  //delay(10);
}

void HackEBot_Move::MoveF(int S, int Z){ // Drive drive forward, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
      // Start to turn the left wheel CW.
      digitalWrite(servoL, HIGH);
      delayMicroseconds(CenterL + map(speed, CenterL, UpperL, 0, 100));
      digitalWrite(servoL, LOW);
      // Start to turn the right wheel CCW.
      digitalWrite(servoR, HIGH);
      delayMicroseconds(CenterR - map(speed, LowerR, CenterR, 0, 100));
      digitalWrite(servoR, LOW);
      //delay(10);
	steps--;
  }
}

void HackEBot_Move::MoveB(int S, int Z){ // Drive drive backward, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL - map(speed, LowerL, CenterL, 0, 100));
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(CenterR + map(speed, CenterR, UpperR, 0, 100));
    digitalWrite(servoR, LOW);
    //delay(10);
	steps--;
  }
}

void HackEBot_Move::TurnL(int S, int Z){ // Turn Left, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL + map(speed, CenterL, UpperL, 0, 100));
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(CenterR + map(speed, CenterR, UpperR, 0, 100));
    digitalWrite(servoR, LOW);
    //delay(10);
	steps--;
  }
}

void HackEBot_Move::TurnR(int S, int Z){ // Turn Right, S = repeat number, Z = Speed.
  steps = S;
  speed = Z;
    while(0 < steps){
    // Start to turn the left wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(CenterL - map(speed, LowerL, CenterL, 0, 100));
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(CenterR - map(speed, LowerR, CenterR, 0, 100));
    digitalWrite(servoR, LOW);
    //delay(10);
	steps--;
	
  }
}
