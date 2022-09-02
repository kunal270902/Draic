int motor1pin1 = 4;
int motor1pin2 = 5;
int speed = 0;
int flag = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  if(flag == 1){
    speed += 10;
    analogWrite(motor1pin1, speed);
    delay(1000);

  }
    if(speed == 250){
        flag =0;
        
       
      
      
    }
    if (flag == 0){
      speed -=10;
      analogWrite(motor1pin1, speed);
      delay(1000);
      
        
    }
    if (speed == 0){
      flag = 1;
      
    }
    
  
}
