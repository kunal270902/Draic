#include <math.h>
int pwm1=3;
int dir1=4;
int pwm2=5;
int dir2=2;   //to motor driver 
int flag=0;
#define CH1 10
#define CH2 6
#define CH4 9     //from FLY sky controler
#define CH6 13
int ch1value;
int ch2value;
int ch4value; 
int ch6value;      // var for calculation 
double m, result;
bool T;
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue) {
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);                        // function to read the channel from FS            //????????????????????????????
}
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}
                   

void setup() {               //void setup 
  pinMode(pwm1,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir2,OUTPUT);      //motor driver 
  pinMode(CH1, INPUT);       //from FS ch1
  pinMode(CH2, INPUT);   //from FS ch2 
  pinMode(CH6, INPUT);
  Serial.begin(115200);
}


void loop() {
ch1value = readChannel(CH1, -180, 180, 0);
//Serial.println(ch1value);
ch2value = readChannel(CH2, -180, 180, 0);
//Serial.println(ch2value);
ch4value = readChannel(CH4, -180, 180, 0);
//Serial.println(ch4value);
ch6value = readSwitch(CH6, false);
delay(50);

   if ((ch1value < 25 && ch1value > -25)&&(ch2value < 25 && ch2value > -25))            //condition for no motion/stop
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    Serial.println("HALT");
    T=false;
   }
else if(ch1value != 0){                   //??????????((ch1value > 25 && ch1value < -25)&&(ch2value > 25 && ch2value < -25))
    m=ch2value/ch1value;
    T=true;
    }
   else 
   {
    T=true;
    } 

if (T==true){
  if (ch1value>0){
    result = atan(m)*180/3.1415;
  }
  else if (ch1value<0){
     result = (atan(m)*180/3.1415)+180;  
  }
  else if(ch1value==0){
    if (ch2value>0){
      result=90;
    }
    else if (ch2value<0){
      result=270;
    }
  }
Serial.println(result);
}
if (ch6value){

 if ((ch1value < 25 && ch1value > -25)&&(ch2value < 25 && ch2value > -25))            //condition for no motion/stop
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    Serial.println("HALT");
  }
 else if(result==0){
    Serial.println("Right");

    digitalWrite(dir1,1);
    analogWrite(pwm1,ch1value);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,0);
  
  }
else if(171<result && result<190){
    Serial.println("Left");

    digitalWrite(dir1,1);
    analogWrite(pwm1,0);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,-ch1value);

 }
 else if(81<result && result<100){
    Serial.println("Front");

    digitalWrite(dir1,1);
    analogWrite(pwm1,ch2value);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,ch2value);
}
else if(261<result && result<270){
    Serial.println("Back");

    digitalWrite(dir1,0);
    analogWrite(pwm1,-ch2value);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,-ch2value);
}



if(ch4value>25||ch4value<-25)
{
 if ((ch4value < 25 && ch4value > -25))
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    T=false;
   }

else if (ch4value>25)
{
  Serial.println("Immediate Right");
  digitalWrite(dir1,0);
  analogWrite(pwm1,ch4value);
  digitalWrite(dir2,1);
  analogWrite(pwm2,ch4value);
}
else if (ch4value<-25)
{
  Serial.println("Immediate Left");
  digitalWrite(dir1,1);
  analogWrite(pwm1,-ch4value);
  digitalWrite(dir2,0);
  analogWrite(pwm2,-ch4value);
}
}
}
else                                                     //flip condt
{
  if ((ch1value < 25 && ch1value > -25)&&(ch2value < 25 && ch2value > -25))            
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    Serial.println("HALT");
  }
 else if(result==0){
    Serial.println("Right");

    digitalWrite(dir1,1);
    analogWrite(pwm1,0);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,ch1value);
  
  }
else if(171<result && result<190){
    Serial.println("Left");

    digitalWrite(dir1,1);
    analogWrite(pwm1,-ch1value);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,0);

 }
 else if(81<result && result<100){
    Serial.println("Front");

    digitalWrite(dir1,1);
    analogWrite(pwm1,ch2value);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,ch2value);
}
else if(261<result && result<270){
    Serial.println("Back");

    digitalWrite(dir1,0);
    analogWrite(pwm1,-ch2value);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,-ch2value);
}


 
if(ch4value>25||ch4value<-25)
{
 if ((ch4value < 25 && ch4value > -25))
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    T=false;
   }

else if (ch4value>25)
{
  Serial.println("Immediate Right");
  digitalWrite(dir1,1);
  analogWrite(pwm1,ch4value);
  digitalWrite(dir2,0);
  analogWrite(pwm2,ch4value);
}
else if (ch4value<-25)
{
  Serial.println("Immediate Left");
  digitalWrite(dir1,0);
  analogWrite(pwm1,-ch4value);
  digitalWrite(dir2,1);
  analogWrite(pwm2,-ch4value);
}
}
}
}
