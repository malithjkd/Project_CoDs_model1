/*
model final: driving all the systems
Device: 6 wire stepper and L298
      : Relay module
      : single bulbs
Malithjkd
01.08.2020
0723434780
chathu1991
*/


#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

int process12 = 52;
int process09 = 48;
int process10 = 49;
int process15 = 53;
int process03 = 44;

int Relay_module_input_1 = 45;
int Relay_module_input_2 = 41;
int Relay_module_input_3 = 37;
int Relay_module_input_4 = 33;


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
  pinMode(process12, OUTPUT);
  pinMode(process09, OUTPUT);
  pinMode(process15, OUTPUT);
  pinMode(process10, OUTPUT);
  pinMode(process03, OUTPUT);

  digitalWrite(process12, LOW);
  digitalWrite(process09, LOW);
  digitalWrite(process10, LOW);
  digitalWrite(process15, LOW);
  
  digitalWrite(Relay_module_input_1, HIGH);
  digitalWrite(Relay_module_input_2, HIGH); 
  digitalWrite(Relay_module_input_3, HIGH);
  digitalWrite(Relay_module_input_4, HIGH);
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(1000);

  //digitalWrite(Relay_module_input_4, HIGH);
  //delay(1000);
  //digitalWrite(Relay_module_input_4, LOW);
  //delay(1000);
}
