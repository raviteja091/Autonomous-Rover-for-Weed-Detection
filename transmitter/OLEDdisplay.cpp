#include "OLEDdisplay.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
extern float pitch, roll, yaw;
#define W 128, H 64
Adafruit_SSD1306 display(W, &Wire, -1);

void OLED_Init(){
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)) Serial.println("OLED fail");
  display.clearDisplay();
}
void OLEDDisplay(){
  display.clearDisplay();
  display.setCursor(0,0); display.print("Yaw: "); display.println(yaw,2);
  display.setCursor(0,20); display.print("Pitch: "); display.println(pitch,2);
  display.setCursor(0,40); display.print("Roll: "); display.println(roll,2);
  display.display();
}
