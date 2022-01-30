#include <MeMCore.h>

MePort servoConnector(PORT_1);
Servo servo1;

void setup(){
  servo1.attach(servoConnector.pin1);
}

void loop(){
  servo1.write(90);
  delay(1000);
  servo1.write(120);
  delay(1000);
}
