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
    ServoA1.write(45);
    ServoA2.write(45);
    ServoA3.write(45);
    
    ServoB1.write(60);
    ServoB2.write(45);
    ServoB3.write(90);

    ServoC1.write(75);
    ServoC2.write(45);
    ServoC3.write(0);

    ServoD1.write(15);
    ServoD2.write(45);
    ServoD3.write(90);
    delay(1000);  
    startup=1000;
  }

  if(startup ==1)
  {
     
     delay(1000); 
     //delay(1000);
     //Leg A1
   /* for (pos = 55; pos >= 30; pos--)//was 45
    { 
      ServoA1.write(pos); 
      delay(15);                       
    }*/ 
     ServoA1.write(30); 
     ServoA2.write(55); 
     ServoA3.write(55);
     //Leg B
     ServoB1.write(60); 
     ServoB2.write(35); 
     ServoB3.write(25);
     //Leg C
     ServoC1.write(60); 
     ServoC2.write(55); 
     ServoC3.write(55);
     //Leg D
     ServoD1.write(30); 
     ServoD2.write(35); 
     ServoD3.write(25);
     delay(1000);
     startup= 3;
  }


 /* if(startup ==2)
  {
     
     delay(1000); 
     //delay(1000);
     //Leg A1
    for (pos = 5; pos <= 30; pos++)//was 5
    { 
      ServoA1.write(pos); 
      delay(10);                       
    }//now 30
 
     //ServoA1.write(30); 
     //ServoA2.write(55); 
     //ServoA3.write(55);

     //Leg B
     /*ServoB1.write(60); 
     ServoB2.write(35); 
     ServoB3.write(25);
     //Leg C
     ServoC1.write(60); 
     ServoC2.write(55); 
     ServoC3.write(55);
     //Leg D
     ServoD1.write(30); 
     ServoD2.write(35); 
     ServoD3.write(25);
     delay(1000); 
     startup= 3;
  }*/

  
  if(startup == 3)
  {
     //Leg A
     //ServoA1.write(30); 
     //ServoA2.write(55); 
     //ServoA3.write(55);
     //delay(1000); 
     for (pos = 30; pos <= 90; pos++)//A2 was 30
        { 
          ServoD2.write(25);//push down was 35(-10)
          ServoA2.write(pos); 
          delay(10);                       
        }//A2 now 90
     
     //ServoA2.write(90); 
     
     //delay(1000); 

    for (pos = 30; pos >= 5; pos--)//A1 was 30
        { 
          ServoA1.write(pos); 
          delay(10);                       
        }//A1 now 5
     
     //ServoA1.write(5); 
     
     //delay(1000); 

     
     
     for (pos = 90; pos >= 55; pos--)//A2 was 90
      { 
        ServoA2.write(pos); 
        delay(10);                       
      }//A2 now 55
      //ServoA2.write(55);


      
     ServoA3.write(55);
     ServoD2.write(35);//push up was 25(+10)
     //delay(500); 
     //ServoA1.write(30); ///////////Move back
     startup = 4;

  }




  
  if(startup == 4)
  {
     //Leg D
     ServoA2.write(65);//push up waa 55(+10)


     delay(1000); 
     
     for (pos = 35; pos >= 25; pos--)//D1 was 35
     { 
       ServoD2.write(25);
       delay(10);
     } 
     //delay(1000); 


     for (pos = 30; pos <= 55; pos++)//D1 was 30
     { 
      ServoD1.write(pos); 
      delay(10);
     }



     
     //ServoD1.write(55); 
     //delay(1000); 

     for (pos = 25; pos <= 35; pos++)//D2 was 25
     { 
      ServoD2.write(pos); 
      delay(10);
     }
     //ServoD2.write(35);

     //ServoD3.write(25);
     ServoA2.write(55);//back was 65 (-10)
     delay(1000); 
     //ServoD1.write(15); ///////move back
     startup= 5;

  }
  
  int D1pos = 55;
  int B1pos = 60;
  int C1pos = 60;

  //Move back
  if(startup == 5)
  {
    for (pos = 5; pos <= 30; pos++)//A1 was 5
     { 
      if(D1pos != 30)
      {
        D1pos--;
      }
      if(B1pos != 35)
      {
        B1pos--;
      }
      if(C1pos != 85)
      {
        C1pos++;
      }
      ServoA1.write(pos); ///////////Was at 5 (+25)
      ServoD1.write(D1pos);////////was at 55 now 30
      ServoB1.write(B1pos);//////////Was at 60 (-25) now 35
      ServoC1.write(C1pos); ///////////////Was at 60 (+25) now 85
      delay(5); 
     }
     //ServoB1.write(35);//////////Was at 60 (-25)
     //ServoC1.write(85); ///////////////Was at 60 (+25)
     delay(1000); 
     startup = 6;
  }

 

  if(startup == 6)
      {
       //Leg B

       for (pos = 45; pos >= 10; pos--)//B2 was 45 now 10
       { 
        ServoB2.write(pos);  
        delay(10);
        
       }
       //ServoB2.write(10);  
       ServoC2.write(65); //was 55 (+10)
       //delay(1000); 

       for (pos = 35; pos <= 60; pos++)//B1 was 35 now 60
       { 
        ServoB1.write(pos); 
        delay(10);

       }
       //delay(1000);
       for (pos = 10; pos <= 35; pos++)//B2 was 35 now 60
       { 
        ServoB2.write(pos); 
        delay(10);
       }
       //ServoB2.write(35); 
       ServoC2.write(55); //was 65 (-10)
       ServoB3.write(25);
       delay(1000); 
       //ServoB1.write(60);//////////Move back
       startup++;
    }

    if(startup == 7)
  {
     //Leg C
     ServoC2.write(45); //was 55
     ServoB2.write(25);//was 35 (-10)
     //delay(1000);

     for (pos = 45; pos <= 85; pos++)//C2 was 45 now 85
     { 
      ServoC2.write(pos); 
      delay(10);
     }
     //ServoC2.write(85); 
     //delay(1000); 
     for (pos = 85; pos >= 60; pos--)//C1 was 85 now 60
     { 
      ServoC1.write(pos);
      delay(10);
     }
     //delay(1000);
     for (pos = 85; pos >= 55; pos--)//C2 was 85 now 55
     {  
      ServoC2.write(pos);
      delay(10);
     }
     ServoB2.write(35);//was 45 (-10)
     ServoC3.write(55);
     delay(1000); 
     //ServoC1.write(75); ///////////////move back
     startup = 3;
  }
  }

  
 
