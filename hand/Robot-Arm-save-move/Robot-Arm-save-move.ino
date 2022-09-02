#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;
int pot5 = A4;
int pot6 = A5;

int valPot1;
int valPot2;
int valPot3;
int valPot4;
int valPot5;
int valPot6;

int servo1S1=0; int servo1S2=0;
int servo2S1=0; int servo2S2=0;
int servo3S1=0; int servo3S2=0;
int servo4S1=0; int servo4S2=0;
int servo5S1=0; int servo5S2=0;
int servo6S1=0; int servo6S2=0;

int Saveval=0; int SaveNo=0;

int doitval=0; int doitNo=0;

int potVal=0;

void setup(){
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(6);
  servo5.attach(5); 
  servo6.attach(3);

  pinMode(4,INPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
}

void loop(){

int servo1R = servo1.read(); int servo2R = servo2.read(); int servo3R = servo3.read();
int servo4R = servo4.read(); int servo5R = servo5.read(); int servo6R = servo6.read();

int Save=digitalRead(4); int potSw=digitalRead(8); int doit=digitalRead(7); 
/*
Serial.print("servo1S1 = "); Serial.println(servo1S1);
Serial.print("servo1S2 = "); Serial.println(servo1S2);
Serial.print("servo2S1 = "); Serial.println(servo2S1);
Serial.print("servo2S2 = "); Serial.println(servo2S2);
Serial.print("servo5S1 = "); Serial.println(servo5S1);
Serial.print("servo5S2 = "); Serial.println(servo5S2);
Serial.print("servo6S1 = "); Serial.println(servo6S1);
Serial.print("servo6S2 = "); Serial.println(servo6S2); 
*/
if (potSw==1){delay(300); digitalWrite(13,HIGH); potVal++;}
else{digitalWrite(13,LOW);}

if (potVal>1){potVal=0;}
  
if(potVal==1){digitalWrite(13,HIGH);
  valPot1 = analogRead(pot1);
  valPot1 = map (valPot1, 0, 1023, 1, 179); 
  servo1.write(valPot1);
  
  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 1, 179);
  servo2.write(valPot2);

  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 1, 179);
  servo3.write(valPot3);

  valPot4 = analogRead(pot4);
  valPot4 = map (valPot4, 0, 1023, 1, 179);
  servo4.write(valPot4);

  valPot5 = analogRead(pot5);
  valPot5 = map (valPot5, 0, 1023, 1, 179);
  servo5.write(valPot5);

  valPot6 = analogRead(pot6);
  valPot6 = map (valPot6, 0, 1023, 80, 179);
  servo6.write(valPot6);
  delay(5); }
  
  if (Save==1&&SaveNo==0){delay(300);
 servo1S1=servo1R; 
 servo2S1=servo2R; 
 servo3S1=servo3R;
 servo4S1=servo4R; 
 servo5S1=servo5R; 
 servo6S1=servo6R;
 SaveNo=1; delay(200);}
  
 else if (Save==1&&SaveNo==1){delay(300); 
 servo1S2=servo1R; 
 servo2S2=servo2R; 
 servo3S2=servo3R;
 servo4S2=servo4R; 
 servo5S2=servo5R; 
 servo6S2=servo6R;
 SaveNo=0; delay(200);} 
  
  if (doit==1&&doitval==0){delay(300);
     if (servo1R==servo1S1){}
     if (servo1R>servo1S1){
  for (int s=servo1R; s>=servo1S1; s --) {servo1.write(s);
  delay(15);} }
     if (servo1R<servo1S1){
  for (int s=servo1R; s<=servo1S1; s ++) {servo1.write(s);
  delay(15);} }

     if (servo2R==servo2S1){}
     if (servo2R>servo2S1){
  for (int s=servo2R; s>=servo2S1; s --) {servo2.write(s);
  delay(15);} }
     if (servo2R<servo2S1){
  for (int s=servo2R; s<=servo2S1; s ++) {servo2.write(s);
  delay(15);} }

     if (servo3R==servo3S1){}
     if (servo3R>servo3S1){
  for (int s=servo3R; s>=servo3S1; s --) {servo3.write(s);
  delay(15);} }
     if (servo3R<servo3S1){
  for (int s=servo3R; s<=servo3S1; s ++) {servo3.write(s);
  delay(15);} }

     if (servo4R==servo4S1){}
     if (servo4R>servo4S1){
  for (int s=servo4R; s>=servo4S1; s --) {servo4.write(s);
  delay(15);} }
     if (servo4R<servo4S1){
  for (int s=servo4R; s<=servo4S1; s ++) {servo4.write(s);
  delay(15);} } 

     if (servo5R==servo5S1){}
     if (servo5R>servo5S1){
  for (int s=servo5R; s>=servo5S1; s --) {servo5.write(s);
  delay(15);} }
     if (servo5R<servo5S1){
  for (int s=servo5R; s<=servo5S1; s ++) {servo5.write(s);
  delay(15);} }

     if (servo6R==servo6S1){}
     if (servo6R>servo6S1){
  for (int s=servo6R; s>=servo6S1; s --) {servo6.write(s);
  delay(15);} }
     if (servo6R<servo6S1){
  for (int s=servo6R; s<=servo6S1; s ++) {servo6.write(s);
  delay(15);} }
//---------------------------------------------
     if (servo1S1==servo1S2){}
     if (servo1S1>servo1S2){
  for (int s=servo1S1; s>=servo1S2; s --) {servo1.write(s);
  delay(15);} }
     if (servo1S1<servo1S2){
  for (int s=servo1S1; s<=servo1S2; s ++) {servo1.write(s);
  delay(15);} }

     if (servo2S1==servo2S2){}
     if (servo2S1>servo2S2){
  for (int s=servo2S1; s>=servo2S2; s --) {servo2.write(s);
  delay(15);} }
     if (servo2S1<servo2S2){
  for (int s=servo2S1; s<=servo2S2; s ++) {servo2.write(s);
  delay(15);} }

     if (servo3S1==servo3S2){}
     if (servo3S1>servo3S2){
  for (int s=servo3S1; s>=servo3S2; s --) {servo3.write(s);
  delay(15);} }
     if (servo3S1<servo3S2){
  for (int s=servo3S1; s<=servo3S2; s ++) {servo3.write(s);
  delay(15);} }

     if (servo4S1==servo4S2){}
     if (servo4S1>servo4S2){
  for (int s=servo4S1; s>=servo4S2; s --) {servo4.write(s);
  delay(15);} }
     if (servo4S1<servo4S2){
  for (int s=servo4S1; s<=servo4S2; s ++) {servo4.write(s);
  delay(15);} }

     if (servo5S1==servo5S2){}
     if (servo5S1>servo5S2){
  for (int s=servo5S1; s>=servo5S2; s --) {servo5.write(s);
  delay(15);} }
     if (servo5S1<servo5S2){
  for (int s=servo5S1; s<=servo5S2; s ++) {servo5.write(s);
  delay(15);} }

     if (servo6S1==servo6S2){}
     if (servo6S1>servo6S2){
  for (int s=servo6S1; s>=servo6S2; s --) {servo6.write(s);
  delay(15);} }
     if (servo6S1<servo6S2){
  for (int s=servo6S1; s<=servo6S2; s ++) {servo6.write(s);
  delay(15);} }
                   }
                        }
