#include <Stepper.h>

//Defines a datatype named WheelVel that has the fields w(1 - 4)
typedef struct{
    double w1;
    double w2;
    double w3;
    double w4;
} WheelVel;

typedef struct{
  double x;
  double y;
  double w;
} Vec3;

typedef struct{
    Vec3 pos;
    Vec3 vel; 
} RobotState;

//Sets a constant variable to store the steps per revolution for the particular stepper motor being used
//Creates two stepper motors with the specified parameters.
const int stepsPerRevolution = 255;
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11); 
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7); 

//Initializes a WheelVel with all 0 data. This will contain the resultant wheel velocities eventually. Might want to malloc and free this depending on amount of available memory.
//This could also be defined in the loop, which might be better depending on how it's going to be used.
WheelVel wheelVel = {0.0, 0.0, 0.0, 0.0};
RobotState currentState = {{0.0,0.0,0.0},{0.0,0.0,0.0}};
RobotState desiredState = {{0.0,0.0,0.0},{0.0,0.0,0.0}};
RobotState control = {{0.0,0.0,0.0},{0.0,0.0,0.0}};

// Parses incoming RPi data, i.e. current state, desired state
// Assume the RPi sends x,y,theta measured from the Vicon and x,y,theta desired from the planner
void parseInput(String& input){
    // TODO: Decide on a communication format for RPi<->Arduino
    // Might want to be flexible here in how we parse data, so RPi can send data as it gets it
    // instead of trying to send it all at once. Kalman filter can have multiple (async) updates
    // so we can update state/var estimates as we get new data.
    //
    // Get current state from input string
    // viconState = ...
    // Update Kalman filter based on Vicon data
    // updateKalman(...)
    //
    // Get desired state from input string, only changes control setpoint
    // desiredState = ...
}

// Read on-board sensors for state estimates
void readSensors(){
    // TODO: Figure out IMU hookup for robot, probably need to move to Mega for the extra pins
    // accel = ...
    // orient = ...
    //
    // Update Kalman filter based on on-board sensor data
    //  updateKalman(...)
}

// Kalman update step with given data (e.g. on-board IMU, Vicon, etc.)
// Should be called by parseInput or readSensor so updates are done as data comes in
// and not all at once
void updateKalman(){
    // K = PH'inv(HPH'+R)
    // x = x+K(z-Hx)
    // P = (I-KH)P
    // kalmanGain = ...
    // kalmanState = ...
    // kalmanCovariance = ...
}

// Take Vicon/IMU
void predictKalman(){
    // State prediction using Kalman filter
    // x = Fx+Bu
    // P = FPF'+Q
    // currentState = ...
    // kalmanCovariance = ...
}

void calcControlInputs(){
    // (Predictive?) controller goes here
    // Probably some sort of MPC
}

//Defines a function that takes a pointer to a desired output WheelVel and desired velocities vx, vy, and wz.
//Calculates the requisite angular velocities of each wheel using the robot's parameters and stores them in the output WheelVel to match.
void calcWheelVels(WheelVel* output, double vx, double vy, double wz){
    double r = 0.1;
    double lx = 0.5;
    double ly = 0.5;
    output->w1 = (1/r)*(vx-vy-(lx+ly)*wz);
    output->w2 = (1/r)*(vx+vy+(lx+ly)*wz);
    output->w3 = (1/r)*(vx+vy-(lx+ly)*wz);
    output->w4 = (1/r)*(vx-vy+(lx+ly)*wz);
}

void moveWheels(WheelVel* vels, unsigned long& remainingTime){
    // Rotate wheels based on calculated velocities
    // step() blocks, so some modifications are necessary here
    // Probably just do enough steps across all wheels to fill remainingTime
    // Time it takes to one-step all four = sum of 1.0/(steps/rev*rev/min) for each motor
    // Number of 4 motor steps = whatever time's left / time it takes to one-step all four (rounded down to int)
    // for(int turnStep = 0; turnStep<numFourMotorSteps; turnStep++){
        // w1motor.setSpeed(4*vels->w1);
        // w1motor.step();
        // w2motor.setSpeed(4*vels->w2);
        // w2motor.step();
        // w3motor.setSpeed(4*vels->w3);
        // w3motor.step();
        // w4motor.setSpeed(4*vels->w4);
        // w4motor.step();
    // }
    // Or something like that...
}

//Opens serial and turns the motors one revolution at a specified speed.
void setup(){
    Serial.begin(9600);
    myStepper1.setSpeed(60); myStepper1.step(stepsPerRevolution);
    myStepper2.setSpeed(60); myStepper2.step(stepsPerRevolution);

    // Initialize controller vars
    
}

// Handles robot control loop:
// 1. Read RPi/sensor inputs
// 2. Update internal state estimates
// 3. Calculate control input from state estimates
// 4. Convert control inputs to motor rpms
// 5. Send rpm commands to motors
void loop(){

    unsigned long loopStart_us = micros();
    unsigned long loopTarget_ms = 10; // 100Hz -> 10ms/loop
    unsigned long loopTarget_us = 1000*loopTarget_ms; // 100Hz -> 10000us/loop
    
    // Check if Raspberry Pi sent over any data
    while(Serial.available()){
        // Incoming data should be read line-by-line
        usbInput = Serial.readStringUntil("\n");
        // Parse incoming data into desired pos & vel
        parseInput(usbInput);
    }

    // Read on-board sensors (IMU, etc.)
    readSensors();

    // Update robot state estimate
    kalmanPredict();

    // Calculate control inputs based on Kalman state prediction
    calcControlInputs();
    
    // Calculate wheel velocities needed to match control inputs
    calcWheelVels(&wheelVel, &control.vel.x, &contorl.vel.y, &control.vel.w);

    unsigned long loopRemaining_us = loopTarget_us - (micros()-loopStart_us);
    // Set wheel velocities through Stepper library
    moveWheels(&wheelVel,loopRemaining_us);

    // No need to break out here, Arduino will call loop() again regardless... So a stop condition is meaningless.
    // But if you insist on waiting, you could sleep for a while, in milliseconds:
    // delay(1);
}
