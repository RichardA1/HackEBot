#include <HackEBot.h>

const int sonarTrig = 2;   // Connect the sonar signal pin to this pin on the Trinket.
const int sonarEcho = 3;

// Number in cm when the rover will reverse and try to navigate around.
const int obstacle = 8;

// Duration of a ping, distance in inches, distance converted to cm.
long duration, inches, cm;

// Set-up the movement controls using;
// 		L = Left Servo Pin
// 		R = Right Servo Pin
// 		C = Right Servo offset
// 		W = Left Servo offset
// Servo offsets should be 0 unless the robot dose not drive strait.
// HackEBot robot(L, R, C, W);
   HackEBot robot(0, 4, 0, 0);
   
int randNumber = 0;  // Used to choose a direction to turn

void setup()
{
  pinMode(sonarTrig, OUTPUT);
  pinMode(sonarEcho, INPUT);
}

/* The Hack-E-Bot can now be programmed to move by giving it instructions like:
Go_forward(); -- to drive forward
Go_backward(); -- to drive backward
TurnR(); -- to turn right
TurnL(); -- to turn left
*/
void loop()
{  
   SonarPing();
   //SonarScan();
  robot.MoveF(3);
}

void SonarPing() {
  /* The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  Give a short LOW pulse beforehand to ensure a clean HIGH pulse:*/
  digitalWrite(sonarTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarTrig, LOW);
  /* The sonarEcho pin is used to read the signal from the PING))): a HIGH
  pulse whose duration is the time (in microseconds) from the sending
  of the ping to the reception of its echo off of an object.*/
  duration = pulseIn(sonarEcho, HIGH);
  
  // convert the time into a distance.
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  if ( cm < obstacle ) {
    // back_track * delay(15) = distance the rover will back-up during 
    // obstacle avoidance.
      robot.MoveB(30);
      randNumber = random(200);
      if (randNumber < 99) {
        robot.TurnL(16);
      } else {
        robot.TurnR(16);
      }
    }
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
