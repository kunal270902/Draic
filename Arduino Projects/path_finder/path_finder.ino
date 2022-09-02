#include<Servo.h>
Servo Myservo;
int pos;
int dir1= 48;
int dir2= 52;
int dir3= 49;
int dir4= 53;
int pwm1= 11;
int pwm2= 13;
int pwm3= 10;
int pwm4= 12;

const int pingPin = 8;
const int echoPin = 9;

bool turn_left;
bool turn_right;
bool forward_move=true;


void setup() {
   Serial.begin(9600);
   Myservo.attach(7);
}

void right(){
 digitalWrite(dir1,LOW);
 digitalWrite(dir2,LOW);
 digitalWrite(dir3,LOW);
 digitalWrite(dir4,LOW);
  
  }
 void left(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  }
 void forward(){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  
  }
 void backward(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,LOW);
  }

  void wait(){
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
  }
  void velocity(){
  analogWrite(pwm1,50);
  analogWrite(pwm2,50);
  analogWrite(pwm3,50);
  analogWrite(pwm4,50);
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
int ultrasonic()
{
 long duration;
int distance;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   distance = microsecondsToCentimeters(duration);
   Serial.print(distance);
   Serial.print("cm");
   Serial.println();
   return(distance);
}





void loop()
{
   int dist_left,dist_right;
   int idistance=ultrasonic();
   int distance_forward=ultrasonic();
   servo_forward();
   velocity();
   forward();
   if(idistance<=30)
   {
    wait();
    servo_left();
    dist_left=ultrasonic();
    Serial.print(dist_left);
    Serial.print("cm");
    delay(1000);
    servo_right();
    dist_right=ultrasonic(); 
    Serial.print(dist_right);
    Serial.print("cm");
    servo_forward(); 
    delay(1000);    
   }
   if(dist_left>30)
   {
      left();
      delay(1000);
   }
   else if (dist_right>30)
   {
    right();
    delay(1000);
    
   }
   else
   {
    wait();
   }
  

}
