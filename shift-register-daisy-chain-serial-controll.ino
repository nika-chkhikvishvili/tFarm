int SER_Pin = 11;   //pin 14 on the 75HC595
int RCLK_Pin = 8;  //pin 12 on the 75HC595
int SRCLK_Pin = 12; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 6

//register pins
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


int dev1=0;
int dev2=1;
int dev3=2;
int dev4=3;
int dev5=4;
int dev6=5;
int dev7=6;
int dev8=7;
int dev9=8;
int dev10=9;
int dev11=10;
int dev12=11;
int dev13=12;
int dev14=13;
int dev15=14;
int dev16=15;
int dev17=16;
int dev18=17;
int dev19=18;
int dev20=19;
int dev21=20;
int dev22=21;
int dev23=22;
int dev24=23;
int dev25=24;
int dev26=25;
int dev27=26;
int dev28=27;
int dev29=28;
int dev30=29;
int dev31=30;
int dev32=31;
int dev33=32;
int dev34=33;
int dev35=34;
int dev36=35;
int dev37=36;
int dev38=37;
int dev39=38;
int dev40=39;
int dev41=40;
int dev42=41;
int dev43=42;
int dev44=43;
int dev45=44;
int dev46=45;
int dev47=46;
int dev48=47;




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
     if (input == "dev1_on")
     {
      setRegisterPin(dev1, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev1_off") 
{ 
      setRegisterPin(dev1, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 1
/////////////////////////// Relay 2 
     if (input == "dev2_on")
     {
      setRegisterPin(dev2, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev2_off") 
{ 
      setRegisterPin(dev2, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 2
/////////////////////////// Relay 3 
     if (input == "dev3_on")
     {
      setRegisterPin(dev3, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev3_off") 
{ 
      setRegisterPin(dev3, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 3
/////////////////////////// Relay 4 
     if (input == "dev4_on")
     {
      setRegisterPin(dev4, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev4_off") 
{ 
      setRegisterPin(dev4, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 4
/////////////////////////// Relay 5 
     if (input == "dev5_on")
     {
      setRegisterPin(dev5, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev5_off") 
{ 
      setRegisterPin(dev5, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 5
/////////////////////////// Relay 6 
     if (input == "dev6_on")
     {
      setRegisterPin(dev6, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev6_off") 
{ 
      setRegisterPin(dev6, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 6
/////////////////////////// Relay 7 
     if (input == "dev7_on")
     {
      setRegisterPin(dev7, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev7_off") 
{ 
      setRegisterPin(dev7, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 7
/////////////////////////// Relay 8 
     if (input == "dev8_on")
     {
      setRegisterPin(dev8, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev8_off") 
{ 
      setRegisterPin(dev8, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 8
/////////////////////////// Relay 9 
     if (input == "dev9_on")
     {
      setRegisterPin(dev9, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev9_off") 
{ 
      setRegisterPin(dev9, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 9
/////////////////////////// Relay 10 
     if (input == "dev10_on")
     {
      setRegisterPin(dev10, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev10_off") 
{ 
      setRegisterPin(dev10, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 10
/////////////////////////// Relay 11 
     if (input == "dev11_on")
     {
      setRegisterPin(dev11, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev11_off") 
{ 
      setRegisterPin(dev11, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 11
/////////////////////////// Relay 12 
     if (input == "dev12_on")
     {
      setRegisterPin(dev12, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev12_off") 
{ 
      setRegisterPin(dev12, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 12
/////////////////////////// Relay 13 
     if (input == "dev13_on")
     {
      setRegisterPin(dev13, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev13_off") 
{ 
      setRegisterPin(dev13, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 13
/////////////////////////// Relay 14 
     if (input == "dev14_on")
     {
      setRegisterPin(dev14, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev14_off") 
{ 
      setRegisterPin(dev14, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 14
/////////////////////////// Relay 15 
     if (input == "dev15_on")
     {
      setRegisterPin(dev15, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev15_off") 
{ 
      setRegisterPin(dev15, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 15
/////////////////////////// Relay 16 
     if (input == "dev16_on")
     {
      setRegisterPin(dev16, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev16_off") 
{ 
      setRegisterPin(dev16, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 16





}
