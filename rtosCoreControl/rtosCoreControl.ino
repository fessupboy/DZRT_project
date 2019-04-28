#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
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

int LED1 = 2;

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

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;

// define two Tasks for DigitalRead & AnalogRead
//void TaskDigitalRead( void *pvParameters );
void Stand( void *pvParameters );
void Wsve( void *pvParameters );
void Left( void *pvParameters );
void Right( void *pvParameters );
void Foward( void *pvParameters );
void Backward( void *pvParameters );


// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
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

  while (!Serial) {
     // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
  // because it is sharing a resource, such as the Serial port.
  // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

    xTaskCreate(
    Stand
    ,  (const portCHAR *) "Stand"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

    xTaskCreate(
    Foward
    ,  (const portCHAR *) "Foward"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

    xTaskCreate(
    Backward
    ,  (const portCHAR *) "Backward"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

    
    xTaskCreate(
    Left
    ,  (const portCHAR *) "Left"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );


    xTaskCreate(
    Wave
    ,  (const portCHAR *) "Wave"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

    xTaskCreate(
    Right
    ,  (const portCHAR *) "Right"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );






  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void Stand( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(22, INPUT);
    //pinMode(10, OUTPUT);
    // read the input on analog pin 0:
    int sensorValue = digitalRead(22);
    //Serial.println("LEDGreen");
    Serial.print("Digital Value Init = ");
    Serial.println(sensorValue);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Green LED Write");
        }
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
//          digitalWrite(2, HIGH);
//          delay(1000);
//          digitalWrite(2, LOW);
//          delay(1000);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}


void Wave( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    //pinMode(11, OUTPUT);
    pinMode(27, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(27);
    Serial.println("Wave");
    Serial.print("Digital Value Wave = ");
    Serial.println(sensorValue2);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue2 == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Red LED Write");
        }
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
          startup = 1;
        }
      
      
        if(startup == 1)
        { 
          ServoC1.write(45);
          delay(1000); 
          ServoA2.write(90);
          delay(1000); 
          ServoA1.write(5);
          delay(1000); 
          startup = 2;
        }
      
        
        if(startup == 2)
        {   
          for(int x = 1; x <= 3; x++) {  
            ServoA3.write(25);
            delay(1000);  
            ServoA3.write(55);
            delay(1000);  
          }
          ServoA1.write(15);
          ServoA2.write(65);
          ServoA3.write(70);
          delay(1000);  
      
          ServoC1.write(90);
          delay(1000); 
          startup = 0;
      
        }
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}

void Left( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(25, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(25);
    Serial.println("Wave");
    Serial.print("Digital Value Left = ");
    Serial.println(sensorValue2);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue2 == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Red LED Write");
        }
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
          startup = 1;
        }
      
        if(startup == 1)
        { 
          ServoD2.write(15);
          delay(1000);
          ServoD3.write(30);
          delay(1000); 
          ServoD1.write(45);
          delay(1000); 
          ServoD2.write(35);
          ServoD3.write(0);
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
          ServoA1.write(45);
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
          ServoC1.write(120);
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
          ServoB1.write(120);
          delay(1000);
          ServoB2.write(15);
          delay(1000);
          startup = 8;
         }
        if(startup == 8)
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
          startup = 0;
        }
         
//        digitalWrite(5, HIGH);
//        delay(1000);
//        digitalWrite(5, LOW);
//        delay(1000);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}




void Right( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(26, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(26);
    Serial.println("Wave");
    Serial.print("Digital Value Right = ");
    Serial.println(sensorValue2);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue2 == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Red LED Write");
        }
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
          
          ServoD1.write(0);
          ServoD2.write(25);
          ServoD3.write(10);
          startup = 0;   
        }
//        digitalWrite(6, HIGH);
//        delay(1000);
//        digitalWrite(6, LOW);
//        delay(1000);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}



void Foward( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(23, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(23);
    Serial.println("Wave");
    Serial.print("Digital Value Right = ");
    Serial.println(sensorValue2);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue2 == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Red LED Write");
        }
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
          startup = 8;          
        }

        if(startup == 8)
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
          startup = 0;          
        }
//        digitalWrite(3, HIGH);
//        delay(1000);
//        digitalWrite(3, LOW);
//        delay(1000);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}


void Backward( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(24, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(24);
    Serial.println("Wave");
    Serial.print("Digital Value Right = ");
    Serial.println(sensorValue2);

    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if(sensorValue2 == 1) {
      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {
        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
        // We want to have the Serial Port for us alone, as it takes some time to print,
        // so we don't want it getting stolen during the middle of a conversion.
        // print out the value you read:
          //Serial.println("Red LED Write");
        }
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
          
          ServoD1.write(0);
          ServoD2.write(25);
          ServoD3.write(10);
        }
//        digitalWrite(4, HIGH);
//        delay(1000);
//        digitalWrite(4, LOW);
//        delay(1000);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}
