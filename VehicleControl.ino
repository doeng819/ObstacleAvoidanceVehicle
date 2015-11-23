
VehicleControl::VehicleControl(int mot1ena,int mot2ena,int mot1in1,int mot1in2,int mot2in1,int mot2in2)
{
  _mot1ena = mot1ena;
  _mot2ena = mot2ena;
  _mot1in1 = mot1in1;
  _mot1in2 = mot1in2;
  _mot2in1 = mot2in1;
  _mot2in2 = mot2in2;

  pinMode(_mot1ena, OUTPUT);
  pinMode(_mot2ena, OUTPUT);
  pinMode(_mot1in1, OUTPUT);
  pinMode(_mot1in2, OUTPUT);
  pinMode(_mot2in1, OUTPUT);
  pinMode(_mot2in2, OUTPUT);
}

void VehicleControl::MoveVehicle(enum Direction dir, int degree)
{

  //always do disable-enable when change direction
  digitalWrite(_mot1ena, LOW); //disable motor1
  digitalWrite(_mot2ena, LOW); //disable motor2
  delay(200);
  digitalWrite(_mot1ena, HIGH); //enable motor1
  digitalWrite(_mot2ena, HIGH); //enable motor2

  switch(dir)
  {
    case FORWARD:
      Serial.println("MoveVehicle : FORWARD");
//     digitalWrite(_mot1in1, HIGH); //control pin1 for motor1 forward
      analogWrite(_mot1in1, 120); //control pin1 for motor1 forward 
      digitalWrite(_mot1in2, LOW);  //control pin2 for motor1 forward
//      digitalWrite(_mot2in1, HIGH); //control pin1 for motor2 forward
      analogWrite(_mot2in1, 120); //control pin1 for motor2 forward
      digitalWrite(_mot2in2, LOW);  //control pin2 for motor2 forward
      break;
    case REVERSE:
      Serial.println("MoveVehicle : REVERSE");
      digitalWrite(_mot1in1, LOW);  //control pin1 for motor1 reverse
      digitalWrite(_mot1in2, HIGH); //control pin2 for motor1 reverse
      digitalWrite(_mot2in1, LOW);  //control pin1 for motor2 reverse
      digitalWrite(_mot2in2, HIGH); //control pin2 for motor2 reverse
      break;
    case STOP:
      Serial.println("MoveVehicle : STOP");
      digitalWrite(_mot1ena, LOW); //disable motor1
      digitalWrite(_mot2ena, LOW); //disable motor2
      delay(200);
      break;
    case RIGHT:
      if (0 == degree)
      {
        break;
      }
      Serial.print("MoveVehicle : RIGHT at ");
      Serial.println(degree);
      digitalWrite(_mot1in1, LOW);  //control pin1 for motor1 reverse
      digitalWrite(_mot1in2, HIGH); //control pin2 for motor1 reverse
      digitalWrite(_mot2in1, HIGH); //control pin1 for motor2 forward
      digitalWrite(_mot2in2, LOW);  //control pin2 for motor2 forward
      switch (degree) {
        case 45:
          delay(ROT45);
          break;
        case 90:
          delay(ROT45*2);
          break;
        case 135:
          delay(ROT45*3);
          break;
        case 180:
          delay(ROT45*4);
          break;
      }
      digitalWrite(_mot1ena, LOW); //disable motor1
      digitalWrite(_mot2ena, LOW); //disable motor2
      delay(200);
      break;
    case LEFT:
      if (0 == degree)
      {
        break;
      }
      Serial.print("MoveVehicle : LEFT at ");
      Serial.println(degree);
      digitalWrite(_mot1in1, HIGH); //control pin1 for motor1 forward
      digitalWrite(_mot1in2, LOW);  //control pin2 for motor1 forward
      digitalWrite(_mot2in1, LOW);  //control pin1 for motor2 reverse
      digitalWrite(_mot2in2, HIGH); //control pin2 for motor2 reverse
      switch (degree) {
        case 45:
          delay(ROT45);
          break;
        case 90:
          delay(ROT45*2);
          break;
        case 135:
          delay(ROT45*3);
          break;
        case 180:
          delay(ROT45*4);
          break;
      }
//      digitalWrite(_mot1ena, LOW); //disable motor1
//      digitalWrite(_mot2ena, LOW); //disable motor2
//      delay(200);
      break;
  }

}
