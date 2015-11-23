/*
void setup()
{
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
}

void loop()
{
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    delay(200);
    digitalWrite(E1, HIGH);
    digitalWrite(E2, HIGH);

 //フルスピード
//    digitalWrite(I1, HIGH);
//    digitalWrite(I2, LOW);
//    digitalWrite(I3, HIGH);
//    digitalWrite(I4, LOW);

//これだと回る
    analogWrite(I1, 120); //pwm
    digitalWrite(I2, LOW); //dir control
    analogWrite(I3, 120); //pwm
    digitalWrite(I4, LOW); //dir control

    delay(3000);

    // change direction

//    digitalWrite(E1, LOW);
//    digitalWrite(E2, LOW);
//    delay(200);
//    digitalWrite(E1, HIGH);
//    digitalWrite(E2, HIGH);

//    digitalWrite(I1, LOW);
//    digitalWrite(I2, HIGH);
//    digitalWrite(I3, LOW);
//    digitalWrite(I4, HIGH);

//    delay(3000);
   
}

*/
