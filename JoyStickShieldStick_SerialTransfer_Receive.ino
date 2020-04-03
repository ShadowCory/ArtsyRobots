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
  SerialBT.begin("Recver");
  joyStick.begin(SerialBT);
}

void loop()
{
  if(joyStick.available()){
    joyStick.rxObj(dataStruct, sizeof(dataStruct));
    //(dataStruct.joy_X) = map((dataStruct.joy_X), 0, 4095, 0, 9);
    //(dataStruct.joy_Y) = map((dataStruct.joy_Y), 0, 4095, 0, 9);
    SerialBT.print(dataStruct.joy_X);
    SerialBT.print(' ');
    SerialBT.print(dataStruct.joy_Y);
    SerialBT.print(' ');
    

 // Y in negative direction  
//  if ((dataStruct.joy_X)>=1 && (dataStruct.joy_Y)<=3)
//  {
//    SerialBT.println("Left");
//  }
//
//// X in negative direction
//  if ((dataStruct.joy_X)<=3 && (dataStruct.joy_Y)>=1)
//  {
//    SerialBT.println("Backward");
//  }
//  
//  // Y in positive direction
//  if ((dataStruct.joy_X)>=1 && (dataStruct.joy_Y)>=7)
//  {
//    SerialBT.println("Right");
//  }
//
//// X in positive direction
//  if ((dataStruct.joy_X)>=7 && (dataStruct.joy_Y)>=1)
//  {
//    SerialBT.println("Forward");
//  }
//  else{SerialBT.println("Idle");}
// 
//  delay(50);
//  }
  }
  else if(joyStick.status < 0);
    SerialBT.print("ERROR: ");
    SerialBT.println(joyStick.status);
}
