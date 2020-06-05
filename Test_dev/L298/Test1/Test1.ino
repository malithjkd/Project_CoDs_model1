/*
Test1: testing the device
Device: L298
Malithjkd
04.06.2020
*/

//L293D
//Motor A
const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 11;  // Pin  2 of L293

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    //This code  will turn Motor A clockwise for 2 sec.
    analogWrite(motorPin1, 100);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 100);
    analogWrite(motorPin4, 0);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 100);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
    
    //This code will turn Motor B clockwise for 2 sec.
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 100);
    analogWrite(motorPin3, 100);
    analogWrite(motorPin4, 0);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    analogWrite(motorPin1, 100);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);    
    
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  
}


void loop(){
  

}
