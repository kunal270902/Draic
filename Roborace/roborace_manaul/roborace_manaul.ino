int pwm1=5;
int pwm2=3;
int dir1=4;
int dir2=2;
#include <math.h>
int m, result;
bool T;
#define CH1 10
#define CH2 6
#define CH4 9

int ch1value;
int ch2value;
int ch4value;
//int channelInput;
//int ch = pulseIn(channelInput, HIGH, 30000);
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue) {
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH4, INPUT);
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
ch1value = readChannel(CH1, -255, 255, 0);
//Serial.println(ch1value);
ch2value = readChannel(CH2, -255, 255, 0);
//Serial.println(ch2value);
ch4value = readChannel(CH4, -255, 255, 0);
//Serial.println(ch4value);
delay(500);

   if ((ch1value < 25 && ch1value > -25)&&(ch2value < 25 && ch2value > -25))
  { 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    Serial.println("HALT");
    T=false;
   }
else if(ch1value != 0){
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
 if(result==0.00){
    Serial.println("Right");

    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,HIGH);
    analogWrite(pwm2,0);
  
  }
  
else if(171<result && result<190){
    Serial.println("Left");

    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,0);
  
    digitalWrite(dir2,HIGH);
    analogWrite(pwm2,225);}


else if(1<result && result<10){
    Serial.println("Right");

    digitalWrite(dir1,1);
    analogWrite(pwm1,255);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,0);
  
  }


else if(1<result && result<10){
    Serial.println("Right");

    digitalWrite(dir1,1);
    analogWrite(pwm1,255);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,0);
  
  }
  else if(351<result && result<359){
    Serial.println("Right");

    digitalWrite(dir1,1);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,00);
  
  }
  
  
  

  else if(11<result && result<20){
    Serial.println("Right+10");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,25);
  
  }


 else if(21<result && result<30){
    Serial.println("Right+20");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,50);
  
  }
    else if(31<result && result<40){
    Serial.println("Right+30");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,75);
  
  }
   else if(41<result && result<50){
    Serial.println("Right+40");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,100);
   }


 else if(51<result && result<60){
    Serial.println("Right+50");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,125);
   }
    else if(61<result && result<70){
    Serial.println("Right+60");

    digitalWrite(dir1,1);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,150);
   }
    else if(71<result && result<80){
    Serial.println("Right+70");

    digitalWrite(dir1,1);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,175);
   }
    else if(81<result && result<100){
    Serial.println("Front");

    digitalWrite(dir1,1);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,225);
}
 else if(101<result && result<110){
    Serial.println("Left+70");

    digitalWrite(dir1,1);
    analogWrite(pwm1,175);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
 else if(111<result && result<120){
    Serial.println("Left+60");

    digitalWrite(dir1,1);
    analogWrite(pwm1,150);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
 else if(121<result && result<130){
    Serial.println("Left+50");

    digitalWrite(dir1,1);
    analogWrite(pwm1,125);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
else if(131<result && result<140){
    Serial.println("Left+40");

    digitalWrite(dir1,1);
    analogWrite(pwm1,100);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
 else if(141<result && result<150){
    Serial.println("Left+30");

    digitalWrite(dir1,1);
    analogWrite(pwm1,75);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
 else if(151<result && result<160){
    Serial.println("Left+20");

    digitalWrite(dir1,1);
    analogWrite(pwm1,50);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }

else if(161<result && result<170){
    Serial.println("Left+10");

    digitalWrite(dir1,1);
    analogWrite(pwm1,25);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,200);

 }
 
//===================================================================back===========================================================================//


else if(341<result && result<350){
    Serial.println("Right-10");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,25);
  
  }


 else if(331<result && result<340){
    Serial.println("Right-20");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,50);
  
  }
    else if(321<result && result<330){
    Serial.println("Right-30");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,75);
  
  }
   else if(311<result && result<320){
    Serial.println("Right-40");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,100);
   }


 else if(301<result && result<310){
    Serial.println("Right-50");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,125);
   }
    else if(291<result && result<300){
    Serial.println("Right-60");

    digitalWrite(dir1,0);
    analogWrite(pwm1,200);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,150);
   }
    else if(281<result && result<290){
    Serial.println("Right+70");

    digitalWrite(dir1,1);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,175);
   }
    else if(261<result && result<280){
    Serial.println("Back");

    digitalWrite(dir1,0);
    analogWrite(pwm1,225);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,225);
}
 else if(251<result && result<260){
    Serial.println("Left-70");

    digitalWrite(dir1,0);
    analogWrite(pwm1,175);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }
 else if(241<result && result<250){
    Serial.println("Left-60");

    digitalWrite(dir1,0);
    analogWrite(pwm1,150);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }
 else if(231<result && result<240){
    Serial.println("Left-50");

    digitalWrite(dir1,0);
    analogWrite(pwm1,125);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }
else if(221<result && result<230){
    Serial.println("Left-40");

    digitalWrite(dir1,0);
    analogWrite(pwm1,100);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }
 else if(211<result && result<220){
    Serial.println("Left-30");

    digitalWrite(dir1,0);
    analogWrite(pwm1,75);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }
 else if(201<result && result<210){
    Serial.println("Left-20");

    digitalWrite(dir1,0);
    analogWrite(pwm1,50);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }

else if(191<result && result<200){
    Serial.println("Left-10");

    digitalWrite(dir1,0);
    analogWrite(pwm1,25);
  
    digitalWrite(dir2,0);
    analogWrite(pwm2,200);

 }

else if(171<result && result<190){
    Serial.println("Left");

    digitalWrite(dir1,1);
    analogWrite(pwm1,0);
  
    digitalWrite(dir2,1);
    analogWrite(pwm2,225);

 }

//=========================================================Immediate Turns CH4================================================================//

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
  analogWrite(pwm1,200);
  digitalWrite(dir2,0);
  analogWrite(pwm2,200);
}
else if (ch4value<-25)
{
  Serial.println("Immediate Left");
  digitalWrite(dir1,0);
  analogWrite(pwm1,200);
  digitalWrite(dir2,1);
  analogWrite(pwm2,200);
}
}
}
