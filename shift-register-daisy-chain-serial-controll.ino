int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 12;  //pin 12 on the 75HC595
int SRCLK_Pin = 11; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 3

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


int led1=0;
int led2=1;
int led3=2;
int led4=3;
int led5=4;
int led6=5;
int led7=6;
int led8=7;
// second shift
int led9=8;
int led10=9;
int led11=10;
int led12=11;
int led13=12
int led14=13;
int led15=14;
int led16=15;



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


/*
PROBLEM. to be fixed:
Random shift register's output states at power up
maybe solution:
OE / MR pins 
pullup resistors
*/

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
     if (input == "led1_on")
     {
      setRegisterPin(led1, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led1_off") 
{ 
      setRegisterPin(led1, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 1
/////////////////////////// Relay 2 
     if (input == "led2_on")
     {
      setRegisterPin(led2, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led2_off") 
{ 
      setRegisterPin(led2, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 2
/////////////////////////// Relay 3 
     if (input == "led3_on")
     {
      setRegisterPin(led3, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led3_off") 
{ 
      setRegisterPin(led3, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 3
/////////////////////////// Relay 4 
     if (input == "led4_on")
     {
      setRegisterPin(led4, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led4_off") 
{ 
      setRegisterPin(led4, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 4
/////////////////////////// Relay 5 
     if (input == "led5_on")
     {
      setRegisterPin(led5, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led5_off") 
{ 
      setRegisterPin(led5, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 5
/////////////////////////// Relay 6 
     if (input == "led6_on")
     {
      setRegisterPin(led6, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led6_off") 
{ 
      setRegisterPin(led6, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 6
/////////////////////////// Relay 7 
     if (input == "led7_on")
     {
      setRegisterPin(led7, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led7_off") 
{ 
      setRegisterPin(led7, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 7
/////////////////////////// Relay 8 
     if (input == "led8_on")
     {
      setRegisterPin(led8, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led8_off") 
{ 
      setRegisterPin(led8, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 8
/////////////////////////// Relay 9 
     if (input == "led9_on")
     {
      setRegisterPin(led9, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led9_off") 
{ 
      setRegisterPin(led9, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 9
/////////////////////////// Relay 10 
     if (input == "led10_on")
     {
      setRegisterPin(led10, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led10_off") 
{ 
      setRegisterPin(led10, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 10
/////////////////////////// Relay 11 
     if (input == "led11_on")
     {
      setRegisterPin(led11, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led11_off") 
{ 
      setRegisterPin(led11, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 11
/////////////////////////// Relay 12 
     if (input == "led12_on")
     {
      setRegisterPin(led12, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led12_off") 
{ 
      setRegisterPin(led12, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 12
/////////////////////////// Relay 13 
     if (input == "led13_on")
     {
      setRegisterPin(led13, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led13_off") 
{ 
      setRegisterPin(led13, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 13
/////////////////////////// Relay 14 
     if (input == "led14_on")
     {
      setRegisterPin(led14, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led14_off") 
{ 
      setRegisterPin(led14, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 14
/////////////////////////// Relay 15 
     if (input == "led15_on")
     {
      setRegisterPin(led15, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led15_off") 
{ 
      setRegisterPin(led15, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 15
/////////////////////////// Relay 16 
     if (input == "led16_on")
     {
      setRegisterPin(led16, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "led16_off") 
{ 
      setRegisterPin(led16, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 16





}

