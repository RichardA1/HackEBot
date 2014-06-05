class Hack-E-Bot_Movement
{
  public:
    Hack-E-Bot_Movement(int Rpin, int Lpin);
    void Go_forward(); -- to drive forward
    void Go_backward(); -- to drive backward
    void TurnR(); -- to turn right
    void TurnL(); -- to turn left
  private:
    int _Rpin;
    int _Lpin;
};
