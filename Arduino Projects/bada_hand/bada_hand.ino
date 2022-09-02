#define dirPin1 2
#define stepPin1 3
#define dirPin2 5
#define stepPin2 6
#define dirPin3 7
#define stepPin3 8
#include <AccelStepper.h>
#include<Servo.h>
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);
AccelStepper stepper3 = AccelStepper(motorInterfaceType, stepPin3, dirPin3);
Servo Myservo;
void setup() {
  stepper1.setMaxSpeed(100);
  stepper1.setAcceleration(100);
  stepper2.setMaxSpeed(100);
  stepper2.setAcceleration(100);
  stepper3.setMaxSpeed(100);
  stepper3.setAcceleration(100);
  Myservo.attach(9);
}
void loop()  
{
void stepperrev_1();
delay(1000);
void stepperoriginal_2();
delay(1000);
void stepperoriginal_3();
delay(1000);
void stepper_1();
delay(1000);
void stepper_2();
delay(1000);
void stepper_3();
delay(1000);
servo();
delay(1000);
void stepperrev_3();
delay(1000);
void stepperrev_2();
delay(1000);
void stepperrev_1();
delay(1000);
stepperleave_2();
delay(1000);
stepperleave_3();
delay(1000);
servorev();
delay(1000);
void stepperoriginal_2();
delay(1000);
void stepperoriginal_3();
delay(1000);
}
void stepper_1()                 //stepper 1 forward
{
  stepper1.moveTo(500);
  stepper1.runToPosition();
}  
void stepper_2()                 //stepper 2 forward
{
  stepper2.moveTo(500);
  stepper2.runToPosition();
}
void stepper_3()                 //stepper 3 forward 
{
  stepper3.moveTo(500);
  stepper3.runToPosition();
}
void stepperrev_1()                 //stepper 1 backwards
{
  stepper1.moveTo(00);
  stepper1.runToPosition();
}
void stepperrev_2()             //stepper 2 backwards
{
  stepper2.moveTo(00);
  stepper2.runToPosition();
}
void stepperrev_3()                 //stepper 1 backwards
{
  stepper3.moveTo(00);
  stepper3.runToPosition();
}
void servo()                       //servo close
{
  Myservo.write(90);
}
void servorev()                   //servo open
{
  Myservo.write(0);
}
void stepperleave_2()           //stepper 2 drop
{
  stepper2.moveTo(00);
  stepper2.runToPosition();
}
void stepperleave_3()           //stepper 3 drop 
{
  stepper3.moveTo(00);
  stepper3.runToPosition();
}
void stepperoriginal_2()           //stepper 3 drop 
{
  stepper2.moveTo(00);
  stepper2.runToPosition();
}
void stepperoriginal_3()           //stepper 3 drop 
{
  stepper3.moveTo(00);
  stepper3.runToPosition();
}
