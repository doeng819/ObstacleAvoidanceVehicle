/*Begin the detection and get the pulse back signal*/
void ObstacleDetector::Ultrasonic::DistanceMeasure(void)
{
  int _pin = _sigpin;

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);
  pinMode(_pin, INPUT);
  duration = pulseIn(_pin, HIGH);
}

/*The measured distance from the range 0 to 400 Centimeters*/
long ObstacleDetector::Ultrasonic::microsecondsToCentimeters(void)
{
  return duration / 29 / 2;
}

ObstacleDetector::ObstacleDetector(int usonicpin, Servo obsdetservo)
{
  usonic._sigpin = usonicpin;
  obsservo = obsdetservo;
}

boolean ObstacleDetector::DetectObstacle(void)
{
  long RangeInCentimeters;

  usonic.DistanceMeasure();// get the current signal time;
  RangeInCentimeters = usonic.microsecondsToCentimeters();//convert the time to centimeters

  if (RangeInCentimeters <= COLLISION_THRES)
  {
    Serial.print("Obstacle detected! (cm):");
    Serial.println(RangeInCentimeters);
    return true;
  }
  else
    return false;
}

void ObstacleDetector::TurnToPos(int degree)
{
  obsservo.write(degree);          // tell servo to go to position in variable 'pos'
  delay(1500);                       // waits for the servo to reach the position

  Serial.print("Sensor position (degrees) : ");
  Serial.println(degree);
}
