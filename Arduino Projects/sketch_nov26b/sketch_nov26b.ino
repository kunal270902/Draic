#define echoPin 32
#define trigPin 30 
int motor1pin1 = 5;
int motor1pin2 = 6;
int motor2pin1 = 2;
int motor2pin2 = 3;

int speed_Left = 0;
int speed_Right = 0;
int speed_Left_turn= 50;
int speed_Right_turn= 50;
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
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");

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

  if (distance<=15)
  {
    if(speed_Left_turn<=50 && speed_Right_turn<=50)
    { 
      speed_Left_turn+=10;
      speed_Right_turn+=10;
      Serial.print("Turn");
      analogWrite(motor1pin1, speed_Left_turn);
      analogWrite(motor2pin2, speed_Right_turn);
    }
    else
    {
      speed_Left_turn=50;
      speed_Right_turn=50;
      Serial.print("Turn");
      analogWrite(motor1pin1, speed_Left_turn);
      analogWrite(motor2pin2, speed_Right_turn);
    }
    
    
    if (distance>=15)
    {
      delay(1000);
      speed_Left=0;
      speed_Right=0;
    }
  }
  
  else
  {
    if(speed_Left<250 && speed_Right<250)
    {
      speed_Left+=50;
      speed_Right+=50;
      analogWrite(motor1pin1, speed_Left);
      analogWrite(motor2pin1, speed_Right);
      delay(1000);
     }
     else
     {
      speed_Left=250;
      speed_Right=250;
      analogWrite(motor1pin1, speed_Left);
      analogWrite(motor2pin1, speed_Right);
      delay(1000);
     }
  }
}
