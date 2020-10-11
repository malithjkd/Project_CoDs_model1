<<<<<<< HEAD
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



=======
/*  Malith JKD
 *  19:35 : 06.10.2020
 *
 *  process 1 - pipe line: sewage line incomming
 *  process 2 - Mesuring building
 *  process 3 - pilimenary treatment building
 *  process 4 - pipe line: pilimenary treatment building to oxidation ditch
 *  process 5 - oxidation ditch
 *  process 6 - pipe line: oxidation ditch to sedimantation tank
 *  process 7 - sedimantation tank
 *  process 8 - pipe line: sedimentation tank to disinfection building
 *  process 9 - disinfection building
 *  process 10 - pipe line: Treated effluent
 *  process 11 - pipe line: sedimentation tank to slug pump building 
 *  process 12 - slug pump building
 *  process 13 - pipe line: slug pump building to oxidation tank
 *  process 14 - pipe line: slug pump building to slug treatment building(red line)
 *  process 15 - slug treatment building
 *  process 16 - pipe line: slug pump building to oxidation ditch(weight line)
 */
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
#include <Wire.h>
#include <FastLED.h>

#define NUM_STRIPS 12 //no of led strips
#define NUM_LEDS 100
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_STRIPS][NUM_LEDS];

int i = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;
int reset = 0;

int slaveReady = 53;
int x = 0;

<<<<<<< HEAD
int process6();
int process7();
int process8();
int process9();
int process10();  // good water out from the pump room
int process11();  // slug collection from sedimentation(round tank) to bulding

=======
// defining functions for 
  
int process6();     //  process 6 - pipe line: oxidation ditch to sedimantation tank
int process7();     //  process 7 - sedimantation tank
int process8();     //  process 8 - pipe line: sedimentation tank to disinfection building
int process9();     //  process 9 - disinfection building
int process10();    //  process 10 - pipe line: Treated effluent
int process11();    //  process 11 - pipe line: sedimentation tank to slug pump building
int process12();    //  process 12 - slug pump building
int process13();    //  process 13 - pipe line: slug pump building to oxidation tank
int process14();    //  process 14 - pipe line: slug pump building to slug treatment building
int process15();    //  process 15 - slug treatment building
int process16();    //  process 16 - pipe line: slug pump building to oxidation ditch(air line)
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f

void setup() {

    pinMode(slaveReady, OUTPUT);
    Wire.begin(9); 
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);

<<<<<<< HEAD
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
=======
    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // process 6 - pipe line: oxidation ditch to sedimantation tank  & process 7 - sedimantation tank 
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // process 10 - pipe line: Treated effluent
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 8 - pipe line: sedimentation tank to disinfection building
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 9 - disinfection building
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 14 - pipe line: slug pump building to slug treatment building (red long line -69)
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // process 8 - pipe line: sedimentation tank to disinfection building(blue line)
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);  // process 13 - pipe line: slug pump building to oxidation tank
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);  // process 16 - pipe line: slug pump building to oxidation ditch(air line)
    FastLED.addLeds<WS2812B, 10, RGB>(leds[8], NUM_LEDS);  // process 11 - pipe line: sedimentation tank to slug pump building
    FastLED.addLeds<WS2812B, 11, RGB>(leds[9], NUM_LEDS);  // **need to be tested
    FastLED.addLeds<WS2812B, 12, RGB>(leds[10], NUM_LEDS);  // process 11 - pipe line: sedimentation tank to slug pump building
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() 
{
<<<<<<< HEAD
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
=======

/*
    process6();   // process 6 - pipe line: oxidation ditch to sedimantation tank
    process7();   // process 7 - sedimantation tank
    process8();   // process 8 - pipe line: sedimentation tank to disinfection building
    process9();   // process 9 - disinfection building
    process10();  // process 10 - pipe line: Treated effluent
    process11();  // process 11 - pipe line: sedimentation tank to slug pump building
    process13();  // process 13 - pipe line: slug pump building to oxidation tank (red line)
    process14();  // process 14 - pipe line: slug pump building to slug treatment building (red long line -69)
    process16();  // process 16 - pipe line: slug pump building to oxidation ditch(air line)
*/



>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
    if(x == 0)
    {
        digitalWrite(slaveReady, LOW);            // slave is busy
        reset = 0;
        Serial.println("reset");
        digitalWrite(slaveReady, HIGH);
        delay(30);
    }else if(x == 1)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 6");
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
        Serial.println("inside process 7");
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
        Serial.println("inside process 8");
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
        Serial.println("inside process 9");
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
        Serial.println("inside process 10");
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
        Serial.println("inside process 11");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process11();      
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 7)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 13");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process13();      
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 8)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 14");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process14();      
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }else if(x == 9)
    {
        digitalWrite(slaveReady, LOW);
        Serial.println("inside process 16");
        Serial.println(x);
        if(reset == 0)
        {
            reset = 1;
            process16();      
        }
        digitalWrite(slaveReady, HIGH);
        delay(10);
    }

<<<<<<< HEAD
    */
    
=======
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f



}   //end of loop

//process functions section

//  process 6 - pipe line: oxidation ditch to sedimantation tank
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
    }   // end of switching off loop 
  }   // end of  reset if
}   // end of function 

//  process 7 - sedimantation tank

