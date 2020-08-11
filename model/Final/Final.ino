/*
model final: driving all the systems
Device: 6 wire stepper and L298
      : Relay module
      : single bulbs

Malithjkd 599132
01.08.2020

0723434780
chathu1991
*/


#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

int process12 = 52;        // 
int process09 = 48;        // 
int process10 = 49;        // 
int process15 = 53;        // 
int process03 = 44;        // 

int GeneralLights = 45;    // GeneralLights
int process07 = 41;        // process07; Round tank settelment tank
int process05 = 37;        // Oxidation Tank
int BlueLight = 33;        // BlueLight


void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("\n");  
  Serial.println("Motor running...");
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GeneralLights, OUTPUT);
  pinMode(process07, OUTPUT);
  pinMode(process05, OUTPUT);
  pinMode(BlueLight, OUTPUT);
  
  pinMode(process12, OUTPUT);
  pinMode(process09, OUTPUT);
  pinMode(process15, OUTPUT);
  pinMode(process10, OUTPUT);
  pinMode(process03, OUTPUT);

  //Starting sequance
  
  digitalWrite(process12, LOW);
  digitalWrite(process09, LOW);
  digitalWrite(process10, LOW);
  digitalWrite(process15, LOW);
  digitalWrite(process03, LOW);
  
  digitalWrite(GeneralLights, HIGH);
  digitalWrite(process07, HIGH); 
  digitalWrite(process05, HIGH);
  digitalWrite(BlueLight, HIGH);

  delay(5000);
  digitalWrite(BlueLight, LOW);
  delay(3000);
  digitalWrite(GeneralLights, HIGH);
  delay(1000);
  digitalWrite(GeneralLights, LOW);
  delay(3000);
  digitalWrite(GeneralLights, HIGH);
  delay(1000);
  digitalWrite(process03, HIGH);
  delay(3000);
  digitalWrite(process03, LOW);
  delay(1000);
  digitalWrite(process05, LOW);
  delay(3000);
  digitalWrite(process05, HIGH);
  delay(1000);
  digitalWrite(process07, LOW);
  delay(3000);
  digitalWrite(process07, HIGH);
  delay(1000);
  digitalWrite(process09, HIGH);
  delay(3000);
  digitalWrite(process09, LOW);
  delay(1000);
  digitalWrite(process10, HIGH);
  delay(3000);
  digitalWrite(process10, LOW);
  delay(1000);
  digitalWrite(process12, HIGH);
  delay(3000);
  digitalWrite(process12, LOW);
  delay(1000);
  digitalWrite(process15, HIGH);
  delay(3000);
  digitalWrite(process15, LOW);
  
  delay(5000);
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(800);
  
}
