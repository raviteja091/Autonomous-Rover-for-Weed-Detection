#include "motor.h"
#include <Arduino.h>

#define Mot1Fwd 12; // etc...
volatile long encoderValue1,encoderValue2,encoderValue3,encoderValue4;
int lastEncoded1=0; // similarly for others

void motor_Init(){
  pinMode(Mot1Fwd,OUTPUT); // define all
  attachInterrupt(digitalPinToInterrupt(23),Encoder1,CHANGE);
  // similarly others...
}

void moveMotor(int m,int dir){
  // implement forward/reverse per motor
}

void Encoder1(){
  int MSB=digitalRead(23),LSB=digitalRead(25);
  int encoded=(MSB<<1)|LSB;
  int sum=(lastEncoded1<<2)|encoded;
  if(sum==0b1101||... ) encoderValue1--;
  if(sum==0b1110||...) encoderValue1++;
  lastEncoded1=encoded;
}
// similarly Encoder2/3/4
