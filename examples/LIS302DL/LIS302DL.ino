#include "LIS302DL.h"
#include "Wire.h"


LIS302DL sens(0x1c,40000);//inizialize LIS302DL and Wire (i2c slave address,i2c speed)

float z;
 
void setup() {
  Serial.begin(19200);
  sens.turnOn();//turn on the device
  sens.zOn();//turn on z axes
  sens.highSpeed();//output data rate 400hz

}

void loop() {
  z=sens.readZ();
  delay(3);
  Serial.println(z);

}
