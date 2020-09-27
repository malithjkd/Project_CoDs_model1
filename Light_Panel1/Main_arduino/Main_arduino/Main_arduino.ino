#include <FastLED.h>

#define NUM_STRIPS 10
#define NUM_LEDS 106
#define CLOCK_PIN 13

CRGB leds[NUM_STRIPS][NUM_LEDS];
int i = 0;
int j = 0;
int k = 0;
int l = 0;

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
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
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
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], NUM_LEDS);  // Process 4
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  // process 4
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  // process 4
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  // process 4
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  // process 11
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);  // process 6 // process 7
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);  // process 5 // process 11
    FastLED.addLeds<WS2812B, 10, RGB>(leds[8], NUM_LEDS); // process 6 // process 7
    FastLED.addLeds<WS2812B, 11, RGB>(leds[9], NUM_LEDS); // process 6 // process 7

}

void loop() {

    // Process 1----------------------------
    for(i=0;i<37;i++)
    {
        leds[0][i] = CRGB(110,125,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);
        leds[0][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);  
    }
    leds[0][36] = CRGB(0,0,0);  // Green,RED,BLUE
    FastLED.show();
    delay(10);  
    

    // Process 2----------------------------
    digitalWrite(relay1, LOW);
    delay(relay_delay);
    digitalWrite(relay1, HIGH);
    //delay(relay_delay);
    
    
    // Process 3----------------------------
    digitalWrite(relay2, LOW);
    delay(relay_delay);
    digitalWrite(relay2, HIGH);
    //delay(relay_delay);
    
    
    // Process 4----------------------------
    for(i=0;i<5;i++)
    {
        leds[1][i] = CRGB(75,214,6);  // Green,RED,BLUE
        leds[2][i] = CRGB(75,214,6);  // Green,RED,BLUE
        FastLED.show();
        delay(100);
        
        leds[1][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[2][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(100);   
    }
    delay(30);
    leds[1][4] = CRGB(0,0,0);  // 
    leds[2][4] = CRGB(0,0,0);  // we need to add the other 2 lights to hear before this stop
    FastLED.show();
    delay(10);  
    
    for(i=0;i<7;i++)
    {
        leds[3][i] = CRGB(75,214,6);  // Green,RED,BLUE
        FastLED.show();
        delay(100);
        
        leds[3][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(100);   
    }
    delay(100);
    leds[4][1] = CRGB(75,214,6);  // Green,RED,BLUE
    delay(200);
    leds[4][1] = CRGB(0,0,0);  // Green,RED,BLUE
    leds[3][6] = CRGB(0,0,0);  // Green,RED,BLUE
    FastLED.show();
    delay(10);
    
    // end of process 4
    
    // Process 5----------------------------
    j=7;
    k=68;
    l=0;
    for(i=5;i<76;i++)
    {
        leds[1][i] = CRGB(75,214,6);  // Green,RED,BLUE // 72 led
        leds[3][j] = CRGB(75,214,6);    // 75 leds
        leds[4][k] = CRGB(75,214,6);
        leds[7][l] = CRGB(75,214,6);
        FastLED.show();
        delay(20);
        leds[1][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[3][j-1] = CRGB(0,0,0);
        leds[4][k+1] = CRGB(0,0,0);
        leds[7][l-1] = CRGB(0,0,0);
        FastLED.show();
        delay(20);
        j++;
        k--;
        l++;
    }
    
    

    // Process 6----------------------------
    for(i=0;i<5;i++)
    {
        leds[6][i] = CRGB(10,99,97);  // Green,RED,BLUE
        leds[8][i] = CRGB(10,99,97);  // Green,RED,BLUE
        leds[9][i] = CRGB(10,99,97);  // Green,RED,BLUE
        FastLED.show();
        delay(50);
        leds[6][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[8][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        leds[9][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);  
    }

    // Process 7----------------------------round tank

    // Process 11----------------------------
    for(i=0;i<25;i++)
    {
        leds[5][i] = CRGB(0,100,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);
        leds[5][i-1] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(10);  
    }
    
 
    // Process none
    digitalWrite(relay3, LOW);
    delay(relay_delay);
    digitalWrite(relay3, HIGH);
    delay(relay_delay);
    digitalWrite(relay4, LOW);
    delay(relay_delay);
    digitalWrite(relay4, HIGH);
    delay(relay_delay);
}
    
