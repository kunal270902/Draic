void setup() {
  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);//pwm1
  pinMode(D4,OUTPUT);//pwm2
  pinMode(D5,OUTPUT);//dir1
  pinMode(D6,OUTPUT);//dir2
  // put your setup code here, to run once
  Serial.begin(115200);
  
}


int speeddBut1(int pwm,bool buttonState)
{
   
  
int flag=1;

int pwmf;
if (buttonState == 1 && flag==1)
      {
       pwmf=pwm+20;
        Serial.println(pwmf);
        flag=0;
       
      }
int flag1=1;


if (buttonState == 1 && flag==1)
      {
        pwmf=pwm-20;
        Serial.println(pwmf);
        flag1=0;
      }
        return pwmf;   

}
   



void loop() {
  // put your main code here, to run repeatedly:
int BTS=digitalRead(D10);  
Serial.print("X");
Serial.println(analogRead(D1));
int pinValuex=analogRead(D1);
Serial.print("Y");
Serial.println(analogRead(D0));
int pinValuey=analogRead(D0);
int speedd;           
speedd=speeddBut1(50, BTS);


delay(1000);
if(D2!=0){
  

if(pinValuey>3000)
{
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  
  }
else if(pinValuey<2000)
{
   analogWrite(D3,speedd);
  digitalWrite(D5,0);
  analogWrite(D3,speedd);
  digitalWrite(D5,0);
}

if(pinValuex>3000)
{
  analogWrite(D3,0);
  digitalWrite(D5,1);
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  
  }
else if(pinValuex<2000)
{
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  analogWrite(D3,0);
  digitalWrite(D5,1);
  
}
 else
 {
  analogWrite(D3,0);
  analogWrite(D3,0);
 }
}

else if(D2==0)
{
 if(pinValuex>3000)
{
  analogWrite(D3,speedd);
  digitalWrite(D5,0);
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  }
else if(pinValuex<2000)
{
  analogWrite(D3,speedd);
  digitalWrite(D5,1);
  analogWrite(D3,speedd);
  digitalWrite(D5,0);  
} 
 
}

}
