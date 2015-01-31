// 42 chars wide

#include <SoftwareSerial.h>

#include "thermalprinter.h"

#define ledPin 13
#define rxPin 6
#define txPin 7

int printStatus = 0;

Epson TM88 = Epson(rxPin, txPin); // init the Printer with Output-Pin

void setup()
{

  Serial.begin(9600); //open the USB connection too
  

  delay(1000);

  TM88.start();
  TM88.println("Hello World");  
  TM88.println("");  
  TM88.println("");  
  
  
  TM88.cut();  


}

void loop()                     // run over and over again
{
  
  printStatus = TM88.getStatus();     // get the current status of the TM88 printer
  if (printStatus == 22) {            // if status is 22 then we are good
    Serial.println("printer online");     // debug that we are online
  } else {
    Serial.print("printer offline: ");    // debug that we are offline
    Serial.println(printStatus);          // debug the returned status code  
  } 
  
  
  if (Serial.available() > 0) {
    TM88.print(Serial.read());
  }

  //digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}
