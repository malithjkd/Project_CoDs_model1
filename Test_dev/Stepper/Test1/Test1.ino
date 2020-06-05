#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("\n");  
  Serial.println("Motor running...");
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(10);
}
