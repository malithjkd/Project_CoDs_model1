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

int LED = 13;
int x = 0;

int process6();

void setup() {

    pinMode (LED, OUTPUT);
    Wire.begin(9); 
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);

    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // precess 6
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // Process 7
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 8
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 8
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 14
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // GRB ordering is typical
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);  // GRB ordering is typical
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);  // GRB ordering is typical

    
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  Serial.println(x);
  delay(100);
  if(x==6)
  {
      process6();
      
  }
  if(x==7)
  {
      reset = 0;  
  }
 
}


int process6()
{
  if(reset == 0){
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(10,99,97);  // Green,RED,BLUE
        FastLED.show();
        delay(70);  
    }
    for(i=0;i<19;i++)
    {
        leds[0][i] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(70);  
    }
    reset = 1;
  }
}
