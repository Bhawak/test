 /*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2015
 by Bhawak Pokhrel
 added motor control
 
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEA };
IPAddress ip(192,168,0,11);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

int pin42=42;
int pin43=43;
int pin44=45;
int pin45=44;
int pin22=26;
int pin23=27;
int pin24=24;
int pin25=25;
int relay=30;
int a=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(pin42,OUTPUT);
  pinMode(pin43,OUTPUT);
  pinMode(pin44,OUTPUT);
  pinMode(pin45,OUTPUT);
  
  pinMode(pin22,OUTPUT);
  pinMode(pin23,OUTPUT);
  pinMode(pin24,OUTPUT);
  pinMode(pin25,OUTPUT);
  
  pinMode(relay,OUTPUT);
  pinMode(31,OUTPUT);
  digitalWrite(31,LOW);
  
  while (!Serial) 
  {


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
 }


void loop() {
  // listen for incoming clients
  int value;
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c; 
        c=client.read();
        if(c=='o')
        {
          c=client.read();
          if(c=='n')
          {
            c=client.read();
            if(c=='=')
            {
              c=client.read();
              value=c-48;
            }
          }
        }

        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        //if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header

          
          
  

     
   
          if(value==2)
          {         //backward
            digitalWrite(pin42,1);
            digitalWrite(pin43,0);
            digitalWrite(pin44,1);
            digitalWrite(pin45,0);
            digitalWrite(pin22,1);
            digitalWrite(pin23,0);
            digitalWrite(pin24,1);
            digitalWrite(pin25,0);
            delay(100);
            
            


          }
          else if(value==1)//forward
          {
            digitalWrite(pin42,0);
            digitalWrite(pin43,1);
            digitalWrite(pin44,0);
            digitalWrite(pin45,1);
            digitalWrite(pin22,0);
            digitalWrite(pin23,1);
            digitalWrite(pin24,0);
            digitalWrite(pin25,1);
            delay(200);

            
            
          }
          else if(value==3){//left
            digitalWrite(pin42,1);
            digitalWrite(pin43,0);
            digitalWrite(pin44,0);
            digitalWrite(pin45,1);
            digitalWrite(pin22,0);
            digitalWrite(pin23,1);
            digitalWrite(pin24,1);
            digitalWrite(pin25,0);
            delay(300);
            
          }
          else if(value==4){//right
          
            digitalWrite(pin42,0);
            digitalWrite(pin43,1);
            digitalWrite(pin44,1);
            digitalWrite(pin45,0);
            digitalWrite(pin22,1);
            digitalWrite(pin23,0);
            digitalWrite(pin24,0);
            digitalWrite(pin25,1);
            delay(300);
          } 
          
           
          else{
           
            digitalWrite(pin42,1);
            digitalWrite(pin43,1);
            digitalWrite(pin44,1);
            digitalWrite(pin45,1);
            digitalWrite(pin22,1);
            digitalWrite(pin23,1);
            digitalWrite(pin24,1);
            digitalWrite(pin25,1);
            delay(200);
          }
            digitalWrite(pin42,1);
            digitalWrite(pin43,1);
            digitalWrite(pin44,1);
            digitalWrite(pin45,1);
            digitalWrite(pin22,1);
            digitalWrite(pin23,1);
            digitalWrite(pin24,1);
            digitalWrite(pin25,1);
          
           

   
   
          
          client.print("{");
          
          client.print("\"inp   ut\" : ");
          client.print(value);
          client.print(", \"pin1\" : ");
          client.print(value);
          client.print(", \"pin2\" : ");
          client.print(value);
          client.print(", \"pin3\" : ");
          client.print(value);
          client.print(", \"pin4\" : ");
          client.print(value);
          client.print(", \"pin5\" : ");
          client.print(value);
          
          client.print("}");
          
          
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
      delay(10);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}


