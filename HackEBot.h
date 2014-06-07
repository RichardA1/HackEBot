// This is an ultra simple software servo driver. For best
// results, use with a timer0 interrupt to refresh() all
// your servos once every 20 milliseconds!
// Written by Limor Fried for Adafruit Industries, BSD license

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class HackEBot {
  public:
    HackEBot();
    void Go_forward(); //-- to drive forward
    void Go_backward(); //-- to drive backward
    void TurnR(); //-- to turn right
    void TurnL(); //-- to turn left
  private:
   // int _servoR;
   // int _servoL;
};
