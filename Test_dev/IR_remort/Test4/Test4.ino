/*
  IR remort test4
  Using IRremort.h calculating remote keys
  Malithjkd
  08.06.2020
*/

// define hedders 
#include<IRremote.h>

// remort keys
#define first_key 41565
#define first_key_ex 9755

#define second_key 25245
#define second_key_ex 7611

#define thired_key 57885
#define forth_key 8925
#define fifth_key 19227
#define sixth_key 19899
#define seventh_key 49467
#define eighth_key 60891
#define nineth_key 48511
#define tenth_key 26775
#define eleventh_key 39015
#define twelveth_key 45135
#define therteenth_key 78703
#define foreteenth_key 58359
#define fiftheeth_key 31365
#define sixteenthn_key 25979
#define seventeenth_key 14535
#define eighteenth_key 23205
#define nineteenth_key 65015
#define twentieth_key 19125
#define twentyone_key 21165

// Input pins
int receiver_pin = 53;

// Output pins
int LED_13 = 13;  // indication
int Relay_1 = 52;
int Relay_2 = 50;
int Relay_3 = 48;
int Relay_4 = 46;
int Relay_5 = 44;
int Relay_6 = 42;
int Relay_7 = 40;
int Relay_8 = 38;

// veribles
int statusPower = 0;
int statusMode = 0;
int statusProcessStep = 0;

// functions for IRremote
IRrecv receiver(receiver_pin);
decode_results output;

void setup(){
  Serial.begin(9600);
  receiver.enableIRIn();

  pinMode(13, OUTPUT);
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  pinMode(Relay_5, OUTPUT);
  pinMode(Relay_6, OUTPUT);
  pinMode(Relay_7, OUTPUT);
  pinMode(Relay_8, OUTPUT);

  digitalWrite(Relay_1,HIGH);
  digitalWrite(Relay_2,HIGH);
  digitalWrite(Relay_3,HIGH);
  digitalWrite(Relay_4,HIGH);
  digitalWrite(Relay_5,HIGH);
  digitalWrite(Relay_6,HIGH);
  digitalWrite(Relay_7,HIGH);
  digitalWrite(Relay_8,HIGH);

  digitalWrite(13,HIGH);
}

void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
      case first_key:
        Serial.println("Power off button");
        if (digitalRead(13) == 1){
          digitalWrite(13,LOW);
          Serial.println("System status : Off");
        }else {
          digitalWrite(13,HIGH);
          Serial.println("System status : ON");
        }
      break;
      case first_key_ex:
        Serial.println("Power off button");
        if (digitalRead(13) == 1){
          digitalWrite(13,LOW);
          Serial.println("System status : Off");
        }else {
          digitalWrite(13,HIGH);
          Serial.println("System status : ON");
        }
      break;
      
      case second_key:
        Serial.println("Auto mode");
        statusMode = 0;
      break;
      case second_key_ex:
        Serial.println("Auto mode");
        statusMode = 0;
      break;

      case thired_key:
        Serial.println("Manual mode");
      break;
      
      case forth_key:
        Serial.println("Go previous step <<");
      break;
      
      case fifth_key:
        Serial.println("Pause || ");
      break;
      
      case sixth_key:
        Serial.println("Go next step >>");
      break;
      
      case seventh_key:
        Serial.println("Process step 1 : Bad water input line");
      break;
      
      case eighth_key:
        Serial.println("Process step 2 : Bad water collecting");
      break;
      
      case nineth_key:
        Serial.println("Process step 3 : Grit classifier area");
      break;
      
      case tenth_key:
        Serial.println("Process step 4 : Pumping bad water to oxidation tank");
      break;
      
      case eleventh_key:
        Serial.println("Process step 5 : Oxidation ditch");
      break;
      
      case twelveth_key:
        Serial.println("Process step 6 : Pumping bad water to sedimentation tank");
      break;
      
      case therteenth_key:
        Serial.println("Process step 7 : Sedimentation tanks");
      break;
      
      case foreteenth_key:
        Serial.println("Process step 8 : Pumping sedimented water to disinfection building");
      break;
      
      case fiftheeth_key:
        Serial.println("Process step 9 : Disinfection building");
      break;
      
      case sixteenthn_key:
        Serial.println("Process step 10 : Clean water out");
      break;
      
      case seventeenth_key:
        Serial.println("Process step 11 : Slugffrom tanks to slug pump building");
      break;
      
      case eighteenth_key:
        Serial.println("Process step 12 : Slug pump building");
      break;
      case nineteenth_key:
        Serial.println("Process step 13 : Pump water slug pump building to oxidation ditch");
      break;
      case twentieth_key:
        Serial.println("Process step 14 : Pump slug to slug tratment building");
      break;
      case twentyone_key:
        Serial.println("Process step 15 : Slug tratment building");
      break;
    } //end switch case

    Serial.println(value);
    receiver.resume();
    delay(100);
  }   // end if
}
   
