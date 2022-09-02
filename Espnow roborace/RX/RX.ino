

#include <ESP8266WiFi.h>
#include <espnow.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
 int BTS,BTS1,FWD,REV,LEFT,RIGHT,BWD_LEFT,BWD_RIGHT,IR,IL;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  /*Serial.print("Int BTS: ");
  Serial.println(myData.BTS);
  Serial.print("Int BTS1: ");
  Serial.println(myData.BTS1);
  Serial.print("Int FWD: ");
  Serial.println(myData.FWD);
  Serial.print("Int REV: ");
  Serial.println(myData.REV);
  Serial.print("Int LEFT: ");
  Serial.println(myData.LEFT);
  Serial.print("Int RIGHT: ");
  Serial.println(myData.RIGHT);
  Serial.print("Int BWD LEFT: ");
  Serial.println(myData.BWD_LEFT);
  Serial.print("Int BWD RIGHT: ");
  Serial.println(myData.BWD_RIGHT);
  Serial.print("Int IR: ");
  Serial.println(myData.IR);
  Serial.print("Int IL: ");
  Serial.println(myData.IL);                 */

}
 int flag=0;
int speeddBut1(int pwm,bool buttonState)
{  
  if(pwm>180)
  {
    pwm=90;
  }
   while(pwm<200)
{
  
int pwmf;


if (buttonState == 1 && flag==0)
  {
       flag=1;
       pwmf=pwm+20;
       // Serial.println(pwmf);
        
       return pwmf;
      }
      

else if(buttonState ==  0){
  flag = 0;
}
return pwm;
}
}

int flag1=0;
int speeddBut2(int pwm1,bool buttonState1)


{
  //Serial.println(pwm1);
if(pwm1<50)
  {
    pwm1=50;
    return pwm1;
  }
   while(pwm1>50)

{
   
  
int pwmf1;


if (buttonState1 == 1 && flag1==0)
  {
       flag1=1;
       pwmf1=pwm1-20;
       // Serial.println(pwmf1);
        
       return pwmf1;
      }
      

else if(buttonState1 ==  0){
  flag1 = 0;
}
return pwm1;
}
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
 // pinMode(26,INPUT);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
}
int speedd=50;
int speedd1=50;
void loop() {
speedd=speeddBut1(speedd, myData.BTS);
delay(20);
speedd=speeddBut2(speedd, myData.BTS1);
delay(20);
Serial.println(speedd);
 if(myData.FWD==1)
{
  digitalWrite(D0,1);
  analogWrite(D5,speedd);
  digitalWrite(D1,1);
  analogWrite(D6,speedd);
  Serial.println("Front");
  }
else if(myData.REV==1)
{
  digitalWrite(D0,0);
  analogWrite(D5,speedd);
  digitalWrite(D1,0);
  analogWrite(D6,speedd);
  Serial.println("Back");
  
}

else if(myData.LEFT==1)
{
  digitalWrite(D0,1);
  analogWrite(D5,70);
  digitalWrite(D1,0);
  analogWrite(D6,0);
  Serial.println("LEFT");
  }
else if(myData.RIGHT==1)
{
  digitalWrite(D0,0);
  analogWrite(D5,0);
  digitalWrite(D1,1);
  analogWrite(D6,70);
  Serial.println("RIGHT");
  
}
else if(myData.BWD_LEFT==1)
{
  digitalWrite(D0,0);
  analogWrite(D5,70);
  digitalWrite(D1,0);
  analogWrite(D6,0);
  Serial.println("BWD_LEFT");
  }
else if(myData.BWD_RIGHT==1)
{
  digitalWrite(D0,0);
  analogWrite(D5,0);
  digitalWrite(D1,0);
  analogWrite(D6,70);
  Serial.println("BWD_RIGHT");
  
}



else if(myData.IR==1)
{
  digitalWrite(D0,0);
  analogWrite(D5,70);
  digitalWrite(D1,1);
  analogWrite(D6,70);
  Serial.println("IR");
  
  }
else if(myData.IL==1)
{
  digitalWrite(D0,1);
  analogWrite(D5,70);
  digitalWrite(D1,0);
  analogWrite(D6,70);
  Serial.println("IL");
  
}
else
 {
  analogWrite(D5,0);
  analogWrite(D6,0);
  Serial.println("Wait");
  
 }
}
 
