
#include "SerialTransfer.h"
#include "BluetoothSerial.h"

SerialTransfer joyStick;
BluetoothSerial SerialBT;


struct STRUCT {
  uint16_t joy_X;
  uint16_t joy_Y;
} dataStruct;

void setup() {
  Serial.begin(115200);
  //SerialBT.begin("Sender");
  joyStick.begin(SerialBT);
}
 
void loop() {
  dataStruct.joy_X = analogRead(32);
  dataStruct.joy_Y = analogRead(33);
  
  joyStick.txObj(dataStruct, sizeof(dataStruct));
  joyStick.sendData(sizeof(dataStruct));
}
