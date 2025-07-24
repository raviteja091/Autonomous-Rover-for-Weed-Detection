#include "batteryManagement.h"
float BatteryMeasure(){
  const int n=50; float total=0;
  for(int i=0;i<n;i++){
    total += analogRead(36)/4095.0 * 4.2;
  }
  float voltage=total/n;
  float pct=((voltage-3.7)/(4.2-3.7))*100;
  return constrain(pct, 0, 100);
}
