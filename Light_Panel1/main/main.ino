/*  Malith JKD
 *  11.10.2020
 *  
 * 	Main takes input from te IR Remote and work accordinly
 * 	Main(arduino)	IR reader LED
 *	49 -------------49
 *  
 * 	Light panel woks with 2 arduinos megas, Main arduino and Slave arduino.
 *  Main arduino Slave arduino communication via I2C using pin no 20 and 21
 *	Main			Slave
 *  20 -------------20
 *	21 -------------21
 * 
 *  Light panel and plant Phyiscal plant model communicate via wifi using pings 31,33,35 and 37.
 *	Main(arduino) 	Wifi(esp8266)
 * 	31 -------------D2
 *  33 -------------D1
 *  35 -------------D3
 *  37 -------------D4
 * 
 *  Main function collectc IR remote signal and derects to led illumination automatic and manual functions.
 * 	inside manual or automat function they calles to indivirual process functions to do the final operatin of the function.
 *  
 *  Indivirual process functions are list in the bellow.
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
 *  process 11 - pipe line: sedimentation tank to slug pump building(red line) 
 *  process 12 - slug pump building
 *  process 13 - pipe line: slug pump building to oxidation tank
 *  process 14 - pipe line: slug pump building to slug treatment building(red line)
 *  process 15 - slug treatment building
 *  process 16 - pipe line: slug pump building to oxidation ditch(air line)
 *
 *	Bulbs are defined is a indivirual veriable using metrix.
 *	Bulbs arreys pins defines in 
 *
 */

#include <Wire.h>
#include <FastLED.h>
#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

// define veriables for led oparetions
#define NUM_STRIPS 10
#define NUM_LEDS 98
#define CLOCK_PIN 13

// Input pins
int receiver_pin = 49;

// communication veriable decleration
int x = 0;
int slaveReady = 53;

// function decleration
int AutoSequance();
int ManualSequance();
int process1();
int process2();
int process3();
int process4();
int process5();
int process6();
int process7();
int process8();
int process9();
int process10();
int process11();
int process12();
int process13();
int process14();
int process15();

// velriable diclaration for led 
CRGB leds[NUM_STRIPS][NUM_LEDS];

// velriable for light diclaration oparation
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

// velriable diclaration for relay functioning
int relay1 = 22;
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 28;
int relay6 = 29;
int relay7 = 26;
int relay8 = 27;

// velriable diclaration slave status
int slaveStatus = 0;

// IR remot output veriable
unsigned int value;

// manua function veriation
int manualOn = 0;
int processNow = 0;

// wifi input veriables;
int D4 = 37;
int D3 = 35;
int D2 = 31;
int D1 = 33;

// functions for IRremote
IRrecv receiver(receiver_pin);
decode_results output;


void setup() {
    Wire.begin(); 				// for I2C communication
    Serial.begin(9600);			// for SerialPrinting
    receiver.enableIRIn();		// for IR reading

    pinMode(slaveReady, INPUT);
    
    pinMode(relay1, OUTPUT);    // precess 2
    pinMode(relay2, OUTPUT);    // precess 3
    pinMode(relay3, OUTPUT);	// precess 12
    pinMode(relay4, OUTPUT);	// precess 15
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

    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], 40);  		// precess 1
    FastLED.addLeds<WS2812B, 3, RGB>(leds[1], 90);  		// Process 4  	// process 5 - oxidation ditch
    FastLED.addLeds<WS2812B, 4, RGB>(leds[2], NUM_LEDS);  	// process 4  
    FastLED.addLeds<WS2812B, 5, RGB>(leds[3], NUM_LEDS);  	// process 4  	// precess 5
    FastLED.addLeds<WS2812B, 6, RGB>(leds[4], NUM_LEDS);  	// process 4  	// precess 5
    FastLED.addLeds<WS2812B, 7, RGB>(leds[5], NUM_LEDS);  	// process 11
    FastLED.addLeds<WS2812B, 8, RGB>(leds[6], NUM_LEDS);    // process 6  	// process 7
    FastLED.addLeds<WS2812B, 9, RGB>(leds[7], NUM_LEDS);    // process 5	// process 13
    FastLED.addLeds<WS2812B, 10, RGB>(leds[8], NUM_LEDS);   // process 6  	// process 7
    FastLED.addLeds<WS2812B, 11, RGB>(leds[9], NUM_LEDS);   // process 6  	// process 7

    pinMode(D4, OUTPUT);    //3
    pinMode(D3, OUTPUT);    //2
    pinMode(D2, OUTPUT);    //1
    pinMode(D1, OUTPUT);    //0

    // making wifi  communication digital outputs to zero
    digitalWrite(D3, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D4, LOW);
}

