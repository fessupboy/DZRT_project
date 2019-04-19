#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;

// define two Tasks for DigitalRead & AnalogRead
//void TaskDigitalRead( void *pvParameters );
void LEDGreen( void *pvParameters );
void LEDRed( void *pvParameters );
void HoldState( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

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
    LEDGreen
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

     xTaskCreate(
    LEDRed
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

//     xTaskCreate(
//    HoldState
//    ,  (const portCHAR *) "AnalogRead"
//    ,  128  // Stack size
//    ,  NULL
//    ,  1  // Priority
//    ,  NULL );


  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void LEDGreen( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(29, INPUT);
    pinMode(10, OUTPUT);
    // read the input on analog pin 0:
    int sensorValue = digitalRead(29);
    Serial.println("LEDGreen");
    Serial.print("Digital Value = ");
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
          Serial.println("Green LED Write");
        }
          digitalWrite(10, HIGH);
          delay(1000);
          digitalWrite(10, LOW);
          delay(1000);
          digitalWrite(10, HIGH);
          delay(1000);
          digitalWrite(10, LOW);
          delay(1000);
          digitalWrite(10, HIGH);
          delay(1000);
          digitalWrite(10, LOW);
          delay(1000);
          digitalWrite(10, HIGH);
          delay(1000);
          digitalWrite(10, LOW);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}


void LEDRed( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;)
  {
    pinMode(11, OUTPUT);
    pinMode(25, INPUT);
    // read the input on analog pin 0:
    int sensorValue2 = digitalRead(25);
    Serial.println("LEDGreen");
    Serial.print("Digital Value 2 = ");
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
          Serial.println("Red LED Write");
        }
          digitalWrite(11, HIGH);
          delay(1000);
          digitalWrite(11, LOW);
          delay(1000);
          digitalWrite(11, HIGH);
          delay(1000);
          digitalWrite(11, LOW);
          delay(1000);
          digitalWrite(11, HIGH);
          delay(1000);
          digitalWrite(11, LOW);
          delay(1000);
          digitalWrite(11, HIGH);
          delay(1000);
          digitalWrite(11, LOW);
        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }
    }
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
}



//void HoldState( void *pvParameters __attribute__((unused)) )  // This is a Task.
//{
//  for (;;)
//  {
//    pinMode(10, OUTPUT);
//    pinMode(11, OUTPUT);
//    // read the input on analog pin 0:
//    int sensorValue = analogRead(A15);
//    Serial.println("Hold State");
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue);
//
//    // See if we can obtain or "Take" the Serial Semaphore.
//    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
//    if(sensorValue > 400) {
//      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
//      {
//        // We were able to obtain or "Take" the semaphore and can now access the shared resource.
//        // We want to have the Serial Port for us alone, as it takes some time to print,
//        // so we don't want it getting stolen during the middle of a conversion.
//        // print out the value you read:
//          Serial.println("Hold State Write");
//        }
//          digitalWrite(11, LOW);
//          digitalWrite(10, LOW);
//        xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
//      }
//    }
//    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability  
//}
