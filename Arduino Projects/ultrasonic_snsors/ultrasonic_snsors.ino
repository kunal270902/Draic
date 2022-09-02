#include<Servo.h>
Servo Myservo;
int pos;
const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 9; // Echo Pin of Ultrasonic Sensor
bool turn_left;
bool turn_right;
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
Myservo.attach(7);

}


void loop() {
   
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   servo_forward();
   if (cm<=20){
   servo_left();
   delay(1000);
   if (cm>45)
   {
    turn_left=true;
    Serial.println("left");
   }
  
   servo_right();
      delay(1000);
      if (cm>45)
   {
    turn_right=true;
    Serial.println("right");
   }

   servo_forward();
   delay(1000);

   }
   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void servo_left()
{
  Myservo.write(180);
}
void servo_forward()
{
  Myservo.write(90);
}
void servo_right()
{
  Myservo.write(0);
}
