//VH_RADIUS 30 //回転半径30cm
//sqrt(2)*VH_RADIUS = 42.4264068712cm
//const long COLLISION_THRES = 42;
const long COLLISION_THRES = 100;

class ObstacleDetector
{
  public:
    class Ultrasonic
    {
      public:
        void DistanceMeasure(void);
        long microsecondsToCentimeters(void);
        int _sigpin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
      private:
        long duration;// the Pulse time received;
    };

    ObstacleDetector(int usonicpin, Servo obsdetservo);
    boolean DetectObstacle(void);
    void TurnToPos(int degree);

  private:
    Ultrasonic usonic;
    Servo obsservo;

};
