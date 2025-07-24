#include "ButtonData.h"
#include <Arduino.h>

int joy1XVal, joy1YVal, joy1ButtonState;
const int joy1X=32, joy1Y=33, joy1Button=16;

void Button_Init(){
  pinMode(joy1Button, INPUT_PULLUP);
}
void readJoystickValues(){
  joy1XVal = analogRead(joy1X);
  joy1YVal = analogRead(joy1Y);
  joy1ButtonState = digitalRead(joy1Button);
}
