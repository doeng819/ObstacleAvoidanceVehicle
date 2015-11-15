#include "Arduino.h"
#include <Servo.h>
#include "VehicleControl.h"
#include "ObstacleDetector.h"

//signals for VehicleControl object
#define E1 10 // Enable Pin for motor 1
#define E2 11 // Enable Pin for motor 2
#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12 // Control pin 1 for motor 2
#define I4 13 // Control pin 2 for motor 2

//signals for object detector object
#define I5 7 // Signal for ultrasonic sensor
#define O1 6 // Signal for ultrasonic sensor servo

/*
 CurPos   servo   absolute angles
 0        0       180 degrees (right most)
 1        45      135 degrees
 2        90       90 degrees (center)
 3        135      45 degrees
 4        180       0 degrees (left most)
*/
const int CurPosArray[] = {0, 45, 90, 135, 180};
const int CenterPos = 2;

Servo obsdetservo;
VehicleControl vehicle(E1, E2, I1, I2, I3, I4);
ObstacleDetector obsdetector(I5, obsdetservo);

void setup()
{
  obsdetservo.attach(O1);// attaches the servo to the servo object
  Serial.begin(9600);
}

void loop()
{

  //test_vehicle();

  int CurPos;
  int CurPosArraySize = sizeof(CurPosArray) / sizeof(CurPosArray[0]);

  obsdetector.TurnToPos(CurPosArray[CenterPos]);

  //found obstacle ahead at 90 degrees
  if (true == obsdetector.DetectObstacle())
  {
    vehicle.MoveVehicle(STOP, 0);
    CurPos = 0; //set to srv pos 0 (= 180 degrees in absolute measure/right most)

    //sweep servo from right to left
    while (CurPos < CurPosArraySize)
    {
      obsdetector.TurnToPos(CurPosArray[CurPos]);

      //found obstacle at new direction
      if (true == obsdetector.DetectObstacle())
      {
        //still obstacle exists
        Serial.print("obstacle detected at: ");
        Serial.println(CurPosArray[CurPos]);

        //Reached end of CurPosArray?
        if (CurPos == (CurPosArraySize-1))
        {
          Serial.println("Vehicle is surrounded.  Will turn 180 to exit :");
          vehicle.MoveVehicle(RIGHT, 180); //180 degrees : turn right by 90 degrees
          obsdetector.TurnToPos(CurPosArray[CenterPos]);
        }

        CurPos++;
      }
      else
      {
        //found a way out
        Serial.print("Vehicle can escape at: ");
        Serial.println(CurPosArray[CurPos]);

        switch (CurPosArray[CurPos])
        {
          case 0:
            vehicle.MoveVehicle(RIGHT, 90);
            break;
          case 45:
            vehicle.MoveVehicle(RIGHT, 45);
            break;
          case 90:
            break;
          case 135:
            vehicle.MoveVehicle(LEFT, 45);
            break;
          case 180:
            vehicle.MoveVehicle(LEFT, 90);
            break;
        }

        CurPos = CurPosArraySize; //in order to exit from the loop

      }//end if found obstacle at new direction
    } //end sweep servo from right to left
  } // end if found obstacle ahead at 90 degrees

  vehicle.MoveVehicle(FORWARD, 0);

}// end loop
