// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 2; 
int servoPin2 = 3; 
int servoPin3 = 4; 
int servoPin4 = 5; 
int servoPin5 = 6; 
int servoPin6 = 7; 
// Create a servo object 
Servo Servo1; 
Servo Servo2; 
Servo Servo3; 
Servo Servo4; 
Servo Servo5; 
Servo Servo6;
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
   Servo3.attach(servoPin3); 
   Servo4.attach(servoPin4); 
   Servo5.attach(servoPin5); 
   Servo6.attach(servoPin6); 
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(45); 
   Servo2.write(60); 
   Servo3.write(90);
   Servo4.write(45); 
   Servo5.write(45); 
   Servo6.write(45);
   delay(1000); 
   Servo1.write(0); 
   Servo2.write(70);
   Servo4.write(90); 
   Servo5.write(35); 
   //Servo3.write(120);
   // Make servo go to 90 degrees 
   //Servo1.write(0); 
   //delay(1000); 
   // Make servo go to 180 degrees 
  // Servo1.write(180); 
   delay(1000); 
}
