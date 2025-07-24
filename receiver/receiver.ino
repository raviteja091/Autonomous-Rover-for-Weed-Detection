#include "MPU9250.h"
#include <Wire.h>
#include "IMUData.h"
#include "ButtonData.h"
#include "flashLED.h"
#include "batteryManagement.h"
#include "wifi_RX.h"
#include "motor.h"

bool displayOut=false, displayIn=false;

void setup(){
  Serial.begin(115200);
  IMU_init();
  Button_Init();
  flashLED_Init();
  batteryInit();
  motor_Init();
  wifi_Init();
}

void loop(){
  updateMPUValues();
  readJoystickValues();
  wifireceiveData();
  if (Serial.available()){
    char c=Serial.read();
    if(c=='o') { displayOut=true; displayIn=false; }
    if(c=='i') { displayIn=true; displayOut=false; }
    if(c=='s') { displayOut=displayIn=false; }
  }
  if(displayOut) outgoingvaluestowifi();
  if(displayIn) incomingvaluesfromwifi();
  flashLED_run();  
  delay(10);
}
