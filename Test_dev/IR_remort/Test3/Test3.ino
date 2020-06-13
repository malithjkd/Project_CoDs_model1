/*
  IR remort test3
  Using IRremort.h calculating remote keys
  Malithjkd
  08.06.2020
*/


#include<IRremote.h>

#define first_key 41565
#define second_key 25245
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

int receiver_pin = 53;

int first_led_pin = 7;
int second_led_pin = 6;
int third_led_pin = 5;
int fourth_led_pin = 4;

int led[] = {0,0,0,0};

IRrecv receiver(receiver_pin);
decode_results output;

void setup(){
  Serial.begin(9600);
  receiver.enableIRIn();
  
  pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);
  pinMode(third_led_pin, OUTPUT);
  pinMode(fourth_led_pin, OUTPUT);
}

void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
      case first_key:                         // power off
        Serial.println("Power off");
      break;
      case second_key:
        Serial.println("2 nd key");
      break;
      case thired_key:
        Serial.println("3 rd key");
      break;
      case forth_key:
        Serial.println("4 th key");
      break;
      case fifth_key:
        Serial.println("5 th key");
      break;
      case sixth_key:
        Serial.println("6 th key");
      break;
      case seventh_key:
        Serial.println("7 th key");
      break;
      case eighth_key:
        Serial.println("8 th key");
      break;
      case nineth_key:
        Serial.println("9 th key");
      break;
      case tenth_key:
        Serial.println("10 th key");
      break;
      case eleventh_key:
        Serial.println("11 th key");
      break;
      case twelveth_key:
        Serial.println("12 th key");
      break;
      case therteenth_key:
        Serial.println("13 th key");
      break;
      case foreteenth_key:
        Serial.println("14 th key");
      break;
      case fiftheeth_key:
        Serial.println("15 th key");
      break;
      case sixteenthn_key:
        Serial.println("16 th key");
      break;
      case seventeenth_key:
        Serial.println("17 th key");
      break;
      case eighteenth_key:
        Serial.println("18 th key");
      break;
      case nineteenth_key:
        Serial.println("19 th key");
      break;
      case twentieth_key:
        Serial.println("20 th key");
      break;
      case twentyone_key:
        Serial.println("21 th key");
      break;
    } //end switch case

    Serial.println(value);
    receiver.resume();
    delay(100);
  }   // end if
}
   
