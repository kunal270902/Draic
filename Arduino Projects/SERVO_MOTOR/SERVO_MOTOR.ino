#include<Servo.h>
Servo Myservo;



void setup() {
   Serial.begin(9600);
   Myservo.attach(11);
}
void loop()
{
Myservo.write(60);


  
}
  
