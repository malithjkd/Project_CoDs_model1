#include <Wire.h>

#include <FastLED.h>

#define NUM_STRIPS 10
#define NUM_LEDS 106
#define CLOCK_PIN 13

int x = 0;
int process6();

CRGB leds[NUM_STRIPS][NUM_LEDS];
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;

int relay1 = 22;
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 28;
int relay6 = 29;
int relay7 = 26;
int relay8 = 27;
int relay_delay = 1500;



void setup() {
    Wire.begin(); 
    Serial.begin(9600);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(relay1, OUTPUT);    // precess 2
    pinMode(relay2, OUTPUT);    // precess 3
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(relay5, OUTPUT);
    pinMode(relay6, OUTPUT);
    pinMode(relay7, OUTPUT);
    pinMode(relay8, OUTPUT);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
    digitalWrite(relay8, HIGH);

    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // precess 1
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // Process 4  // precess 5
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 4  
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 4  // precess 5
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 4  // precess 5
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // process 11
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);                             // process 6  // process 7
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);                // process 5 // process 11
    FastLED.addLeds<WS2812B, 10, RGB>(leds[8], NUM_LEDS);                            // process 6  // process 7
    FastLED.addLeds<WS2812B, 11, RGB>(leds[9], NUM_LEDS);                            // process 6  // process 7

}

void loop() {
    Wire.beginTransmission(9);
    Wire.write(x);
    Serial.println(x);
    Wire.endTransmission();
    
    if(x==6)
    {
        process6(); 
    }

    x++; // Increment x
    if (x > 8)
    { 
        x = 0;
    }
    
    delay(300);
}



int process6()
{
    j=0;
    k=0;
    l=0;
    for(i=0;i<23;i++)
    {
        leds[6][i] = CRGB(10,99,97);  // Green,RED,BLUE
        leds[8][k] = CRGB(10,99,97);  // Green,RED,BLUE
        leds[9][m] = CRGB(10,99,97);  // Green,RED,BLUE
        FastLED.show();
        delay(50); 
        //to limit the no of lights illuminating in the line
        if(j==20)
        {
            j=0;
        }else
        {
            j++;  
        }
        k=j/7;

        if(l==20)
        {
            l=0;
        }else
        {
            l++;  
        }
        m=l/4;
        
    }
    //swiching off
    j=0;
    k=0;
    l=0;
    for(i=0;i<23;i++)
    {
        leds[6][i] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[8][k] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[9][m] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);  
        
        //to limit the no of lights illuminating in the line
        if(j==20)
        {
            j=0;
        }else
        {
            j++;  
        }
        k=j/7;

        if(l==20)
        {
            l=0;
        }else
        {
            l++;  
        }
        m=l/4;
    }
  
}
