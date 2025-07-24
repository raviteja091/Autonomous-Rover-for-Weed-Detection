#include "wifi_TX.h"
#include <esp_now.h>
#include <WiFi.h>
#include "IMUData.h"
#include "ButtonData.h"

typedef struct {
  int jx1, jy1, jb1;
  float theta_out, phi_out, psi_out;
} outgoing_message;

outgoing_message outMsg;
uint8_t peerAddr[6]={0xC8,0xF0,0x9E,0xBA,0x60,0x9C};
String success;

void OnDataSent(const uint8_t*, esp_now_send_status_t status){
  success = status==ESP_NOW_SEND_SUCCESS?"Success":"Fail";
}
void OnDataRecv(const uint8_t*,const uint8_t*,int){}

void wifi_Init(){
  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_peer_info_t peer={};
  memcpy(peer.peer_addr,peerAddr,6);
  esp_now_add_peer(&peer);
}

void wifisendData(){
  outMsg.jx1=joy1XVal; outMsg.jy1=joy1YVal; outMsg.jb1=joy1ButtonState;
  outMsg.theta_out=pitch; outMsg.phi_out=roll; outMsg.psi_out=yaw;
  esp_now_send(peerAddr,(uint8_t*)&outMsg,sizeof(outMsg));
}

void outgoingvaluestowifi(){
  Serial.print("joystick: ");Serial.print(joy1XVal);Serial.print(",");
  Serial.print(joy1YVal);Serial.print(" IMU: ");
  Serial.print(pitch);Serial.print(",");
  Serial.print(roll);Serial.print(",");
  Serial.println(yaw);
}

void incomingvaluesfromwifi(){
  // no-op for TX
}
