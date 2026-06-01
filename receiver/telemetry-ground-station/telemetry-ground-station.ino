/*
* Receiver Program on Arduino Nano
*
* ## Acknowledgements
*
* This project was developed through experimentation with Arduino, NRF24L01 telemetry systems, MPU6050 motion processing, and VPython visualization.
*
* Some NRF24L01 communication concepts were adapted from tutorials by Dejan Nedelkovski (HowToMechatronics) and MPU6050 DMP examples from Jeff Rowberg’s I2Cdevlib project.
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

float f1; // initializing float values
float f2;
float f3;
float dataToReceive[3] = { f1, f2, f3 }; // creating an array
RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setAutoAck(false); 
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    float dataToReceive[3]; // recieving an array and printing
    radio.read(&dataToReceive, sizeof(dataToReceive));
    Serial.print(dataToReceive[0]);
    Serial.print(",");
    Serial.print(dataToReceive[1]);
    Serial.print(",");
    Serial.println(dataToReceive[2]);
  }
}
