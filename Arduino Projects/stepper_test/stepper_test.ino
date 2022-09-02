#include <AccelStepper.h>
#include<Servo.h>
Servo Myservo;
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin1 8
#define stepPin1 9
#define dirPin2 5
#define stepPin2 6
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  // Set the maximum speed and acceleration:
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(500);
  stepper2.setMaxSpeed(500);
  stepper2.setAcceleration(500);
  Myservo.attach(11);
}

void loop() {
  // Set the target position:
  Myservo.write(0);
  stepper1.moveTo(-700);
  // Run to target position with set speed and acceleration/deceleration:
  stepper1.runToPosition();

 // delay(1000);

  // Move back to zero:
  //stepper2.moveTo(2000);
  //stepper2.runToPosition();
  delay(1000);
  Myservo.write(60);
  delay(1000);
//     Move back to zero:
  //stepper2.moveTo(000);
  //stepper2.runToPosition();
  stepper1.moveTo(00);
  // Run to target position with set speed and acceleration/deceleration:
  stepper1.runToPosition();
  delay(1000);
  //stepper2.moveTo(2000);
  //stepper2.runToPosition();
  delay(1000);
  Myservo.write(0);
  delay(1000);
  //stepper2.moveTo(000);
  //stepper2.runToPosition();
  delay(1000);
  



}
