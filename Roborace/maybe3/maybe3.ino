#define BLYNK_TEMPLATE_ID "TMPLRzUJLzix"
#define BLYNK_DEVICE_NAME "Naruto" 
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#include "cmath"
int pinValuex,pinValuey,pinValueL,pinValueR,pinvaluey,pinvaluex;
int pinspeed=70;
int pinSpeed=70;

BLYNK_WRITE(V4)
{
  pinspeed= param.asInt();
  Serial.print(pinspeed);
}
BLYNK_WRITE(V2)
{
  pinSpeed= param.asInt();
  Serial.print(pinSpeed);
}






BLYNK_WRITE(V0)//JOY_x
{
  pinValuex = param.asInt();
}

BLYNK_WRITE(V1)//JOY_y
{
  pinValuey = param.asInt();
  Serial.print("X:");
  Serial.println(pinValuex);
  Serial.print("Y:");
  Serial.println(pinValuey);

  
  double m, result;
  bool T;
  if ((pinValuey==0)&&(pinValuex==0))
  {
    analogWrite(D5,0);
    analogWrite(D6,0);

    T=false;
   }
   else if(pinValuex != 0){
    m=pinValuey/pinValuex;
    T=true;
    }
   else 
   {
    T=true;
    } 

if (T==true){
  if (pinValuex>0){
    result = atan(m)*180/3.1415;
  }
  else if (pinValuex<0){
     result = (atan(m)*180/3.1415)+180;  
  }
  else if(pinValuex==0){
    if (pinValuey>0){
      result=90;
    }
    else if (pinValuey<0){
      result=270;
    }
  }
  Serial.print(result);
}

  if(30<result && result<60){
    Serial.println("NW");

    digitalWrite(D0,0);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinspeed/2);

  }
  else if(80<=result && result <=89){
    Serial.println("lft");
    digitalWrite(D0,1);
    analogWrite(D5,0);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinspeed);

  }
    else if(97<=result && result <=120){
    Serial.println("lft");
    digitalWrite(D0,1);
    analogWrite(D5,0);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinspeed);

  }
  else if(120<result && result<150){
    Serial.println("SW");
    digitalWrite(D0,1);
    analogWrite(D5,pinspeed/2);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinspeed);

  }

  else if(210<result && result<240){
    Serial.println("SW");
    digitalWrite(D0,0);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinspeed/2);
 
  }
  else if(-60<result && result<-30){
    Serial.println("NW");
    digitalWrite(D0,0);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinspeed/2);

  }
  else if(-90<=result && result<=-60){
    Serial.println("rht");
    digitalWrite(D0,1);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,1);
    analogWrite(D6,0);
  

  }
  else if(240<=result && result<=270){
    Serial.println("rht");
    digitalWrite(D0,1);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,1);
    analogWrite(D6,0);
  

  }
  else if ((pinValuex == 0) && (pinValuey > 0))
  {
    Serial.println("lft");
    digitalWrite(D0,1);
    analogWrite(D5,0);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinspeed);
  

    }
  else if ((pinValuex == 0) && (pinValuey < 0))
  {
    Serial.println("rht");
    digitalWrite(D0,1);
    analogWrite(D5,pinspeed);
  
    digitalWrite(D1,1);
    analogWrite(D6,0);
  

    }

    else{
  Serial.println("Wait");
  analogWrite(D5,0);
  analogWrite(D6,0);

  }
}







BLYNK_WRITE(V5)//JOY_y
{
  pinvaluex = param.asInt();
  Serial.print("X:");
  Serial.println(pinvaluex);

  if (pinvaluex==0)
  {
    analogWrite(D5,0);
    analogWrite(D6,0);
    Serial.println("wait");
  }
if (pinvaluex!=0)
{
  

if (pinvaluex>0){
    Serial.println("fwd");
    digitalWrite(D0,1);
    analogWrite(D5,pinSpeed);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinSpeed);
  }
 
   else if(pinvaluex<0){
    Serial.println("bck");
    digitalWrite(D0,0);
    analogWrite(D5,pinSpeed);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinSpeed);
  

  }
} 
    else{
  Serial.println("Wait");
  analogWrite(D5,0);
  analogWrite(D6,0);

  }
}
  

void setup()
{
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);

  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
