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
void setup()
{ 
  FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // precess 6
  FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // Process 7
  FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 8
  FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 8
  FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 14
  FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);  // GRB ordering is typical
}

void loop() {


    // Process 6
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(10,99,97);  // Green,RED,BLUE
        FastLED.show();
        delay(50);  
    }
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);  
    }
    //process 7

    for(j=0;j<1;j++){
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
    
    delay(1500);

    
    //prcess 8
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
    
    delay(1500);




    // process 9
    for(i=0;i<12;i++)
    {
        leds[3][i] = CRGB(10,10,100);  // Green,RED,BLUE
        delay(15);

    }
    FastLED.show();
    delay(3000);
    
    for(i=0;i<12;i++)
    {
        leds[3][i] = CRGB(0,0,0);  // Green,RED,BLUE
        delay(10);
    }
    FastLED.show();
    delay(1500);


  // process 10
    for(i=0;i<106;i++)
    {
        leds[1][i] = CRGB(80,25,125);  // Green,RED,BLUE
        FastLED.show();
        delay(15);

        leds[1][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);
    }

    // process 13
    for(i=0;i<31;i++)
    {
        leds[6][i] = CRGB(50,50,50);  // Green,RED,BLUE
        FastLED.show();
        delay(30);
        leds[6][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(30);  
    }

    // process 14
    for(i=0;i<69;i++)
    {
        leds[4][i] = CRGB(0,125,5);  // Green,RED,BLUE
        FastLED.show();
        delay(15);

        leds[4][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);
    }

}
