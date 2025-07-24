#include "wifi_RX.h"
#include <esp_now.h>
#include <WiFi.h>
#include "IMUData.h"
#include "ButtonData.h"
#include "motor.h"

typedef struct {
  int jx1, jy1, jb1;
  float theta_out, phi_out, psi_out;
} incoming_message;

incoming_message inMsg;
uint8_t peerAddr[6]={0xD8,0x13,0x2A,0xED,0x7F,0xB0};
String success;

void OnDataSent(const uint8_t*,esp_now_send_status_t){}
void OnDataRecv(const uint8_t*,const uint8_t* data,int){
  memcpy(&inMsg,data,sizeof(inMsg));
}

void wifi_Init(){
  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_peer_info_t peer={};
  memcpy(peer.peer_addr,peerAddr,6);
  esp_now_add_peer(&peer);
}

void wifireceiveData(){
  // nothing here; data arrives in callback
}

void outgoingvaluestowifi(){
  Serial.print("MotorEnc: ");
  Serial.print(encoderValue1);Serial.print(",");
  Serial.print(encoderValue2);Serial.print(",");
  Serial.print(encoderValue3);Serial.print(",");
  Serial.println(encoderValue4);
}

void incomingvaluesfromwifi(){
  Serial.print("TX IMU: ");
  Serial.print(inMsg.theta_out);Serial.print(",");
  Serial.print(inMsg.phi_out);Serial.print(",");
  Serial.println(inMsg.psi_out);
}
