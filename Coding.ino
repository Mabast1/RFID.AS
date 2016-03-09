#include <SPI.h>
#include <RFID.h>
#include "pitches.h"
#include <Ethernet.h>
#include <LiquidCrystal.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x96, 0xB4 };
byte ip[] = { 169,254,76,246 };
char server[]={"example.com"};

EthernetClient client;

RFID rfid(10,5);
byte USER[5] = {124,11,145,50,212};

LiquidCrystal lcd(9, 8, 7, 4, 3, 2);
byte serNum[5];
byte data[5];

void setup(){ 
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  delay(1000);
  lcd.begin(16, 2);
  lcd.print(Ethernet.localIP());
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  lcd.setCursor(0,1);
  lcd.print("Waiting for Card");
  Serial.println("Waiting for Card");
}

void loop(){
  boolean USER_card = true;
  if (rfid.isCard()){ 
    if (rfid.readCardSerial()){
      data[0] = rfid.serNum[0]; 
      data[1] = rfid.serNum[1];
      data[2] = rfid.serNum[2];
      data[3] = rfid.serNum[3];
      data[4] = rfid.serNum[4];
    }  
 
  for(int i=0; i<5; i++){
    if(data[i] != USER[i]) USER_card = false; 
  } 
    if (client.connect(server, 80)) {
      
    if (USER_card){
    Serial.println("Connection Successfull");
    client.print("GET http://example.com/arduino.php?v=");
    client.print(data[0]);client.print(data[1]);client.print(data[2]);client.print(data[3]);client.print(data[4]);
    client.println(" HTTP/1.0"); client.println("User-Agent: Arduino 1.0");
    client.println(); client.stop(); lcd.clear();
    lcd.print("USER!");
    Serial.println("Hello USER!");  
    delay(1000);  
  }
  
  else{ 
    lcd.clear();
    lcd.print("Card not");
    lcd.setCursor(0,1);
    lcd.print("recognized!");
    Serial.println("Card not recognized!");
     delay(1000);
  }
  if (USER_card){ 
   lcd.setCursor(0,1);
   lcd.print("Access Granted!");
    Serial.println("Access Granted!... Welcome!");
    delay(1000);
  }
  Serial.println();
  lcd.clear();
  lcd.print("    Welcome!");
  lcd.setCursor(0,1);
  Serial.println("Waiting for Card");
  lcd.print("Waiting for Card");
  client.stop();
  delay(1000);
  }
  else{
    Serial.println("Connection Unuccessfull");
    lcd.clear();
    lcd.print("Connection");
    lcd.setCursor(0,1);
    lcd.print("Unuccessful");
    delay(1000);
    lcd.clear();
    lcd.print("Try Again!");
    client.stop();
    delay(1000);
     }
  }
}
  