void loop()
{    
    if (receiver.decode(&output)) 
    {
        value = output.value;
        Serial.println(value);
        if(value == 41565 )
        {
            // auto sequance botton pressed
            manualOn = 0;
            processNow = 0;
            AutoSequance();
        }else if(value == 57885)
        {
            // manual oparation button pressed
            manualOn = 1;
            processNow = 0;
        }else if(value == 8925)   // << button
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                  processNow = processNow -1;
                  ManualSequance();
            }
            
        }else if(value == 49725)  // >> button
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                  processNow = processNow + 1;
                  ManualSequance();
            }    
        }else if(value == 57375)  //  1
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                process1();
            }    
        }else if(value == 43095)  //  2
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                process2();
            }    
        }else if(value == 36975)  //  3
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                process3();
            }    
        }else if(value == 26775)  //  4
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                process4();
            }    
        }else if(value == 39015)  //  5
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process5();
            }    
        }else if(value == 45135)  //  6
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process6();
            }    
        }else if(value == 12495)  //  7
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process7();
            }    
        }else if(value == 6375)  //  8
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process8();
            }    
        }else if(value == 31365)  //  9
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process9();
            }    
        }else if(value == 4335)  //  10
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process10();
            }    
        }else if(value == 14535)  //  11
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process11();
            }    
        }else if(value == 23205)  //  12
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process12();
            }    
        }else if(value == 17085)  //  13
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process13();
            }    
        }else if(value == 19125)  //  14
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process14();
            }    
        }else if(value == 21165)  //  15
        {
            // manual oparation button pressed
            if(manualOn == 1)
            {
                Wire.beginTransmission(9);    // sending value to arduino 2
                Wire.write(0);
                Wire.endTransmission();
                delay(100);
                process15();
            }    
        }
        
        receiver.resume();
        delay(100);
        
    }//end of if function for remote operation
    
}//end of loop

// process declaration

int ManualSequance()
{
    if(processNow == 1 )
        {
            process1();
        }else if(processNow == 2)
        {
            process2();
        }else if(processNow == 3)
        {
            process3();
        }else if(processNow == 4)
        {
            process4();
        }else if(processNow == 5)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process5();
        }else if(processNow == 6)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0); 
            Wire.endTransmission();
            delay(100);
            process6();
        }else if(processNow == 7)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process7();
        }else if(processNow == 8)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process8();
        }else if(processNow == 9)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process9();
        }else if(processNow == 10)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process10();
        }else if(processNow == 11)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process11();
        }else if(processNow == 12)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process12();
        }else if(processNow == 13)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process13();
        }else if(processNow == 14)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process14();
        }else if(processNow == 15)
        {
            Wire.beginTransmission(9);    // sending value to arduino 2
            Wire.write(0);
            Wire.endTransmission();
            delay(100);
            process15();
        }
}


int AutoSequance()
{
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
    delay(500);
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);
    delay(50);
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process7();
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process8();
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process9();
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process10();
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process11();

    process12();

    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process13();

    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(0);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    process14();
    
    process15();

    delay(2000); 
}


int process1()
{
    for(i=0;i<37;i++)
    {
        leds[0][i] = CRGB(110,125,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);  
    }
    for(i=0;i<37;i++)
    {
        leds[0][i] = CRGB(0,0,0);  // Green,RED,BLUE
        FastLED.show();
        delay(50);
    }
}

int process2()
{
    Serial.println("Process 2 starts");
    digitalWrite(relay1, LOW);
    delay(1500);
    digitalWrite(relay1, HIGH);
    Serial.println("Process 2 finished");
}

