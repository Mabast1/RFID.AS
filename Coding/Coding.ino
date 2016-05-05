      /*
      #####################################################################################
      #  	RFID Attendance System 
      #   Team Leader : Mabast Ahmad
      #   Team Members: Maksat Taganov
      #                 Douglas Perez
      #                 Bakhromjon Kamolov
      #                 Andi Alla 
      #					
      #####################################################################################
       
      */
      
      // Libraries
      #include <SPI.h>
      #include <RFID.h>
      #include "pitches.h"
      #include <Ethernet.h>
      #include <LiquidCrystal.h>
      
      byte mac[] = { 0x7c,0xc3,0xa1,0x89,0x32,0xa4 };
      byte ip[] = { 169,254,100,202 }; // Direction ip local
      char server[]={"localhost"};
      
      EthernetClient client;
      
      // RFID definition
      RFID rfid(10,5);
      byte USER[5] = {156 , 188 , 26 , 43 , 17};
      //Put here the another allowed cards
      
      //LCD address and type declaration
      LiquidCrystal lcd(9, 8, 7, 4, 3, 2);
      byte serNum[5];
      byte data[5];
      
      void setup(){ 
        Serial.begin(9600);
        Ethernet.begin(mac, ip); //Initiation ethernet shield
        delay(1000); // Waiting 1 second after initializing
        lcd.begin(16, 2);
        lcd.print(Ethernet.localIP());
        Serial.print("My IP address: ");
        Serial.println(Ethernet.localIP());
        
        Serial.begin(9600); // Serial communication initialization
        SPI.begin(); // SPI communication initialization
        rfid.init(); // RFID module initialization
        lcd.setCursor(0,1);
        lcd.print("Waiting for Card");
        Serial.println("Waiting for Card");
      }
      
      void loop(){
        boolean USER_card = true;  // Here you can create a variable for each user
        //Put here the another variable for user
        
        if (rfid.isCard()){ // valid card found
          if (rfid.readCardSerial()){ // reads the card 
            data[0] = rfid.serNum[0]; // stores the serial number
            data[1] = rfid.serNum[1];
            data[2] = rfid.serNum[2];
            data[3] = rfid.serNum[3];
            data[4] = rfid.serNum[4];
          }  
       
        for(int i=0; i<5; i++){
          if(data[i] != USER[i]) USER_card = false; // if it is not a valid card, put false to this user
          // Here you can check the another allowed users, just put lines like above with the user name
        } 
if (client.connect(server,80)) {
            
    if (USER_card){
    Serial.println("Connection Successfull");
    client.print("GET http://localhost/~Mabast/arduino.php?v=");
    client.print(data[0]);client.print(data[1]);client.print(data[2]);client.print(data[3]);client.print(data[4]);
    client.println(" HTTP/1.0"); client.println("User-Agent: Arduino 1.0");
    client.println(); client.stop(); lcd.clear();
    lcd.print("USER!");
    Serial.println("Hello USER!"); // print a message  
    delay(1000);  
    }else{ // if a card is not recognized
      lcd.clear();
      lcd.print("Card not");
      lcd.setCursor(0,1);
      lcd.print("recognized!");
      Serial.println("Card not recognized!"); // print a message
       delay(1000);
      }
      if (USER_card){// add another user using an logical or condition ||
          // Welcome messages and access permission  
       lcd.setCursor(0,1);
       lcd.print("Access Granted!");
        Serial.println("Access Granted!... Welcome!"); // print a message
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
        

