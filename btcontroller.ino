#include <MePS2.h>
#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MePS2 MePS2(PORT_5);

MeDCMotor motorLeft(M1);
MeDCMotor motorRight(M2);


void setup(){
  MePS2.begin(115200);
}

void motors(int left, int right){
  motorLeft.run(-left);
  motorRight.run(right);
}

void loop(){
  MePS2.loop();
  
  int left_updown = MePS2.MeAnalog(4);
  int left_leftright = MePS2.MeAnalog(2);
  
  motors(left_updown+left_leftright,left_updown-left_leftright);
  if(MePS2.ButtonPressed(9)){
    motors(150,-150);
    delay(500);
    motors(0,0);
  }
}
