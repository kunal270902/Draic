#define echoPin 39
#define trigPin  38
int motor1pin1 = 51;
int motor1pin2 = 53;
int motor2pin1 = 50;
int motor2pin2 = 52;

int speed_Left = 150;
int speed_Right = 150;
int speed_Left_turn= 50;
int speed_Right_turn=50;
int flag = 1;
long duration;
int distance;

void setup() {
   pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);

 if(distance<=15)
{
   /*speed_Left=0;
  speed_Right=0;
  analogWrite(motor1pin2, speed_Left);
  analogWrite(motor2pin2, speed_Right);
speed_Left=0;
 speed_Right=0;*/


 speed_Left+=10;
 speed_Right-=10;
 Serial.print("Turn");
 analogWrite(motor1pin1, speed_Left);
 analogWrite(motor2pin1, speed_Right);

}

  speed_Left=150;
  speed_Right=150;
  analogWrite(motor1pin2, speed_Left);
  analogWrite(motor2pin2, speed_Right);

  


 
//if (distance>15)
//{
//  flag=1;
//
//  speed_Left=150;
//  speed_Right=150;
//  analogWrite(motor1pin2, speed_Left);
//  analogWrite(motor2pin2, speed_Right);
//  Serial.print("run");
//
//}
////}
//else if(distance<=15)
//{
//   /*speed_Left=0;
//  speed_Right=0;
//  analogWrite(motor1pin2, speed_Left);
//  analogWrite(motor2pin2, speed_Right);
//speed_Left=0;
// speed_Right=0;*/
//
//
// speed_Left+=10;
// speed_Right-=10;
// Serial.print("Turn");
// analogWrite(motor1pin1, speed_Left);
// analogWrite(motor2pin1, speed_Right);
// flag=1;
//
//}


}
