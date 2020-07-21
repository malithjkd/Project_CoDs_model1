/*
model final: driving all the systems
Device: 6 wire stepper and L298
      : Relay module
      : single bulbs
Malithjkd
21.07.2020
*/

#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

int Relay_module_input_1 = 52;
int Relay_module_input_2 = 50;
int Relay_module_input_3 = 48;
int Relay_module_input_4 = 46;





void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("\n");  
  Serial.println("Motor running...");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Relay_module_input_1, OUTPUT);
  pinMode(Relay_module_input_2, OUTPUT);
  pinMode(Relay_module_input_3, OUTPUT);
  pinMode(Relay_module_input_4, OUTPUT);
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(1000);
}
