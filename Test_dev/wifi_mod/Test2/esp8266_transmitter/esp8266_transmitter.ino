/*
 Wifi siglnal transmitter module
 To establish the communication bitween two divices using wifi technology we use ESP8266 module D1 Mini.
 malithjkd
 17.06.2020
*/

#include <ESP8266WiFi.h>

const char *ssid = "malithjkd";
const char *password = "password";

int sensorValue0 = 0;       //sensor value, I'm usingg 0/1 button state
int sensorValue1 = 0;        
int sensorValue2 = 0;        
int sensorValue3 = 0;
int sensorValue4 = 0;  

void setup() {
  Serial.begin(9600);
  Serial.println("test1/ malith jkd ");
  delay(10);

  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);


  // set the ESP8266 to be a WiFi-client
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

}

void loop() {

  
  sensorValue0 = digitalRead(D1);
  sensorValue1 = digitalRead(D2);
  sensorValue2 = digitalRead(D3);
  sensorValue3 = digitalRead(D4); 
  Serial.println("sensorRead");
  Serial.print(sensorValue0);
  Serial.print(",");
  Serial.print(sensorValue1);
  Serial.print(",");
  Serial.print(sensorValue2);
  Serial.print(",");
  Serial.print(sensorValue3);
  
  sensorValue4 = sensorValue3*8 + sensorValue2*4 + sensorValue1*2 + sensorValue0;
  Serial.println(sensorValue4);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const char * host = "192.168.4.1";            //default IP address
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request. Something like /data/?sensor_reading=123
  String url = "/data/";
  url += "?sensor_reading=";
  url +=  "{\"s4r\":\"sensor4_value\"}";

  url.replace("sensor4_value", String(sensorValue4));

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  
  while (client.available() == 0) {
    if (millis() - timeout > 10000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}
