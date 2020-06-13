int Relay_module_input_1 = 38;
int Relay_module_input_2 = 40;
int Relay_module_input_3 = 42;
int Relay_module_input_4 = 44;
int Relay_module_input_5 = 46;
int Relay_module_input_6 = 48;
int Relay_module_input_7 = 50;
int Relay_module_input_8 = 52;



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

  digitalWrite(Relay_module_input_1, LOW);
  digitalWrite(Relay_module_input_2, LOW); 
  digitalWrite(Relay_module_input_3, LOW); 
  digitalWrite(Relay_module_input_4, LOW); 
  digitalWrite(Relay_module_input_5, LOW); 
  digitalWrite(Relay_module_input_6, LOW); 
  digitalWrite(Relay_module_input_7, LOW); 
  digitalWrite(Relay_module_input_8, LOW);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(3000);
}

void loop() {
 
  
  digitalWrite(Relay_module_input_4, HIGH);
  delay(1000);                       
  digitalWrite(Relay_module_input_4, LOW);    
  delay(1000);

}
