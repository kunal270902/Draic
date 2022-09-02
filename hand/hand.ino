
#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

void loop() {
 pwm.setPWM(0, 0, angleToPulse(160) );
 delay(500);
 pwm.setPWM(8, 0, angleToPulse(1) );
  delay(500);
 pwm.setPWM(4, 0, angleToPulse(45) );
 delay(500);

  for( int angle =0; angle<=90; angle +=10){
      delay(50);
       //pwm.setPWM(4, 0, angleToPulse(angle) );
         pwm.setPWM(12, 0, angleToPulse(angle) );
   }
       for( int angle =90; angle>=0; angle -=10){
      delay(50);
      //pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(12, 0, angleToPulse(angle) );
}

}

 int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
