#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)
int sit=15;
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

void loop() {
 

stand();
delay(1000);
sitdown();
/*for( int angle =90; angle<=0; angle +=90){
      delay(50);
       //pwm.setPWM(3, 0, angleToPulse(angle) );
       delay(1000);
         pwm.setPWM(5, 0, angleToPulse(angle) );
}
for( int angle =0; angle<=60; angle +=60){
      delay(50);
       //pwm.setPWM(3, 0, angleToPulse(angle) );
       delay(1000);
         pwm.setPWM(3, 0, angleToPulse(angle) );
}
for( int angle =0; angle<=90; angle +=90){
      delay(50);
       //pwm.setPWM(3, 0, angleToPulse(angle) );
       delay(1000);
         pwm.setPWM(5, 0, angleToPulse(angle) );

}

for( int angle =60; angle<=0; angle +=60){
      delay(50);
       //pwm.setPWM(3, 0, angleToPulse(angle) );
       delay(1000);
         pwm.setPWM(3, 0, angleToPulse(angle) );
}
*/






}

void stand()
{
  pwm.setPWM(5, 0, angleToPulse(90) );//fl 2
  
 pwm.setPWM(3, 0, angleToPulse(0) );//fl 1
  //delay(500);

  pwm.setPWM(4, 0, angleToPulse(50) );//fl 3
 //delay(500);
  pwm.setPWM(2, 0, angleToPulse(180) );//fr 1
 //delay(500);
  pwm.setPWM(1, 0, angleToPulse(55) );//fr 2
 //delay(500);
  pwm.setPWM(0, 0, angleToPulse(-90) );//fr 3
 //delay(500);
  pwm.setPWM(9, 0, angleToPulse(20) );//bl 1
 //delay(500);
  pwm.setPWM(7, 0, angleToPulse(90) );//bl 2
 //delay(500);
  pwm.setPWM(8, 0, angleToPulse(180) );//bl 3
 //delay(500);
  pwm.setPWM(14, 0, angleToPulse(125) );//br 1
 //delay(500);
  pwm.setPWM(13, 0, angleToPulse(65) );//br 2
 //delay(500);
 pwm.setPWM(12, 0, angleToPulse(180) );//br 3*/
   pwm.setPWM(0, 0, angleToPulse(-90) );//fr 3
  pwm.setPWM(4, 0, angleToPulse(50) );//fl 3
  pwm.setPWM(8, 0, angleToPulse(180) );//bl 3
 pwm.setPWM(12, 0, angleToPulse(180) );//br 3
}
void sitdown()
{
  pwm.setPWM(5, 0, angleToPulse(90+sit));//fl 2
  
 pwm.setPWM(3, 0, angleToPulse(0));//fl 1
  //delay(500);

  pwm.setPWM(4, 0, angleToPulse(50) );//fl 3
 //delay(500);
  pwm.setPWM(2, 0, angleToPulse(180) );//fr 1
 //delay(500);
  pwm.setPWM(1, 0, angleToPulse(55-sit) );//fr 2
 //delay(500);
  pwm.setPWM(0, 0, angleToPulse(-90) );//fr 3
 //delay(500);
  pwm.setPWM(9, 0, angleToPulse(20) );//bl 1
 //delay(500);
  pwm.setPWM(7, 0, angleToPulse(90) );//bl 2
 //delay(500);
  pwm.setPWM(8, 0, angleToPulse(180) );//bl 3
 //delay(500);
  pwm.setPWM(14, 0, angleToPulse(125) );//br 1
 //delay(500);
  pwm.setPWM(13, 0, angleToPulse(65) );//br 2
 //delay(500);
 pwm.setPWM(12, 0, angleToPulse(180) );//br 3*/
   pwm.setPWM(0, 0, angleToPulse(-90) );//fr 3
  pwm.setPWM(4, 0, angleToPulse(50) );//fl 3
  pwm.setPWM(8, 0, angleToPulse(180) );//bl 3
 pwm.setPWM(12, 0, angleToPulse(180) );//br 3
}






 int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
