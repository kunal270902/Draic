#include "cmath"
int pwm1 = 1;
int pwm2 =2 ;
int pwm3 = 3;
int pwm4 = 4;
int dir1 = 5;
int dir2 = 6;
int dir1 = 7;
int dir2 = 8;
int CH2 = 9,CH1 = 10;

int pinValueL,pinValueR;
int ch2Value,ch1value;


int readChannel1(int channelInput, int minLimit, int maxLimit, int defaultValue) {
  int ch1 = pulseIn(channelInput, HIGH
 
  
  if (ch1 < 100) return defaultValue;
  return map(ch1, 1000, 2000, minLimit, maxLimit);
 
}

int readChannel1(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch1 = pulseIn(channelInput, HIGH, 30000);
   if (ch1 < 100) return defaultValue;
  return map(ch1, 1000, 2000, minLimit, maxLimit);
}





Serial.println(CH1,CH2);
float a,result;
int flag;

void setup() {
  Serial.begin(115200);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT) ;
  pinMode(pwm4, OUTPUT):
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
}














void loop() {
  ch1Value = readChannel1(CH1, -255, 255, 0);
  ch2Value = readChannel2(CH2, -255, 255, 0);
}
if if (ch2Value < 25 && ch2Value > -25)&& {(ch1Value < 25 && ch1Value > -25){
    Serial.println("stop");
    
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);

    analogWrite(pwm3,0);

    analogWrite(pwm4,0);       //for stop


flag=0;
else if(CH1 != 0){
    a=pinValuey/pinValuex;
    flag=1;
}
else{
  flag=1;
}
if (flag==1){
  if (CH1>0){
    result = atan(a)*180/3.1415;
  }
  else if (CH1<0){
     result = (atan(a)*180/3.1415)+180;  
  }
else if(CH1==0){
    if (Ch2>0){
      result=90;
    }
    else if (CH2<0){
      result=270;
    }
  }
  Serial.print(result);
if (-30<=result && result<=30){
    Serial.println("RIGHT/E");
    digitalWrite(dir1,0);
    analogWrite(pwm1,0);
    digitalWrite(dir2,0);
    analogWrite(pwm2,0);
    digitalWrite(dir3,1);
    analogWrite(pwm3,-ch1value);
    digitalWrite(dir4,1);
    analogWrite(pwm4,-ch1value);


else if(30<result && result<60){
    Serial.println("NE");

    digitalWrite(dir1,0);
    analogWrite(pwm1,+ch1value);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,0);
  
    digitalWrite(dir3,1);
    analogWrite(pwm3,-ch2value);
  
    digitalWrite(dir4,1);
    analogWrite(pwm4,0);
  }
  else if(60<=result && result <=120){
    Serial.println("FRONT");
    digitalWrite(dir1,0);
    analogWrite(pwm1,+ch1value);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,0);
  
    digitalWrite(dir3,1);
    analogWrite(pwm3,+ch1value);
  
    digitalWrite(dir4,0);
    analogWrite(pwm4,0);
  }

   
    
  
  
  
  
  }

















 
  Serial.println(ch2Value);
  if (ch2Value > 25) {
    digitalWrite(dir, HIGH);
    analogWrite(pwm, ch2Value);
  }
  
  if(ch2Value<-25) {
    digitalWrite(dir, LOW);
    analogWrite(pwm, - ch2Value);
  }

}
