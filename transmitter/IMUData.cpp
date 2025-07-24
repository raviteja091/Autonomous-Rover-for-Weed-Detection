#include "IMUData.h"
#include <Wire.h>
#include <MPU9250.h>

MPU9250 mpu;
float pitch=0, roll=0, yaw=0;

void IMU_init() {
  Wire.begin();
  delay(2000);
  if (!mpu.setup(0x68)) Serial.println("MPU9250 not connected");
}
void updateMPUValues(){
  static uint32_t prev=0;
  if (mpu.update() && millis()-prev>25) {
    yaw = mpu.getYaw();
    pitch = mpu.getPitch();
    roll = mpu.getRoll();
    prev = millis();
  }
}
