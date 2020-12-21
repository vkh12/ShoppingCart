#include <Stepper.h>

const int stepsPerRevolution = 255;
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11); 
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7); 

double* calcWheelVels(double vx, double vy, double wz){
double r = 0.1;
double lx = 0.5;
double ly = 0.5;
double w1=(1/r)*(vx-vy-(lx+ly)*wz);
double w2=(1/r)*(vx+vy+(lx+ly)*wz);
double w3=(1/r)*(vx+vy-(lx+ly)*wz);
double w4=(1/r)*(vx-vy+(lx+ly)*wz);}

void setup() {
  Serial.begin(9600);
  myStepper1.setSpeed(60); myStepper1.step(stepsPerRevolution);
  myStepper2.setSpeed(60); myStepper2.step(stepsPerRevolution);
}

void loop() {
  struct WheelVel{
  double w1;
  double w2;
  double w3;
  double w4;
  }

WheelVel result();
  result.w1=w1;
  result.w2=w2;
  result.w3=w3;
  result.w4=w4;
  return result;
};
  
