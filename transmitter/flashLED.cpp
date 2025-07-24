#include "flashLED.h"
#define NUM_LEDS 64
CRGB leds[NUM_LEDS];

void flashLED_Init(){
  FastLED.addLeds<NEOPIXEL,2>(leds,NUM_LEDS);
  FastLED.setBrightness(84);
}
void flashLED_run(){
  static uint8_t hue=0;
  for(int i=0;i<NUM_LEDS;i++){
    leds[i]=CHSV(hue++,255,255);
    FastLED.show(); fadeall(); delay(10);
  }
  for(int i=NUM_LEDS-1;i>=0;i--){
    leds[i]=CHSV(hue++,255,255);
    FastLED.show(); fadeall(); delay(10);
  }
}
void fadeall(){
  for(int i=0;i<NUM_LEDS;i++) leds[i].nscale8(250);
}
