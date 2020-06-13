/*
* Test for IR module
  Malithjkd
  09.06.2020
*/

int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(53,INPUT);
}

void loop() {
  val = digitalRead(53);
  Serial.println(val);
}
