#include <FastLED.h>

int relay1 = 22;
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 28;
int relay6 = 29;
int relay7 = 26;
int relay8 = 27;
int relay_delay = 5000;


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

}

void loop() {
    digitalWrite(relay1, LOW);
    delay(relay_delay);
    digitalWrite(relay1, HIGH);
    delay(relay_delay);
    digitalWrite(relay2, LOW);
    delay(relay_delay);
    digitalWrite(relay2, HIGH);
    delay(relay_delay);
    digitalWrite(relay3, LOW);
    delay(relay_delay);
    digitalWrite(relay3, HIGH);
    delay(relay_delay);
    digitalWrite(relay4, LOW);
    delay(relay_delay);
    digitalWrite(relay4, HIGH);
    delay(relay_delay);
    digitalWrite(relay5, LOW);
    delay(relay_delay);
    digitalWrite(relay5, HIGH);
    delay(relay_delay);
    digitalWrite(relay6, LOW);
    delay(relay_delay);
    digitalWrite(relay6, HIGH);
    delay(relay_delay);
    digitalWrite(relay7, LOW);
    delay(relay_delay);
    digitalWrite(relay7, HIGH);
    delay(relay_delay);
    digitalWrite(relay8, LOW);
    delay(relay_delay);
    digitalWrite(relay8, HIGH);
    delay(relay_delay);
}
