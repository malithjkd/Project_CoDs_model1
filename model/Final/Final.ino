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

//  other lights
int process12 = 52;        // 
int process09 = 48;        // 
int process10 = 49;        // 
int process15 = 53;        // 
int process03 = 44;        // 

// relay module
int GeneralLights = 45;    // GeneralLights // 
int process07 = 41;        // process07; Round tank settelment tank
int process05 = 37;        // Oxidation Tank
int BlueLight = 33;        // BlueLight

// for wifi input
int D1 = 5;
int D2 = 4;
int D3 = 3;
int D4 = 2;

int inputFromMain = 0;

int autoMode();

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("model arduino start working...\n");

  //wifi inputs
  pinMode(D4,INPUT);
  pinMode(D3,INPUT);
  pinMode(D2,INPUT);
  pinMode(D1,INPUT);
  
  
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

  // switching off all the outputs 
  digitalWrite(process12, LOW);
  digitalWrite(process09, LOW);
  digitalWrite(process10, LOW);
  digitalWrite(process15, LOW);
  digitalWrite(process03, LOW);
  // switching off all the relays
  digitalWrite(GeneralLights, HIGH); 
  digitalWrite(process07, HIGH); 
  digitalWrite(process05, HIGH);
  digitalWrite(BlueLight, HIGH);
  delay(5000);                      // 

  //Starting sequance 
  digitalWrite(BlueLight, LOW);     // blue light on
  delay(3000);
  
  digitalWrite(GeneralLights, LOW); // general lights on 
  delay(9000);

}

void loop() {
  myStepper.step(1);
  delay(800);

  inputFromMain = digitalRead(D4)*8 + digitalRead(D3)*4 + digitalRead(D2)*2 + digitalRead(D1); 
  Serial.println(inputFromMain);
  
    if(inputFromMain == 0)
    {
        //digitalWrite(BlueLight, HIGH);      // blue light off
        //digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);       // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
        digitalWrite(process15, LOW);       // process 15 off
    }else if(inputFromMain == 1)
    {
        digitalWrite(BlueLight, LOW);       // blue light on
    }else if(inputFromMain == 2)
    {
        digitalWrite(BlueLight, HIGH);       // blue light off
    }else if (inputFromMain == 3)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, HIGH);      // process 3 on
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);      // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
        digitalWrite(process15, LOW);       // process 15 off
    }else if (inputFromMain == 5)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, LOW);       // process 5 relay on
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);       // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
    }else if (inputFromMain == 6)
    {
        digitalWrite(GeneralLights, LOW);  // general lights ON
    }else if (inputFromMain == 7)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, LOW);       // process 7 relay on
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);      // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
        digitalWrite(process15, LOW);       // process 15 off
    }else if (inputFromMain == 8)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off
    
    }else if (inputFromMain == 9)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, HIGH);      // process 9 on
        digitalWrite(process10, LOW);       // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
        
    }else if (inputFromMain == 10)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, HIGH);      // process 10 on
        digitalWrite(process12, LOW);       // process 12 off
        digitalWrite(process15, LOW);       // process 15 off
    }else if (inputFromMain == 12)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);       // process 10 off
        digitalWrite(process12, HIGH);      // process 12 on
        digitalWrite(process15, LOW);       // process 15 off
    }else if (inputFromMain == 15)
    {
        digitalWrite(GeneralLights, HIGH);  // general lights off 
        digitalWrite(process03, LOW);       // process 3 off
        digitalWrite(process05, HIGH);      // process 5 relay off
        digitalWrite(process07, HIGH);      // process 7 relay off
        digitalWrite(process09, LOW);       // process 9 off
        digitalWrite(process10, LOW);       // process 10 off
        digitalWrite(process12, LOW);       // process 12 off
        digitalWrite(process15, HIGH);      // process 15 on
    }
}
