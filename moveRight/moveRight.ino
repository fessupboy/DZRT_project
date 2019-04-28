#include <Servo.h> 
int servoPin1 = 2; 
int servoPin2 = 3; 
int servoPin3 = 4; 
int servoPin4 = 5; 
int servoPin5 = 6; 
int servoPin6 = 7;
int servoPin7 = 8; 
int servoPin8 = 9; 
int servoPin9 = 10;
int servoPin10 = 11; 
int servoPin11 = 12; 
int servoPin12 = 13;
int startup = 0;
int pos = 0;
// Create a servo object 
Servo ServoA1; 
Servo ServoA2; 
Servo ServoA3; 
Servo ServoB1; 
Servo ServoB2; 
Servo ServoB3; 
Servo ServoC1; 
Servo ServoC2; 
Servo ServoC3; 
Servo ServoD1; 
Servo ServoD2; 
Servo ServoD3; 
void setup() { 
   // We need to attach the servo to the used pin number 
   ServoA1.attach(servoPin1); 
   ServoA2.attach(servoPin2); 
   ServoA3.attach(servoPin3); 
   ServoB1.attach(servoPin4); 
   ServoB2.attach(servoPin5); 
   ServoB3.attach(servoPin6); 
   ServoC1.attach(servoPin7); 
   ServoC2.attach(servoPin8); 
   ServoC3.attach(servoPin9); 
   ServoD1.attach(servoPin10); 
   ServoD2.attach(servoPin11); 
   ServoD3.attach(servoPin12); 
}
void loop(){ 

  if(startup == 0)
  {   
    ServoA1.write(15);
    ServoA2.write(65);
    ServoA3.write(70);
    
    ServoB1.write(90);
    ServoB2.write(15);
    ServoB3.write(20);

    ServoC1.write(90);
    ServoC2.write(65);
    ServoC3.write(90);

    ServoD1.write(0);
    ServoD2.write(25);
    ServoD3.write(10);
    delay(3000);
    startup = 2;
  }

  if(startup == 2)
  { 
    ServoA2.write(90);
    delay(1000); 
    startup = 3;
  }

  if(startup == 3)
  { 
    ServoA1.write(0);
    delay(1000); 
    startup = 4;
  }
  
  if(startup == 4)
  {
    ServoA2.write(65);
    delay(1000); 
    startup = 5;
  }
  
  if(startup == 5)
  {
    ServoC3.write(60);
    ServoC2.write(85);
    delay(1000);
    ServoC1.write(45);
    startup = 6;
    delay(1000);
  }

  if(startup == 6)
  {
    ServoC2.write(65);
    ServoC3.write(90);
    delay(1000);
    startup = 7;
  }

  if(startup == 7)
  {
    ServoB2.write(0);
    delay(1000);
    ServoB1.write(45);
    delay(1000);
    ServoB2.write(15);
    delay(1000);
    startup = 7;
    
  }

  if(startup == 7)
  {
    ServoA1.write(15);
    ServoA2.write(65);
    ServoA3.write(70);
    
    ServoB1.write(90);
    ServoB2.write(15);
    ServoB3.write(20);

    ServoC1.write(90);
    ServoC2.write(65);
    ServoC3.write(90);

    //ServoD1.write(0);
    ServoD2.write(25);
    ServoD3.write(10);
    
    ServoD1.write(45);
    startup = 0;
  }
  
}
