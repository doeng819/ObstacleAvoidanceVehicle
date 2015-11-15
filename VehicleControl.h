//msec needed for vehicle to turn 45 degree rotation
#define ROT45 200

enum Direction {
  FORWARD,
  REVERSE,
  RIGHT,
  LEFT,
  STOP
};

class VehicleControl
{
  public:
    VehicleControl(int mot1ena,int mot2ena,int mot1in1,int mot1in2,int mot2in1,int mot2in2);
    void MoveVehicle(enum Direction dir, int degree);
  private:
    int _mot1ena,_mot2ena,_mot1in1,_mot1in2,_mot2in1,_mot2in2;//pin number of Arduino that is connected with SIG pin
};
