#define echoPin1 PB12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 PB13 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 PB14 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 PB15
#define echoPin3 PA11 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin3 PA12
#define red PA3
#define blue PA2
#define green PA1

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
    pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
    pinMode(trigPin3, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin3, INPUT); // Sets the echoPin as an INPUT
  pinMode(red , OUTPUT);
  pinMode(blue , OUTPUT);
  pinMode(green , OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // put your main code here, to run repeatedly:
  int C = (utrs(trigPin2,echoPin2));
  
  int L = (utrs(trigPin1,echoPin1));
  
  int R = (utrs(trigPin3,echoPin3));

  if (C==0 && L==0 && R==0){
  analogWrite(red, 65535);
  analogWrite(green, 0);
  analogWrite(blue, 0);
  }
  else if (C==0 && L==0 && R==1){
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 65535);
  }
  if (C==0 && L==1 && R==0){
  analogWrite(red, 0);
  analogWrite(green, 65535);
  analogWrite(blue, 0);
  }
  if (C==0 && L==1 && R==1){
  analogWrite(red, 65535);
  analogWrite(green, 49344);
  analogWrite(blue, 52535);
  }
if (C==1 && L==0 && R==0){
  analogWrite(red, 65535);
  analogWrite(green, 17733);
  analogWrite(blue, 0);
  }
  if (C==1 && L==0 && R==1){
  analogWrite(red, 65535);
  analogWrite(green, 60138);
  analogWrite(blue, 0);
  }
  if (C==1 && L==1 && R==0){
  analogWrite(red, 61166);
  analogWrite(green, 33410);
  analogWrite(blue, 61166);
  }
  if (C==1 && L==1 && R==1){
  analogWrite(red, 65535);
  analogWrite(green, 65535);
  analogWrite(blue, 65535);
  }


  
  delay(1000);
}

int utrs(int tpi, int epi){
  digitalWrite(tpi, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(tpi, HIGH);
  delayMicroseconds(10);
  digitalWrite(tpi, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(epi, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //return(distance);
  if (distance>=10 && distance<=350)
    return(1);
  else
    return(0);
  }
