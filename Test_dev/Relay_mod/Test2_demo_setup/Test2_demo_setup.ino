int Relay_module_input_1 = 52;
int Relay_module_input_2 = 50;
int Relay_module_input_3 = 48;
int Relay_module_input_4 = 46;
int Relay_module_input_5 = 44;
int Relay_module_input_6 = 42;
int Relay_module_input_7 = 40;
int Relay_module_input_8 = 38;



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Relay_module_input_1, OUTPUT);
  pinMode(Relay_module_input_2, OUTPUT);
  pinMode(Relay_module_input_3, OUTPUT);
  pinMode(Relay_module_input_4, OUTPUT);
  pinMode(Relay_module_input_5, OUTPUT);
  pinMode(Relay_module_input_6, OUTPUT);
  pinMode(Relay_module_input_7, OUTPUT);
  pinMode(Relay_module_input_8, OUTPUT);

  digitalWrite(Relay_module_input_1, HIGH);
  digitalWrite(Relay_module_input_2, HIGH); 
  digitalWrite(Relay_module_input_3, LOW); 
  delay(1000);
  digitalWrite(Relay_module_input_4, LOW); 
  delay(1000);
  digitalWrite(Relay_module_input_5, HIGH); 
  digitalWrite(Relay_module_input_6, HIGH); 
  digitalWrite(Relay_module_input_7, HIGH); 
  digitalWrite(Relay_module_input_8, HIGH);

}

void loop() {


}
