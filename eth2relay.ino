//ARDUINO 1.0+ ONLY
//ARDUINO 1.0+ ONLY


#include <Ethernet.h>
#include <SPI.h>
boolean reading = false;

////////////////////////////////////////////////////////////////////////
//CONFIGURE
////////////////////////////////////////////////////////////////////////
  //byte ip[] = { 192, 168, 0, 199 };   //Manual setup only
  //byte gateway[] = { 192, 168, 0, 1 }; //Manual setup only
  //byte subnet[] = { 255, 255, 255, 0 }; //Manual setup only

  // if need to change the MAC address (Very Rare)
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

  EthernetServer server = EthernetServer(80); //port 80
////////////////////////////////////////////////////////////////////////



int SER_Pin = 11;   //pin 14 on the 75HC595
int RCLK_Pin = 8;  //pin 12 on the 75HC595
int SRCLK_Pin = 12; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 2

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
////////////////////////////////////////////////////////



void setup(){
  Serial.begin(9600);

  //Pins 10,11,12 & 13 are used by the ethernet shield
 pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  clearRegisters();
  writeRegisters();
  
  Ethernet.begin(mac);
  //Ethernet.begin(mac, ip, gateway, subnet); //for manual setup

  server.begin();
  Serial.println(Ethernet.localIP());

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

  // listen for incoming clients, and process qequest.
  checkForClient();

}

void checkForClient(){

  EthernetClient client = server.available();

  if (client) {

    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        if(!sentHeader){
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          sentHeader = true;
        }

        char c = client.read();

        if(reading && c == ' ') reading = false;
        if(c == '?') reading = true; //found the ?, begin reading the info

        if(reading){
          Serial.print(c);

           switch (c) {
            case 'a':
              //add code here to trigger on 2
              triggerPin(dev1, client);
              break;
            case 'b':
            //add code here to trigger on 3
              triggerOff(dev1, client);
              break;
            case 'c':
            //add code here to trigger on 4
              triggerPin(dev2, client);
              break;
            case 'd':
            //add code here to trigger on 5
              triggerOff(dev2, client);
              break;
            case 'e':
            //add code here to trigger on 6
              triggerPin(dev3, client);
              break;
            case 'f':
            //add code here to trigger on 7
              triggerOff(dev3, client);
              break;
            case 'g':
            //add code here to trigger on 8
              triggerPin(dev4, client);
              break;
            case 'h':
            //add code here to trigger on 9
              triggerOff(dev4, client);
              break;
          }

        }

        if (c == '\n' && currentLineIsBlank)  break;

        if (c == '\n') {
          currentLineIsBlank = true;
        }else if (c != '\r') {
          currentLineIsBlank = false;
        }

      }
    }

    delay(1); // give the web browser time to receive the data
    client.stop(); // close the connection:

  } 

}







void triggerOff(int offdev, EthernetClient client){
  int delayTime=200;
  
    client.print("Turning OFF dev ");
  client.println(offdev);
  client.print("<br>");
   client.print("<br>MAINC SRULDEBA???");
   
      setRegisterPin(offdev, LOW);
      writeRegisters();
      delay(delayTime);
;

}
  
void triggerPin(int ondev, EthernetClient client){
  
    int delayTime=200;
  
  client.print("Turning on dev ");
  client.println(ondev);
  client.print("<br>");
   
      setRegisterPin(ondev, HIGH);
      writeRegisters();
      delay(delayTime);
;


}
