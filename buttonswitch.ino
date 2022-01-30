#include <MeMCore.h>

MeDCMotor motorLeft (M1);

MeDCMotor motorRight (M2);

MeBuzzer buzzer; int programNumber = 1;

void setup() { int startTimer = 0;

while (startTimer <2000) { if (analogRead(7) < 100) (

programNumber++;

buzzer.tone(600, 100);

delay(100);

startTimer = 0; }

startTimer++; delay(1);

}

void loop() {

if (programNumber == 1) { //PROGRAM 1 CODE HERE

motors (100, 100); delay(500);

motors (100, -100);

delay(500);

}

if (programNumber == 2) { //PROGRAM CODE 2 HERE

motors(-100, -100);

delay(500);

motors (-100, 100); delay(500);

}

}

void motors(int left, int right) { motorLeft.run(-left); motorRight.run(right);