int process3()
{
    digitalWrite(D4, LOW);  
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, HIGH);
    
    Serial.println("Process 3 starts");
    digitalWrite(relay2, LOW);
    delay(1500);
    digitalWrite(relay2, HIGH);
    //delay(1500);
    Serial.println("Process 3 finished");
  
}
// process 4----------------------------------------------
int process4()
{

    Serial.println("Process 4 starts");
    for(i=0;i<12;i++)
    {
        if(i<10)
        {
            leds[1][i/2] = CRGB(75,214,6);  // Green,RED,BLUE  
        }
        if(i<5)
        {
            leds[2][i] = CRGB(75,214,6);  // Green,RED,BLUE
        } else if (i>=5)
        {
            leds[3][i-5] = CRGB(75,214,6);  // Green,RED,BLUE  
        }
        FastLED.show();
        delay(250);
    }
    delay(500);
    for(i=0;i<12;i++)
    {
        if(i<10)
        {
            leds[1][i/2] = CRGB(0,0,0);  // Green,RED,BLUE  
        }
        if(i<5)
        {
            leds[2][i] = CRGB(0,0,0);  // Green,RED,BLUE
        } else if (i>=5)
        {
            leds[3][i-5] = CRGB(0,0,0);  // Green,RED,BLUE  
        }
        FastLED.show();
        delay(250);
    }
    
    delay(100);
    Serial.println("Process 4 finished");
    
}


// process 5----------------------------------------------
int process5()
{
    Serial.println("Process 5 starts");
    digitalWrite(D4, LOW);  
    digitalWrite(D3, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D1, HIGH);

    Serial.println("Process 16 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(9);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(100);
    
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
    Serial.println("Process 16 ends");
    
    for(i=0;i<=67;i++)
    {
        leds[1][i+5] = CRGB(37,107,3);
        
        j = i+35;
        if(i<32)
        {
            leds[7][j] = CRGB(37,107,3);
            
        }else
        {
            leds[7][j-67] = CRGB(37,107,3);
        }
       
        leds[3][i+7] = CRGB(37,107,3); 
        leds[4][68-i] = CRGB(37,107,3);
        
        FastLED.show();
        delay(25);
    }
    /*
     * To calcluate the values of each and every item I calulate and identyfied sequance of the oparetion.
     * There might be some maths to calcuate this type of things. 
     * Hear we are just calcuate it by trial and error. It takes time, But it works.
     */
    for(i=0;i<=77;i++)
    {
        if(i<=29)
        {
            leds[1][i+42] = CRGB(0,0,0);  
        }else if(i>29)
        {
            leds[1][i-25] = CRGB(0,0,0);
        }

        if(i < 62)
        {
            leds[7][i+5] = CRGB(0,0,0);  
        }
        else if(i >=62)
        {
            leds[7][i-62] = CRGB(0,0,0);
        }
        
        if(i<39)
        {
            leds[3][i+45] = CRGB(0,0,0);
        }else if(i>=39)
        {
            leds[3][i-32] = CRGB(0,0,0);
        }
        if(i<31)
        {
            leds[4][31-i] = CRGB(0,0,0);  
        }else if(i>=31)
        {
            leds[4][99-i] = CRGB(0,0,0);  
        }
        
        
        FastLED.show();
        delay(25);
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

    digitalWrite(D4, LOW);  
    digitalWrite(D3, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, HIGH);
    
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(2);                // sending value to arduino 2
    delay(50);
    Wire.endTransmission();       // sending value to arduino 2  
    delay(50);
    
    for(i=23;i<=52;i++)
    {
        j = i;
        p = i-17;
        v = i-20; 
        leds[6][j] = CRGB(10,10,100);
        leds[8][v] = CRGB(10,10,100);
        leds[9][p] = CRGB(10,10,100);
        FastLED.show();
        delay(20);

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
        delay(20);

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
        delay(20);

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
            u = r - 28;  
        }
        leds[6][n] = CRGB(10,10,100);
        leds[8][a] = CRGB(10,10,100);
        leds[9][u] = CRGB(10,10,100);
        FastLED.show();
        delay(20);

        // swiching off
        leds[6][j-1] = CRGB(0,0,0);
        leds[8][v-1] = CRGB(0,0,0);
        leds[9][p-1] = CRGB(0,0,0);
        FastLED.show();
        delay(20);
        leds[6][l-1] = CRGB(0,0,0);
        leds[8][y-1] = CRGB(0,0,0);
        leds[9][s-1] = CRGB(0,0,0);
        FastLED.show();
        delay(20);
        leds[6][m-1] = CRGB(0,0,0);
        leds[8][z-1] = CRGB(0,0,0);
        leds[9][t-1] = CRGB(0,0,0);
        FastLED.show();
        delay(20);
        leds[6][n-1] = CRGB(0,0,0);
        leds[8][a-1] = CRGB(0,0,0);
        leds[9][u-1] = CRGB(0,0,0);
        FastLED.show();
        delay(20);
        
    }
    leds[6][52] = CRGB(0,0,0);
    leds[8][32] = CRGB(0,0,0);
    leds[9][34] = CRGB(0,0,0);
    FastLED.show();
    delay(20);
    leds[6][30] = CRGB(0,0,0);
    leds[8][10] = CRGB(0,0,0);
    leds[9][14] = CRGB(0,0,0);
    FastLED.show();
    delay(20);
    leds[6][37] = CRGB(0,0,0);
    leds[8][17] = CRGB(0,0,0);
    leds[9][21] = CRGB(0,0,0);
    FastLED.show();
    delay(20);
    leds[6][45] = CRGB(0,0,0);
    leds[8][25] = CRGB(0,0,0);
    leds[9][28] = CRGB(0,0,0);
    FastLED.show();
    delay(20);
    
    Serial.println("Process 7 stps in master ");
    // waiting for slave to finish the pocess
    for(i=0;i<30;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(100);
        
    }
    Serial.println(slaveStatus);
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

    //Sending input to wifi
    digitalWrite(D4, HIGH);  
    digitalWrite(D3, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D1, HIGH);

    // Sending input to 
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

    // sending signal to wifi
    digitalWrite(D4, HIGH);  
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, LOW);

    // sending signal to slave ardino via I2C.
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(5);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<200;i++)
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


