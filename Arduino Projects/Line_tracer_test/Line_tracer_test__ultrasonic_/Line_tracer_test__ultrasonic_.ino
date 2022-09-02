#define echoPin 32
#define trigPin 30 
int motor1pin1 = 11;
int motor1pin2 = 10;
int motor2pin1 = 6;
int motor2pin2 = 5;
int IRSensor1 = 2;
int IRSensor2 = 3;
int speed_Left = 100;
int speed_Right = 150;


void stopp();
long duration;
int distance;
void forward();
 
void left();
void right();
s
void setup()
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  pinMode (IRSensor1, INPUT);
  pinMode (IRSensor2, INPUT);

}

void loop() 
{
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
    if (statusSensor1 && statusSensor2  == 0)
    {
      forward();
    }
    if (statusSensor1 && statusSensor2  == 1){
      stop();
    }
  

  if (statusSensor1 == 1)
  {
    left();
  }
  if (statusSensor2 == 1)
  {
   right();
  }
  
/*if (distance<=20)
 { 
left();  
    
 }*/

}


void forward()
{
  analogWrite(motor1pin2, speed_Left);
  analogWrite(motor2pin2, speed_Right);

}
void stop()
{
  speed_Left=0;
    speed_Right=0;
  analogWrite(motor1pin2, speed_Left);
  analogWrite(motor2pin2, speed_Right);
}
void left()
{
  speed_Left=0;
    speed_Right=0;
     
    speed_Left=50;
    speed_Right=50;

    Serial.print("Turn");
    analogWrite(motor1pin2, speed_Left);
      analogWrite(motor1pin1, speed_Left);
}
void right()
{
  speed_Left=0;
    speed_Right=0;
     
    speed_Right=50;
    

    Serial.print("Turn");
    analogWrite(motor2pin2, speed_Right);
     analogWrite(motor2pin1, speed_Right);
}

/*int dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return (distance);
}*/
