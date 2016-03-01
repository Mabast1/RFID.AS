### RFID based Attendance System

######Team Leader:
  * Mabast Ahmad

######Team Members: 
  * Maksat Taganov
  * Douglas Perez 
  * Bakhromjon Kamolov
  * Andi Alla


**Brief Project Description:**

Attendance in colleges is generally paper based which may sometimes cause errors.
Taking attendance manually consumes more time. So the proposed attendance system uses RFID technology to take attendance.
In this system, each student is issued an RFID tag.
Controlling unit is in the institute. Whenever the card is placed near the reader, it will take the attendance.
[Gantt Chart & More Info](https://drive.google.com/folderview?id=0B7aOwH1Fv0j4dFFpd1dXTUd2dkE&usp=sharing)

**Hardware Requirements:**

* 1 x Intel Galileo (You also can use Arduino UNO and other compatible board )
* 1 x RFID RC522
* 1 x LCD 16x2
* 1 x Potentiometer (10k)
* Jumper Wires
* Ethernet connection cable to Router


**How to design a virtual schematic diagram for your circuit ?**

There're a lot of programs that can be used for designing a circuit, and most of them are really useful that comes with helpful tools letting you design your schematic easily and professionally.

The picture below is a schematic design for this project:
![Project Scheme](https://github.com/Mabast1/RFID.AS/blob/master/RFID%20SCHEME_bb.png)

The software that I'm using here and strongly recommend it:

[Fritzing](http://fritzing.org/home/) , an open-source hardware initiative that makes electronics accessible as a creative material for anyone,its available for (Windows, Mac and Linux) operating systems.
click the link to download Fritzing for your machine: http://fritzing.org/home/

**Connections:**

   in case if you couldn't get the scheme, the below pin to pin connections might help:   

**Connection of *RFID* to *Intel Galileo*:**
   * GND = GROUND
   * 3.3 = 3.3v
   * Reset = Pin 5
   * SDA = Pin 10
   * MOSI = Pin 11
   * MISO = Pin 12
   * SCK = Pin 13

**Connection of *LCD* to *Intel Galileo*:**
   * VSS & RW = GND
   * Vcc = 5v
   * Vo = Potentiometer (the middle pin of the 10k potentiometer)
   * D7 = Pin 2
   * D6 = Pin 3
   * D5 = Pin 4
   * D4 = Pin 7
   * E = Pin 8
   * RS = Pin 9

**Time for Coding** 

  1- First of all you need to [download Arduino](https://www.arduino.cc/en/Main/Software) software to be able to compile run
  and upload the codes into the Galileo.   
  2- Download the library folder in this Repo. and import it into arduino software other wise the compiler pop-up errors.  
  3- to be continued...

