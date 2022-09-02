#define BLYNK_TEMPLATE_ID "TMPLRzUJLzix"
#define BLYNK_DEVICE_NAME "Naruto" 
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#include "cmath"
int pinValuex,pinValuey,pinValueL,pinValueR,pinvaluex,pinvaluey;
int pinspeed=70;
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

if(30<result && result<60){
    Serial.println("NE");

    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex/4);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);

  }
  else if(60<=result && result <=120){
    Serial.println("FRONT");
    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);

  }
  else if(120<result && result<150){
    Serial.println("NW");
    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex/4);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);

  }
 
  else if(210<result && result<240){
    Serial.println("SW");
    digitalWrite(D0,0);
    analogWrite(D5,pinvaluex/4);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinvaluex);
 
  }
  else if(-60<result && result<-30){
    Serial.println("SE");
    digitalWrite(D0,0);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinvaluex/4);

  }
  else if(-90<=result && result<=-60){
    Serial.println("Back");
    digitalWrite(D0,0);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinvaluex);
  

  }
  else if(240<=result && result<=270){
    Serial.println("Back");
    digitalWrite(D0,0);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinvaluex);
  

  }
  else if ((pinValuex == 0) && (pinValuey > 0))
  {
    Serial.println("FRONT");
    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);
  

    }
  else if ((pinValuex == 0) && (pinValuey < 0))
  {
    Serial.println("Back");
    digitalWrite(D0,0);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,0);
    analogWrite(D6,pinvaluex);
  

    }
}
else{
  Serial.println("Wait");
  analogWrite(D5,0);
  analogWrite(D6,0);

  }
  }
BLYNK_WRITE(V2)//Left turn
{
  pinValueL = param.asInt();
  int pinValueL = param.asInt();
  //Serial.print(pinValueL);
  if (pinValueL==1)
  {
  digitalWrite(D0,HIGH);
  analogWrite(D5,0);

  digitalWrite(D1,HIGH);
  analogWrite(D6,pinvaluex);


  }
  else{
    analogWrite(D5,0);
    analogWrite(D6,0);

    }
}

  BLYNK_WRITE(V3)//right turn
{
  int pinValueR = param.asInt();
  Serial.print(pinValueR);
  if (pinValueR==1)
  {
  digitalWrite(D0,LOW);
  analogWrite(D5,pinvaluex);

  digitalWrite(D1,LOW);
  analogWrite(D6,0);


  }
  else{
    analogWrite(D5,0);
    analogWrite(D6,0);

    }
}

BLYNK_WRITE(V4)
{
  pinspeed= param.asInt();
  Serial.print(pinspeed);
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
BLYNK_WRITE(V5)//JOY_x
{
  pinvaluex = param.asInt();
}

BLYNK_WRITE(V6)//JOY_y
{
  pinvaluey = param.asInt();
  Serial.print("X:");
  Serial.println(pinvaluex);
  Serial.print("Y:");
  Serial.println(pinvaluey);

  
  double m, result;
  bool T;
  if ((pinvaluey==0)&&(pinvaluex==0))
  {
    analogWrite(D5,0);
    analogWrite(D6,0);

    T=false;
   }
   else if(pinvaluex != 0){
    m=pinvaluey/pinvaluex;
    T=true;
    }
   else 
   {
    T=true;
    } 

if (T==true){
  if (pinvaluex>0){
    result = atan(m)*180/3.1415;
  }
  else if (pinvaluex<0){
     result = (atan(m)*180/3.1415)+180;  
  }
  else if(pinvaluex==0){
    if (pinvaluey>0){
      result=90;
    }
    else if (pinvaluey<0){
      result=270;
    }
  }
  Serial.print(result);

  if (-30<=result && result<=30){
    Serial.println("Back");
    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);
  

  }



  else if(150<=result && result<=210){
    Serial.println("Forward");
    digitalWrite(D0,1);
    analogWrite(D5,pinvaluex);
  
    digitalWrite(D1,1);
    analogWrite(D6,pinvaluex);
  }
}
else{
  Serial.println("Wait");
  analogWrite(D5,0);
  analogWrite(D6,0);

  }
  }

void loop() {
  BlynkEdgent.run();
}
