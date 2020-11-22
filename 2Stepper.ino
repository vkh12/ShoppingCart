
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 512;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 8, 10, 9, 11); 
Stepper myStepper2(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
}

void loop() {
  if (millis()<1000){
    myStepper1.step(1);
    myStepper2.step(-1);
}

if (millis()>=1000 && millis()<2000) {
    myStepper1.step(1);
    myStepper2.step(1);
}

else{
  myStepper1.step(0);
    myStepper2.step(0);
}
}
