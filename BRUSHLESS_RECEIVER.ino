/*
BRUSHLESS RECEIVER:
receive the data for transmitter and sen to esc

*/
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include<Servo.h>

RF24 radio(7,8);//CE AND CSN
Servo ESC;

  const byte address[10] = "SIDDHARTH";


void setup() {
  // put your setup code here, to run once:
  ESC.attach(10,1000,2000);// calibarate the esc
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);//open pipe to read th data
  radio.setPALevel(RF24_PA_MAX);// set the rang
  radio.startListening();// set as receiver

}

void loop() {
  // put your main code here, to run repeatedly:
  
   if(radio.available())
   while(radio.available()){
    int YPotval = 0;
    radio.read(&YPotval,sizeof(YPotval));
    ESC.write(YPotval);
    Serial.println(YPotval);
    
   }

}
