// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
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
int servoPin12= 13; 
int startup = 0;
int pos;
// Create a servo object 
Servo Servo1; 
Servo Servo2; 
Servo Servo3; 
Servo Servo4; 
Servo Servo5; 
Servo Servo6;
Servo Servo7; 
Servo Servo8; 
Servo Servo9;
Servo Servo10; 
Servo Servo11; 
Servo Servo12;
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
   Servo3.attach(servoPin3); 
   Servo4.attach(servoPin4); 
   Servo5.attach(servoPin5); 
   Servo6.attach(servoPin6); 
   Servo7.attach(servoPin7); 
   Servo8.attach(servoPin8); 
   Servo9.attach(servoPin9); 
   Servo10.attach(servoPin10); 
   Servo11.attach(servoPin11); 
   Servo12.attach(servoPin12); 
}
void loop(){ 

  if(startup == 0)
  {
    Servo1.write(45);
    Servo2.write(45);
    Servo3.write(45);
    Servo7.write(60);
    Servo8.write(45);
    Servo9.write(45);
    //Serial.print("startup");
    startup++;
  }
  // Servo8.write(45);        
  // Servo9.write(45);        
   /*for (pos = 45; pos >= 10; pos--) {// Start at 45 for LegA partA and move to 10
      // in steps of 1 degree
      Servo1.write(pos);              
      delay(25);                      
    } */
   Servo2.write(45);  
   for (pos = 60; pos >= 20; pos--) {
     // in steps of 1 degree
     Servo7.write(pos);              
     delay(25);                      
   } 
   //Move all back together///////////////////////////////////////////////////////////////////////////////
   /*for (pos = 10; pos <= 45; pos++) {// Strat at 10 for LegA partS amd move to 45
      // in steps of 1 degree
      Servo1.write(pos);             
      delay(25);                       
  } */
    for (pos = 20; pos <= 60; pos++) {
      // in steps of 1 degree
      Servo7.write(pos);             
      delay(25);                       
  } 
  Servo2.write(70);   
 
}
