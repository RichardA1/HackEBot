#include <Servo.h>

Servo RightS;
Servo LeftS;

int servoR = 13;
int servoL = 8;

void setup()
{
  RightS.attach(servoR);
  LeftS.attach(servoL);
}

int speed = map(50, 0, 100, 0, 90); // This remaps a value of 0%-100% to 0°-90°;
int moveTime = 200;
int turnTime = 50;

void loop()
{
  MoveF(speed, moveTime);
  TurnR(speed, turnTime);
  MoveF(speed, moveTime);
  TurnR(speed, turnTime);
  MoveF(speed, moveTime);
  TurnR(speed, turnTime);
  MoveF(speed, moveTime);
  TurnR(speed, turnTime);
  MoveF(speed, moveTime);
  TurnL(speed, turnTime);
  MoveF(speed, moveTime);
  TurnL(speed, turnTime);
  MoveF(speed, moveTime);
  TurnL(speed, turnTime);
  MoveF(speed, moveTime);
  TurnL(speed, turnTime);
  delay(600);
}

void MoveF(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  RightS.write(S);
  LeftS.write(S + 90);
  delay(T);
}

void MoveB(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  RightS.write(S + 90);
  LeftS.write(S);
  delay(T);
}

void TurnL(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  RightS.write(S);
  LeftS.write(S);
  delay(T);
}

void TurnR(int S, int T){ // Drive drive forward, S = driveSpeed, T = driveTime.
  RightS.write(S + 90);
  LeftS.write(S + 90);
  delay(T);
}
