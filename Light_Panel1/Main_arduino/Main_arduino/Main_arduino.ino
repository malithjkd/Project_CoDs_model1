#include <FastLED.h>

int relay1 = 22;
int relay2 = 23;
int relay3 = 24;
int relay4 = 25;
int relay5 = 26;
int relay6 = 27;
int relay7 = 28;
int relay8 = 29;


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

}

void loop() {
  digitalWrite(relay1, HIGH);
  delay(1000);
  digitalWrite(relay1, LOW);
  delay(1000);
  digitalWrite(relay2, HIGH);
  delay(1000);
  digitalWrite(relay2, LOW);
  delay(1000);
  digitalWrite(relay3, HIGH);
  delay(1000);
  digitalWrite(relay3, LOW);
  delay(1000);
  digitalWrite(relay4, HIGH);
  delay(1000);
  digitalWrite(relay4, LOW);
  delay(1000);
  digitalWrite(relay5, HIGH);
  delay(1000);
  digitalWrite(relay5, LOW);
  delay(1000);
  digitalWrite(relay6, HIGH);
  delay(1000);
  digitalWrite(relay6, LOW);
  delay(1000);
  digitalWrite(relay7, HIGH);
  delay(1000);
  digitalWrite(relay7, LOW);
  delay(1000);
  digitalWrite(relay8, HIGH);
  delay(1000);
  digitalWrite(relay8, LOW);
  delay(1000);
}
