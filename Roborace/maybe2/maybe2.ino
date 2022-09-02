
#define BLYNK_TEMPLATE_ID "TMPLGwNM3bqd"
#define BLYNK_DEVICE_NAME "jujutsu kaisen"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

int pinValueSPEED=70;

#include "BlynkEdgent.h"

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

BLYNK_WRITE(V0)//FWD
{
int pinValueUP = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueUP);
  if (pinValueUP==1)
  {
    digitalWrite(D0,1);
    digitalWrite(D1,1);
    analogWrite(D5,pinValueSPEED);
    analogWrite(D6,pinValueSPEED);
   }
 else     {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}

BLYNK_WRITE(V1)//Bk
{
int  pinValueBk = param.asInt();
  Serial.print("Back:");
  Serial.println(pinValueBk);
  if (pinValueBk==1)
  {
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    analogWrite(D5,pinValueSPEED);
    analogWrite(D6,pinValueSPEED);
   }
else      {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}

BLYNK_WRITE(V3)//RIGHT
{
int  pinValueRt = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueRt);
  if (pinValueRt==1)
  {
    digitalWrite(D0,1);
    digitalWrite(D1,1);
    analogWrite(D5,70);
    analogWrite(D6,0);
   }
 else     {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}
BLYNK_WRITE(V2)//Left
{
int  pinValueLt = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueLt);
  if (pinValueLt==1)
  {
    digitalWrite(D0,1);
    digitalWrite(D1,1);
    analogWrite(D5,0);
    analogWrite(D6,70);
   }
 else     {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}
BLYNK_WRITE(V5)//IR
{
int  pinValueIR = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueIR);
  if (pinValueIR==1)
  {
    digitalWrite(D0,1);
    digitalWrite(D1,0);
    analogWrite(D5,pinValueSPEED);
    analogWrite(D6,pinValueSPEED);
   }
      
 else
   {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
 }

BLYNK_WRITE(V6)//IL
{
int  pinValueIL = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueIL);
  if (pinValueIL==1)
  {
    digitalWrite(D0,0);
    digitalWrite(D1,1);
    analogWrite(D5,pinValueSPEED);
    analogWrite(D6,pinValueSPEED);
   }
   else
   {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}
BLYNK_WRITE(V7)//IL
{
int  pinValueIL = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueIL);
  if (pinValueIL==1)
  {
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    analogWrite(D5,0);
    analogWrite(D6,pinValueSPEED);
   }
   else
   {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}
BLYNK_WRITE(V8)//IL
{
int  pinValueIL = param.asInt();
  Serial.print("UP:");
  Serial.println(pinValueIL);
  if (pinValueIL==1)
  {
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    analogWrite(D5,pinValueSPEED);
    analogWrite(D6,0);
   }
   else
   {
    analogWrite(D5,0);
    analogWrite(D6,0);   
   }
}
BLYNK_WRITE(V4)
{
  pinValueSPEED= param.asInt();
  Serial.print(pinValueSPEED);
}
void loop() {
  BlynkEdgent.run();
}
