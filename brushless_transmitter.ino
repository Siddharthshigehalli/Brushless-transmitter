/*
BRUSHLESS TRANSMITTER:
motor will rotate when joystick is move forward and stop when josystik is at centre.

*/
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(7,8);//CE AND CSN

  const byte address[10] = "SIDDHARTH";
  int Yaxis;
  int SW = 2;

  void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  digitalWrite(2,HIGH);
  radio.begin();
  radio.openWritingPipe(address);//open pipe to send data
  radio.setPALevel(RF24_PA_MAX);// set the range
  radio.stopListening();//set as transmitter

}

void loop() {
  // put your main code here, to run repeatedly:
  
  Yaxis = analogRead(A6);//read the anaolg value
  int YPotval = map(Yaxis,0,1023,0,255);//map the joystick val
  radio.write(&YPotval, sizeof(YPotval));// send the data to the receiver

}
