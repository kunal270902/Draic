#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

void loop() {
 
stand();
delay(5000);
//sit();
//delay(5000);



}

 int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void stand(){
   pwm.setPWM(5, 0, angleToPulse(60) );//br 2
  
 pwm.setPWM(4, 0, angleToPulse(50) );//br 1
  //delay(500);

  pwm.setPWM(6, 0, angleToPulse(45) );//br 3
 //delay(500);
  pwm.setPWM(0, 0, angleToPulse(100) );//bl 1
 //delay(500);
  pwm.setPWM(1, 0, angleToPulse(90) );//bl 2
 //delay(500);
  pwm.setPWM(2, 0, angleToPulse(-90) );//bl 3
 //delay(500);
  pwm.setPWM(12, 0, angleToPulse(100) );//fr 1
 //delay(500);
  pwm.setPWM(13, 0, angleToPulse(50) );//fr 2
 //delay(500);
  pwm.setPWM(14, 0, angleToPulse(180) );//fr 3
 //delay(500);
  pwm.setPWM(8, 0, angleToPulse(50) );//fl 1
 //delay(500);
  pwm.setPWM(9, 0, angleToPulse(95) );//fl 2
 //delay(500);
 pwm.setPWM(10, 0, angleToPulse(180) );//fl 3
  }

void sit(){
  pwm.setPWM(14, 0, angleToPulse(30) );//fl 1
  pwm.setPWM(9, 0, angleToPulse(130) );//fr 1
   pwm.setPWM(2, 0, angleToPulse(90) );//bl 1
   pwm.setPWM(3, 0, angleToPulse(35) );//br 1
  }
