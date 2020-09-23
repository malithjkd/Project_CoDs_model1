#include <FastLED.h>

// How many leds in your strip?

#define NUM_STRIPS 2
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
  FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // GRB ordering is typical
}

void loop() { 

  
  for(i=0;i<20;i++)
  {
    leds[0][i] = CRGB(10,99,97);  // Green,RED,BLUE
    FastLED.show();
    delay(50);
    leds[0][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
    FastLED.show();
    delay(10);  
  }
    leds[0][19] = CRGB(0,0,0);  // Green,RED,BLUE
    FastLED.show();
    delay(10);  
    delay(1500);

  //process 7

  for(j=0;j<6;j++){
    for(i=20;i<50;i++)
    {
      k=i;
      leds[0][k] = CRGB(10,10,100);
      FastLED.show();
      delay(15);
      l = i+7;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(10,10,100);
      FastLED.show();
      delay(15);
      l = i+14;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(10,10,100);
      FastLED.show();
      delay(15);
      l = i+22;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(10,10,100);
      FastLED.show();
      delay(15);
     
      
      leds[0][i-1] = CRGB(0,0,0);
      FastLED.show();
      delay(15);
      l = i+6;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(0,0,0);
      FastLED.show();
      delay(15);
      l = i+13;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(0,0,0);
      FastLED.show();
      delay(15);
      l = i+21;
      if(l<50)
      {
        k=l;
      }else
      {
        k=l-30;  
      }
      leds[0][k] = CRGB(10,10,100);
      FastLED.show();
      delay(15);

    }
  }
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

}
