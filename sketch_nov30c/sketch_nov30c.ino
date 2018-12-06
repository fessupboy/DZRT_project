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
int servoPin12 = 13;
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
    Servo1.write(35);
    Servo2.write(45);
    Servo3.write(0);
    
    Servo4.write(65);
    Servo5.write(45);
    Servo6.write(90);

    Servo7.write(75);
    Servo8.write(45);
    Servo9.write(0);

    Servo10.write(15);
    Servo11.write(45);
    Servo12.write(90);
    delay(5000); 

    
    startup++;
  }
  
   //Leg A
   Servo1.write(30); 
   Servo2.write(75); 
   Servo3.write(75);
   //Leg B
   Servo4.write(60); 
   Servo5.write(15); 
   Servo6.write(15);
   //Leg C
   Servo7.write(85); 
   Servo8.write(75); 
   Servo9.write(75);
   //Leg D
   Servo10.write(5); 
   Servo11.write(15); 
   Servo12.write(15);
   // Make servo go to 90 degrees 
   //Servo1.write(0); 
   delay(1000); 
   // Make servo go to 180 degrees 
  // Servo1.write(180); 
   //delay(1000); 
   //Leg A
   Servo1.write(30); 
   Servo2.write(55); 
   Servo3.write(55);
   //Leg B
   Servo4.write(60); 
   Servo5.write(35); 
   Servo6.write(35);
   //Leg C
   Servo7.write(85); 
   Servo8.write(55); 
   Servo9.write(55);
   //Leg D
   Servo10.write(5); 
   Servo11.write(35); 
   Servo12.write(35);
   delay(1000); 
}
