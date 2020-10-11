/*
 * 05.10.2020
 * malithjkd
 * 
 * Process floor lightpanel project for water board Kandy - Wast water treatemtne plant
 * 
 * process 1 - incomming from MC
 * process 2 - incomming flow meater
 * process 3 - piliminary process building
 * process 4 - slug line to oxidation ditch
 * process 5 - Oxidation ditch
 * process 6 - sewge line to sedimentation tand
 * process 7 - Sedimantation tand(round tank)
 * process 8 - Trated water to disinfection tank
 * process 9 - Disinfection Building
 * process 10 - Treated Effluent Line
 * process 11 - slug line from sedimentation line to slug pump blower builing
 * process 12 - slug pump building
 * process 13 - retuen sulg line to oxidation ditch
 * process 14 - exess slug line to slug tratment building 
 * process 15 - slug treatment buiding
 * 
 */



#include <Wire.h>
#include <FastLED.h>

#define NUM_STRIPS 8 //no of led strips
#define NUM_LEDS 106
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_STRIPS][NUM_LEDS];
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int reset = 0;

int slaveReady = 53;
int x = 0;

int process6();
int process7();
int process8();
int process9();
int process10();  // good water out from the pump room
int process11();  // slug collection from sedimentation(round tank) to bulding


void setup() {

    pinMode(slaveReady, OUTPUT);
    Wire.begin(9); 
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);

    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // precess 6 & process7 *
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // Process 1 *
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 8 *
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 9 *
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 14 *
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // process 8 *
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);  // pricess 13 *
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);  // ariation line 1 15 * 
    FastLED.addLeds<WS2812B, 10, RGB>(leds[8], NUM_LEDS);  // **need to be tested
    FastLED.addLeds<WS2812B, 11, RGB>(leds[9], NUM_LEDS);  // **need to be tested
    FastLED.addLeds<WS2812B, 12, RGB>(leds[10], NUM_LEDS);  // **need to be tested
    FastLED.addLeds<WS2812B, 13, RGB>(leds[11], NUM_LEDS);  // **need to be tested
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() 
{
    process6();
    process7();
    process8();
    process9();
    process10();  // good water out from the pump room
    process11(); 
    process13(); 
    process14();
    process15(); 
    /*
    if(x == 0)
    {
        digitalWrite(slaveReady, LOW);            // slave is busy
        reset = 0;
        digitalWrite(slaveReady, HIGH);
        delay(30);
    }else if(x ==1)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 1");
        if(reset == 0)
        {
            process6();
            reset = 1;
        }
        digitalWrite(slaveReady, HIGH);
        delay(30);
    }else if(x == 2)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 2");
        if(reset == 0)
        {
            process7();
            reset = 1;
        }
        Serial.println("process 7 ends");
        digitalWrite(slaveReady, HIGH);
        delay(30);
    }else if(x == 3)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 3");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process8();  
        }
        digitalWrite(slaveReady, HIGH);
        delay(30);
    }else if(x == 4)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 4");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process9();
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 5)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 5");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process10();      
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 6)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 6");
        Serial.println(x);
        delay(1000);
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 7)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 7");
        Serial.println(x);
        delay(6000);
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }

    */
    

}   //end of loop


//process functions

int process6()
{
  if(reset == 0){
    // swiching on 
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(10,99,97);  // Green,RED,BLUE
        FastLED.show();
        delay(70);  
    }
    // swiching off
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(70);  
    }   // end of for loop 
  }   // end of if
}   // end of function 

int process7()
{
    for(i=20;i<49;i++)
    {
        k=i;
        leds[0][k] = CRGB(10,10,100);
        FastLED.show();
        delay(15);

        l = i+7;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
            
        leds[0][k] = CRGB(10,10,100);
        FastLED.show();
        delay(15);
      
        l = i+14;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
            
        leds[0][k] = CRGB(10,10,100);
        FastLED.show();
        delay(15);
      
        l = i+22;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
        leds[0][k] = CRGB(10,10,100);
        FastLED.show();
        delay(15);
               //off
        leds[0][i-1] = CRGB(0,0,0);
        FastLED.show();
        delay(15);
        l = i+6;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
        leds[0][k] = CRGB(0,0,0);
        FastLED.show();
        delay(15);
        l = i+13;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
        leds[0][k] = CRGB(0,0,0);
        FastLED.show();
        delay(15);
            
        l = i+21;
        if(l<49)
        {
            k=l;
        }else
        {
            k=l-29;  
        }
        leds[0][k] = CRGB(0,0,0);
        FastLED.show();
        delay(15);
    }
    
    leds[0][48] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[0][26] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[0][33] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[0][41] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
}

//prcess 8

int process8()
{
    j=0;
    leds[2][7] = CRGB(10,10,100);  // Green,RED,BLUE
    leds[5][3] = CRGB(10,10,100);
    leds[5][4] = CRGB(10,10,100);
    for(i=12;i>0;i--)
    {
        
        leds[2][i] = CRGB(10,10,100);  // Green,RED,BLUE
        leds[5][j] = CRGB(10,10,100);  // Green,RED,BLUE
        if(j==9)
        {
            leds[1][0] = CRGB(10,10,100);  // Green,RED,BLUE
        }else if(j==10)
        {
           leds[2][0] = CRGB(10,10,100);
        }
        
        FastLED.show();
        delay(45);

        leds[2][i+1] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[5][j-1] = CRGB(0,0,0);  // Green,RED,BLUE
        if(j==10)
        {
            leds[1][0] = CRGB(0,0,0);  // Green,RED,BLUE
        }else if(j==11)
        {
            leds[2][0] = CRGB(0,0,0);
        }
        FastLED.show();
        delay(45);
        j++;
    }
    delay(145);
    leds[2][1] = CRGB(0,0,0);
    FastLED.show();
}


int process9()      // pump house clean water
{
    for(i=0;i<12;i++)
    {
        leds[3][i] = CRGB(10,10,100);  // Green,RED,BLUE
        delay(15);

    }
    FastLED.show();
    delay(4000);
    
    for(i=0;i<12;i++)
    {
        leds[3][i] = CRGB(0,0,0);  // Green,RED,BLUE
        delay(10);
    }
    FastLED.show();
  
}


// process 10----------------------------------------------
int process10()
{ 
    for(i=0;i<106;i++)
    {
        leds[1][i] = CRGB(80,25,125);  // Green,RED,BLUE 
        FastLED.show();
        delay(15);

        leds[1][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);
    }
}


// process 11 - slug line from sedimentation line to slug pump blower builing---------
int process11()
{
    for(i=0;i<8;i++)
    {
        leds[8][i] = CRGB(0,100,0);  // Green,RED,BLUE
        FastLED.show();
        delay(500);
        leds[8][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(500);  
    }
    
}

int process13(){
    // process 13 - retuen sulg line to oxidation ditch
    for(i=0;i<31;i++)
    {
        leds[6][i] = CRGB(50,50,50);  // Green,RED,BLUE
        FastLED.show();
        delay(30);
        leds[6][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(30);  
    }
}

int process14(){
    // process 14
    for(i=0;i<69;i++)
    {
        leds[4][i] = CRGB(0,125,0);  // Green,RED,BLUE
        FastLED.show();
        delay(15);

        leds[4][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);
    }

}

int process15() //oxidatio lie
{
    //  Oxidatioon line 15 -1 
    for(i=0;i<8;i++)
    {
        leds[7][i] = CRGB(50,50,50);  // Green,RED,BLUE
        FastLED.show();
        delay(500);
        leds[7][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(500);  
    }
    
}
