/*
This example will turn the on-board LED on when an object gets within 8cm of the Sonar sensor.

The same basic format can allow your Hack-E-Bot to react to it's environment.
*/

// Attach the Sonar.h library to this code
#include <HackEBot_Sonar.h>

// Set-up the Sonar sensor for object detection;
// 		sonarTrig = Sends the chirp (Blue wire)
// 		sonarEcho = Listens for the chirp (Green wire)
// Sonar Obstacle(sonarTrig, sonarEcho);
HackEBot_Sonar Obstacle(4, 2);

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop()
{ 
 // When Obstacle.Ping(D) is used, it will return:
 //       "true" is an obstacle is detected 
 //       "false" if there is no obstacle
 // The distance from an obstacle is set by entering the distance, D, in centimetres.
  if (Obstacle.Ping(8)){     // if an object gets within 8cm of the sonar sensor, do the following:
   digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
 } else {                    // if an object is not within 8cm of the sonar sensor, then do the following:
   digitalWrite(led, LOW);   // turn the LED off by making the voltage LOW
 }
  delay(10); // wait for 1/100th of a second.
}
