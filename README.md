Te# Project_CoDs_model1
Electrical setup for architechral model. Physical model and light board setups. 

https://www.cods.lk/ deverloping achitecturel model for newly building westewater treatment plat in Kandy. 
This repo represent the light, motor control codes. 

Also this servers as projectlog file

10.06.2020
1. Install arduino 
2. Test arduino mega
3. Test ESP8266MOD
    arduino--> files --> preferance --> 
    Additional board manager URLs: http://arduino.esp8266.com/stable/package_esp8266com_index.json
    arduino--> tools--> board--> Boards Manager
      i.    Scerch: ESP8266 --> install
      ii.   Select board--> WeMos D1 R2 & mini
      iii.  In repo: Project_CoDs_model1-->Test_dev--> wifi_mod--> test1
      
17.06.2020
4. Enabaling wifi to wifi comuniction
	Inside Test_dev/wifi_mod/Test2 contains "ArduinoJson" folder
	Create zip folder from it. It is an arduino libry includeing headdres for ESP8266 trasmitter and 
	receiver module.
	Include that libry to the ArduinoIDE from Sketch-->Include Library-->Add .ZIP Library
5. upload esp8266_receiver.ino and esp8266_transmitter.ino to two divices.
6. Serial read the receiver module from arduinoIDE.

