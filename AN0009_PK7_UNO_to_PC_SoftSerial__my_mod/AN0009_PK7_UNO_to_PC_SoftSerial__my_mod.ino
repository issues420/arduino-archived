/*
 AN0009-PK7-UNO_to_PC_SoftSerial
 ===============================
 Function: 
 --- Communication between PC and UNO via 2.4G RF Module
 --- PC Sent command "LED=ON" to turn ON the LED
 --- PC Sent command "LED=OFF" to turn OFF the LED
 
 HW Request:
 --- 1 * PK7 : http://www.ebay.com/itm/PK7-Arduino-2-4GHz-RF-shield-batt-UART-wireless-sensor-instead-XBee-Bluetooth-/221278984998?pt=LH_DefaultDomain_0&hash=item3385415b26
  
 SW Request:
 --- Arduino 1.5.2
 --- sscom32E.exe V3.2 Serial tool for Windows
 --- LC-1000U Driver: http://www.inhaos.com/downcount.php?download_id=90
 
 Document Request:
 --- BUONO UNO R3 Datasheet: http://www.inhaos.com/uploadfile/otherpic/DOC-BUONO-UNO-R3-V02-EN.pdf
 --- LC-1000 Datasheet: http://www.inhaos.com/uploadfile/otherpic/UM-LC-1000-V10-EN.pdf
 --- LC-1000U Datasheet: http://www.inhaos.com/uploadfile/otherpic/UM-LC-1000U-V10-EN.pdf
 --- BATT & RF UART SHIELD Datasheet: http://www.inhaos.com/uploadfile/otherpic/DOC-BATT-RF-SHIELD-V01-EN.pdf
 
 The circuit (P4 Config):
 --- Connect RXD and #8 --- Use SoftSerial rxd
 --- Connect TXD and #9 --- Use SoftSerial txd
 */


#include <SoftwareSerial.h>

SoftwareSerial mySerial(8,9); // RX, TX

int led = 13;
int led2 = 2; //red
int led3 = 4; //green
int led4 = 7; //blue

String inputString = "";  // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
const String Led_On = "0ON";
const String Led_Off = "0OFF";
const String pin2on = "2ON";
const String pin2off = "2OFF";
const String pin4on = "4ON";
const String pin4off = "4OFF";
const String pin7on = "7ON";
const String pin7off = "7OFF";

void setup()  
{
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void loop() // run over and over
{
  myserialEvent();
  if (stringComplete) {
    inputString.toUpperCase();    
    if(inputString == Led_On) digitalWrite(led, HIGH);
    if(inputString == Led_Off) digitalWrite(led, LOW);
    if(inputString == pin2on) digitalWrite(led2, LOW);
    if(inputString == pin2off) digitalWrite(led2, HIGH);
    if(inputString == pin4on) digitalWrite(led3, LOW);
    if(inputString == pin4off) digitalWrite(led3, HIGH);
    if(inputString == pin7on) digitalWrite(led4, LOW);
    if(inputString == pin7off) digitalWrite(led4, HIGH);
    mySerial.println("hello world!\n");
    mySerial.println(inputString);
    inputString = "";
    stringComplete = false; 
  }
}

void myserialEvent() {
  if (stringComplete == false){
    if (mySerial.available()) {
      char inChar = (char)mySerial.read(); 
      if (inChar == 0x0d || inChar == 0x0a) {
        stringComplete = true;
      }
      if (stringComplete == false){
        if (inChar != ' ') inputString += inChar;
      }
    }
  }
}
