// process 11--------------------------------------------------
//(red line)
int process11()
{
    Serial.println("Process 11 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(6);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<200;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(50);
    }
    Serial.println("Process 11 ends");
}

// process 12--------------------------------------------------
int process12()
{
    // sending signal to wifi
    digitalWrite(D4, HIGH);  
    digitalWrite(D3, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D1, LOW);

    Serial.println("Process 12 starts");
    digitalWrite(relay3, LOW);
    delay(1500);
    digitalWrite(relay3, HIGH);
    Serial.println("Process 11 ends");
}


// process 13--------------------------------------------------

int process13()
{
    Serial.println("Process 13 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(7);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    i = 80;
    j = 0;
    for(i=80;i>65;i--)
    {
        leds[7][i] = CRGB(0,75,0);
        leds[5][j] = CRGB(0,75,0);
        FastLED.show();
        delay(120); 
        j++;
    }
    delay(960);
    j = 0;
    for(i=80;i>65;i--)
    {
        leds[7][i] = CRGB(0,0,0);
        leds[5][j] = CRGB(0,0,0);
        FastLED.show();
        delay(120);
        j++;
    }

    for(i=0;i<200;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(50);
    }
    Serial.println("Process 13 ends");
}

int process14()
{
    Serial.println("Process 14 starts");
    Wire.beginTransmission(9);    // sending value to arduino 2
    Wire.write(8);                // sending value to arduino 2
    Wire.endTransmission();       // sending value to arduino 2
    delay(50);
    for(i=0;i<200;i++)
    {
        slaveStatus = digitalRead(slaveReady);
        Serial.println(slaveStatus);
        if (slaveStatus > 0)
        {
            break;  
        }
        delay(50);
    }
    Serial.println("Process 14 ends");
}


// process 15--------------------------------------------------
int process15()
{
	// sending signal to wifi
    digitalWrite(D4, HIGH);  
    digitalWrite(D3, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, HIGH);

    // sending signal to slave ardino via I2C.
    Serial.println("Process 15 starts");
    digitalWrite(relay4, LOW);
    delay(1500);
    digitalWrite(relay4, HIGH);
    Serial.println("Process 15 ends");
}