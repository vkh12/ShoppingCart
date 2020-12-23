#include <Stepper.h>

 //Defines a datatype named WheelVel that has the fields w(1 - 4)
 typedef struct
 {
   double w1;
   double w2;
   double w3;
   double w4;
 } WheelVel;

 //Defines a function that takes a pointer to a desired output WheelVel and desired velocities vx, vy, and wz.
 //Calculates the requisite angular velocities of each wheel using the robot's parameters and stores them in the output WheelVel to match.
 void calcWheelVels(WheelVel* output, double vx, double vy, double wz)
 {
   double r = 0.1;
   double lx = 0.5;
   double ly = 0.5;
   output->w1 = (1/r)*(vx-vy-(lx+ly)*wz);
   output->w2 = (1/r)*(vx+vy+(lx+ly)*wz);
   output->w3 = (1/r)*(vx+vy-(lx+ly)*wz);
   output->w4 = (1/r)*(vx-vy+(lx+ly)*wz);
   return;
 }

 //Sets a constant variable to store the steps per revolution for the particular stepper motor being used
 //Creates two stepper motors with the specified parameters.
 const int stepsPerRevolution = 255;
 Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11); 
 Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7); 
 Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);

 double* calcWheelVels(double vx, double vy, double wz){
 double r = 0.1;
 double lx = 0.5;
 double ly = 0.5;
 double w1=(1/r)*(vx-vy-(lx+ly)*wz);
 double w2=(1/r)*(vx+vy+(lx+ly)*wz);
 double w3=(1/r)*(vx+vy-(lx+ly)*wz);
 double w4=(1/r)*(vx-vy+(lx+ly)*wz);}
 //Initializes a WheelVel with all 0 data. This will contain the resultant wheel velocities eventually. Might want to malloc and free this depending on amount of available memory.
 //This could also be defined in the loop, which might be better depending on how it's going to be used.
 WheelVel result = {0.0, 0.0, 0.0, 0.0};

 void setup() {
 //Opens serial and turns the motors one revolution at a specified speed.
 void setup() 
 {
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
 //Does whatever this code is supposed to do.
 void loop()
 {  
   //Initializes desired velocities to zero. In the final code, this program will have to grab data from somewhere else (maybe serial) to put as the values.
   double vx = 0.0, vy = 0.0, wz = 0.0;

   //Calls the previously defined function to modify our result variable to contain the desired values.
   calcWheelVels(&result, vx, vy, wz);

   //In the final code, the data will have to be used to do something, such as move the motors. That would go around here.
   //It might also need to be sent somewhere, or printed to serial for testing purposes.

   //Including an unconditional break so there isn't an infinite loop. In the final code, this will have to trigger conditionally with whatever you'd like the stop condition to be.
   //Might also want to implement some wait time after one loop iteration so that WheelVel updates at some determined frequency, or only after the motors have finished moving.
   break;
 }
