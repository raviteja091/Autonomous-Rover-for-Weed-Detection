#include "MPU9250.h"  // MPU9250 IMU sensor library
#include <Wire.h>     // I2C library
#include "IMUData.h"
#include "ButtonData.h"
#include "flashLED.h"
#include "batteryManagement.h"
#include "OLEDdisplay.h"
#include "wifi_TX.h"

bool displayOutGoing = false;
bool displayIncoming = false;

void setup() {
  Serial.begin(115200);
  IMU_init();
  Button_Init();
  flashLED_Init();
  OLED_Init();
  batteryInit();
  wifi_Init();
}

void loop() {
  updateMPUValues();
  readJoystickValues();
  float battPct = BatteryMeasure();
  OLEDDisplay();  
  wifisendData();

  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c=='o') { displayOutGoing=true; displayIncoming=false; }
    if (c=='i') { displayIncoming=true; displayOutGoing=false; }
    if (c=='s') { displayOutGoing=false; displayIncoming=false; }
  }
  if (displayOutGoing) outgoingvaluestowifi();
  if (displayIncoming) incomingvaluesfromwifi();

  flashLED_run();
  delay(10);
}
