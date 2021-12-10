#include <MeMCore.h>
MeDCMotor motorLeft (M1);
MeDCMotor motorRight (M2);
MeRGBLed led (PORT_7);
MeLineFollower lineFinder (PORT_2);
MeUltrasonicSensor ultrasonic(PORT_4);
int d = 0;
int height=0;
int base =0;
int hypo=0;
int crosshypo=0;
int area=0;
int turnratio;
int left;
void motors(int l, int r) {
  motorLeft.run(-l);
  motorRight.run(r);
}
void better_turning(){
  d = ultrasonic.distanceCm();
  height = d;
  motors(38,75);
  delay(1000);
  d = ultrasonic.distanceCm();
  if (d>15){
    left =1;
    motors(75,38);
    delay(2000);
    d = ultrasonic.distanceCm();
  }
  base = d;
  area=0.5ab;
  hypo = sqrt((heightheight)+(basebase));
  crosshypo=area/hypo/0.5;
  turnratio=acos(crosshypo/base);
  if (left=1){
    motors(100, (1-turnratio)100);
    delay(1000);
  }
  else {
    motors((1-turnratio)100, 100);
    delay(1000);
  }
  motors(100,100);
  delay(crosshypo*200);
  motors(0,0)
  if (left=1){
    motors(90, 0);
    delay(1000);
  }
  else {
    motors(0, 90);
    delay(1000);
  }
}
void loop() {
  better_turning();
}
