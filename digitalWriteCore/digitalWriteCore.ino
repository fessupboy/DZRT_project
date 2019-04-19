int val = 0; 
int val2 = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Begen listening on port 9600 for serial
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  val = digitalRead(12);   // read the input pin
  val2 = digitalRead(11); 
  if(Serial.available() > 0) // Read from serial port
    {
      char ReaderFromNode; // Store current character
      ReaderFromNode = (char) Serial.read();
      convertToState(ReaderFromNode); // Convert character to state  
    }
  delay(1000); 
}

void convertToState(char chr) {
//  int sensorValue = analogRead(A1);
//  int sensorValue2 = analogRead(A1);
   if(chr=='w'){ 
    digitalWrite(12, HIGH);
    Serial.print("Digital Value w = ");
    Serial.println(val);
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue);
  }
  if(chr=='t'){
    digitalWrite(12, LOW);
    Serial.print("Digital Value t = ");
    Serial.println(val);
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue);
  }

  if(chr=='z'){ 
    digitalWrite(11, HIGH);
    Serial.print("Digital Value z = ");
    Serial.println(val2);
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue2);
  }

  if(chr=='x'){
    digitalWrite(11, LOW);
    Serial.print("Digital Value x = ");
    Serial.println(val2);
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue2);
  }


  if(chr=='q'){
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    Serial.print("Digital Value q = ");
    Serial.println(val);
//    Serial.print("Analog Value = ");
//    Serial.println(sensorValue2);
  }
}
