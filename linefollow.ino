#include <MeMCore.h>

MeDCMotor left(M1);
MeDCMotor right(M2);
MeUltrasonicSensor ultrasonic(PORT_4); 
MeLineFollower line(PORT_3);
MeRGBLed led(PORT_7);

void setup() {

}

void loop() {

    led.setColor(random(1,255), random(1,255), random(1,255));
    delay(750);
    led.show();

  /if(line.readSensors() == 0000) {
    motors(100,100);
    delay(500);
    if (line.readSensors() == 0100) {
    motors(75, 20);
  }else if(line.readSensors() == 1100){
      motors(100, 25);
  }else if(line.readSensors() == 0010){
    motors(20,75);
  }else if(line.readSensors() == 0011){
    motors(25,100);
  }else if (line.readSensors() == 0110) {
    motors(100, 100);
  }/
   if (line.readSensors() == 0) {
    motors(100, 100);
  }else  if (line.readSensors() == 1) {
    motors(25, 100);
  }else  if (line.readSensors() == 2) {
    motors(100, 25);
  }else  if (line.readSensors() == 3) {
    motors(100, 100);
  }
}

void motors(int l, int r) {
  left.run(-l);
  right.run(r);
}