int process7()
{
    Serial.println("inside process 7");
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

}// end of function 

//  process 8 - pipe line: sedimentation tank to disinfection building (bulue line)

int process8()
{   
    j = 0;    //    switching on sequance
    for(i=12;i>=1;i--)
    {
          leds[2][i] = CRGB(10,10,100);
          if(j<=8)
          {
              leds[5][j] = CRGB(10,10,100);
          }else if(j == 9)
          {
              leds[1][0] = CRGB(10,10,100);
          }else if(j == 10)
          {
              leds[2][0] = CRGB(10,10,100);
          }
          FastLED.show();
          delay(75);
          j++;
          
          
    }
    delay(800);
    
    j = 0;    // swiching off sequance
    for(i=12;i>=1;i--)
    {
          leds[2][i] = CRGB(0,0,0);
          if(j <= 8)
          {
              leds[5][j] = CRGB(0,0,0);
          }else if(j == 9)
          {
              leds[1][0] = CRGB(0,0,0);
          }else if(j == 10)
          {
              leds[2][0] = CRGB(0,0,0);
          }
          FastLED.show();
          delay(75);
          j++;
    }

    
  
   
}

//  process 9 - disinfection building
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


//  process 10 - pipe line: Treated effluent
int process10()
{ 
    for(i=0;i<100;i++)
    {
        leds[1][i] = CRGB(80,25,125);  // Green,RED,BLUE 
        FastLED.show();
        delay(15);

        leds[1][i-2] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(15);
    }
    leds[1][98] = CRGB(0,0,0);
    leds[1][99] = CRGB(0,0,0);
    leds[1][100] = CRGB(0,0,0);
    FastLED.show();
    delay(10);
} 

<<<<<<< HEAD

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
=======
//  process 11 - pipe line: sedimentation tank to slug pump building 
int process11()
{
    j = 4;
    k = 0;
    l = 8;
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
    
    for(i=3;i>=0;i--)
    {
        leds[8][i] = CRGB(0,100,0);  // Green,RED,BLUE
        leds[8][j] = CRGB(0,100,0);
        leds[10][k] = CRGB(0,100,0);
        m = l/2;
        leds[10][m] = CRGB(0,100,0);
        FastLED.show();
        delay(500);
        j++;
        k++;
        l++;
    }

    j = 4;
    k = 0;
    l = 8;
    for(i=3;i>=0;i--)
    {
        leds[8][i] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[8][j] = CRGB(0,0,0);
        leds[10][k] = CRGB(0,0,0);
        m = l/2;
        leds[10][m] = CRGB(0,0,0);
        FastLED.show();
        delay(500);
        j++;
        k++;
        l++;
    }
}
// end of process 11

<<<<<<< HEAD
int process13(){
    // process 13 - retuen sulg line to oxidation ditch
    for(i=0;i<31;i++)
=======

//  process 13 - pipe line: slug pump building to oxidation tank(red line)
int process13(){
    for(i=0;i<5;i++)
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
    {
        leds[9][i] = CRGB(0,100,0);  // Green,RED,BLUE
        FastLED.show();
        delay(120);
    }
    leds[1][12] = CRGB(0,100,0);  // Green,RED,BLUE
    FastLED.show(); 
    delay(120);
    
    delay(1800);
    
    for(i=0;i<5;i++)
    {
        leds[9][i] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(120);
    }
    leds[1][12] = CRGB(0,0,0);  // Green,RED,BLUE
    FastLED.show(); 
    delay(120);
}
//  

//  process 14 - pipe line: slug pump building to slug treatment building
int process14()
{
    for(i=0;i<69;i++)
    {
<<<<<<< HEAD
        leds[4][i] = CRGB(0,125,0);  // Green,RED,BLUE
=======
        leds[4][i] = CRGB(0,100,0);  // Green,RED,BLUE
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
        FastLED.show();
        delay(15);

        leds[4][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(15);
    }

}

//  process 16 - pipe line: slug pump building to oxidation ditch
int process16()
{
    // swiching on leds
    for(i=0;i<=36;i++)
    {
        j = 0;
        leds[6][i] = CRGB(50,50,50);  // Green,RED,BLUE
        
        if (i == 10)
        {
            leds[4][9] = CRGB(50,50,50);  // Green,RED,BLUE
        } else if (i == 11)
        {
            leds[1][20] = CRGB(50,50,50); 
        } else if(i > 12)
        {
            leds[7][i-12] = CRGB(70,70,70);  // Green,RED,BLUE
        }
        FastLED.show();
        delay(100);      
    }
    j = 0;
    // switching off leds
    for(i=0;i<=36;i++)
    {
        leds[6][i] = CRGB(0,0,0);  // Green,RED,BLUE
        if (i == 10)
        {
            leds[4][9] = CRGB(0,0,0);  // Green,RED,BLUE
        }else if (i == 11)
        {
            leds[1][20] = CRGB(0,0,0); 
        }else if(i > 12)
        {
            leds[7][i-12] = CRGB(0,0,0);  // Green,RED,BLUE
        }
        FastLED.show();
        delay(100);
    }

}
<<<<<<< HEAD

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
=======
//  end of function 16
>>>>>>> 9eb964d761fb7604c98d4d36e871250d1fe8a91f
