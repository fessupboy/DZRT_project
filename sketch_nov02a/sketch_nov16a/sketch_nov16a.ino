// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 2; 
int servoPin2 = 3; 
int servoPin3 = 4; 
// Create a servo object 
Servo Servo1; 
Servo Servo2; 
Servo Servo3; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
   Servo3.attach(servoPin3); 
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(45); 
   Servo2.write(0); 
   Servo3.write(120);
   delay(1000); 
   
   Servo1.write(90); 
   Servo2.write(120); 
   Servo3.write(60);
   // Make servo go to 90 degrees 
   //Servo1.write(0); 
   delay(1000); 
   // Make servo go to 180 degrees 
  // Servo1.write(180); 
   //delay(1000); 
}
