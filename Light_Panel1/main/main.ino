#include <Wire.h>
#include <FastLED.h>

#define NUM_STRIPS 10
#define NUM_LEDS 98
#define CLOCK_PIN 13

// communication
int x = 0;
int slaveReady = 53;

// function decleration
int process1();
int process2();
int process3();
int process4();
int process5();
int process6();
int process7();
int process8();
int process9();

// velriable diclaration for led 
CRGB leds[NUM_STRIPS][NUM_LEDS];
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;
int n = 0;
int p = 0;
int r = 0;
int s = 0;
int t = 0;
int u = 0;
int v = 0;
int w = 0;
int y = 0;
int z = 0;
int a = 0;


int relay1 = 22;
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 28;
int relay6 = 29;
int relay7 = 26;
int relay8 = 27;

int relay_delay = 1500;
int slaveStatus = 0;


void setup() {
    Wire.begin(); 
    Serial.begin(9600);
    
    pinMode(slaveReady, INPUT);
    
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

void loop(){
    
    process1();
    process2();
    process3();
    process4();
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process5();
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process6();
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process7();
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    process8();
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    process9();
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    

}//end of loop

// process declaration


int process1()
{
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
    
}

int process2()
{
    Serial.println("Process 2 starts");
    digitalWrite(relay1, LOW);
    delay(relay_delay);
    digitalWrite(relay1, HIGH);
    Serial.println("Process 2 finished");
}

int process3()
{
    Serial.println("Process 3 starts");
    digitalWrite(relay2, LOW);
    delay(relay_delay);
    digitalWrite(relay2, HIGH);
    //delay(relay_delay);
    Serial.println("Process 3 finished");
  
}
// process 4----------------------------------------------
int process4()
{
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
}

// process 5----------------------------------------------
int process5()
{
    Serial.println("Process 5 starts");
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
    Serial.println("Process 5 ends");
}

// process 6----------------------------------------------
int process6()
{
    Serial.println("process6 starts");
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(1);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2    
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
    slaveStatus = digitalRead(slaveReady);
    if(slaveStatus > 0)
    {
        Serial.println("Process 6 ends at slave stage");
    }
    
    
    return 0;
}   
//  end of process 6

// process 7----------------------------------------------
int process7()
{
    Serial.println("Process 7 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(2);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    for(i=23;i<=52;i++)
    {
        j = i;
        p = i-17;
        v = i-20; 
        leds[6][j] = CRGB(10,10,100);
        leds[8][v] = CRGB(10,10,100);
        leds[9][p] = CRGB(10,10,100);
        FastLED.show();
        delay(10);

        k = i+7;
        w = v+7;
        r = p+7;
        if(k<52)
        {
            l=k;
        }else
        {
            l = k-29;  
        }
        
        if(w<32)
        {
           y=w;
        }else
        {
            y = w-29;  
        }
        if(r<34)
        {
            s = r;
        }else
        {
            s = r-28;
        }
        leds[6][l] = CRGB(10,10,100);
        leds[8][y] = CRGB(10,10,100);
        leds[9][s] = CRGB(10,10,100);
        FastLED.show();
        delay(10);

        k = i+14;
        w = v+14;
        r = p+14;
        if(k<52)
        {
            m=k;
        }else
        {
            m = k-29;  
        }
        if(w<32)
        {
            z=w;
        }else
        {
            z = w-29;  
        }
        if(r<34)
        {
            t=r;
        }else
        {
            t = r-28;
        }
        leds[6][m] = CRGB(10,10,100);
        leds[8][z] = CRGB(10,10,100);
        leds[9][t] = CRGB(10,10,100);
        FastLED.show();
        delay(10);

        k = i+22;
        w = v+22;
        r = p+21;
        if(k<52)
        {
            n=k;
        }else
        {
            n = k-29;  
        }
        if(w<32)
        {
            a=w;
        }else
        {
            a = w-29;  
        }
        if(r<34)
        {
            u = r;
        }else
        {
            u = r -28;  
        }
        leds[6][n] = CRGB(10,10,100);
        leds[8][a] = CRGB(10,10,100);
        leds[9][u] = CRGB(10,10,100);
        FastLED.show();
        delay(10);

        // swiching off
        leds[6][j-1] = CRGB(0,0,0);
        leds[8][v-1] = CRGB(0,0,0);
        leds[9][p-1] = CRGB(0,0,0);
        FastLED.show();
        delay(10);
        leds[6][l-1] = CRGB(0,0,0);
        leds[8][y-1] = CRGB(0,0,0);
        leds[9][s-1] = CRGB(0,0,0);
        FastLED.show();
        delay(10);
        leds[6][m-1] = CRGB(0,0,0);
        leds[8][z-1] = CRGB(0,0,0);
        leds[9][t-1] = CRGB(0,0,0);
        FastLED.show();
        delay(10);
        leds[6][n-1] = CRGB(0,0,0);
        leds[8][a-1] = CRGB(0,0,0);
        leds[9][u-1] = CRGB(0,0,0);
        FastLED.show();
        delay(10);
        
    }
    leds[6][52] = CRGB(0,0,0);
    leds[8][32] = CRGB(0,0,0);
    leds[9][34] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[6][30] = CRGB(0,0,0);
    leds[8][10] = CRGB(0,0,0);
    leds[9][14] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[6][37] = CRGB(0,0,0);
    leds[8][17] = CRGB(0,0,0);
    leds[9][21] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    leds[6][45] = CRGB(0,0,0);
    leds[8][25] = CRGB(0,0,0);
    leds[9][28] = CRGB(0,0,0);
    FastLED.show();
    delay(15);
    
    
    Serial.println("Process 7 stps in master ");
    // waiting for slave to finish the pocess
    for(i=0;i<20;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(500);
    }
} // end of process 7

// process 8------------------------------------------
int process8()
{
    Serial.println("Process 8 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(3);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<20;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(500);
    }
    Serial.println("Process 8 ends");
}

// process 9-------------------------------------------------- pump house for clean water
int process9()
{
    Serial.println("Process 9 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(4);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<90;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(50);
    }
    Serial.println("Process 9 ends");
}


// process 10--------------------------------------------------.

int process10()
{
    Serial.println("Process 10 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(5);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<90;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(50);
    }
    Serial.println("Process 10 ends");
}
