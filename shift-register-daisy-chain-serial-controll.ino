int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 12;  //pin 12 on the 75HC595
int SRCLK_Pin = 11; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 3

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


int fan1=0;
int fan2=1;
int pump1=8;


void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  Serial.begin(9600); // baud rate
  Serial.flush();


  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
  writeRegisters();
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}



void loop(){

  relaycontroll();
  
  
}



void relaycontroll()
{
  
  
  int delayTime=200;
  String input = "";
 
     // Read any serial input
     while (Serial.available() > 0)
     {
         input += (char) Serial.read(); // Read in one char at a time
         delay(5); // Delay for 5 ms so the next char has time to be received
     }




/////////////////////////// Relay 1 
     if (input == "fan1_on")
     {
      setRegisterPin(fan1, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "fan1_off") 
{ 
      setRegisterPin(fan1, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}



/////////////////////////// End Relay 1 

/////////////////////////// Relay 2
     if (input == "fan2_on")
     {
      setRegisterPin(fan2, HIGH);
      writeRegisters();
      delay(delayTime);
//    clearRegisters();
     }
     else if(input == "fan2_off") 
{ 
      setRegisterPin(fan2, LOW);
      writeRegisters();
      delay(delayTime);
//      clearRegisters();

}
/////////////////////////// End Relay 2


/////////////////////////// Relay 2
     if (input == "pump1_on")
     {
      setRegisterPin(pump1, HIGH);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
     }
     else if(input == "pump1_off") 
{ 
      setRegisterPin(pump1, LOW);
      writeRegisters();
      delay(delayTime);
 //     clearRegisters();
}
/////////////////////////// End Relay 2






}

