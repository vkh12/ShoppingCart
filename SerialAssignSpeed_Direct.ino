#include <Stepper.h>

const int stepsPerRevolution = 255;
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11); //left motor
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7); //right motor
char data;

void setup() {
  Serial.begin(9600);
  Serial.println("To begin, set the speed (full speed: '1' or half speed: '2') and press [ENTER]."); //prints blank line in serial
  Serial.println("");//prints blank line in serial 
}

void loop() {
  if(Serial.available()) {data = Serial.read();}
  //speed
  if(data == '2') {Half();} //"Half" Speed
  if(data == '1') {Full();} // Full Speed
  //actions
  if(data == rturn) {Rturn();} // Right turn 
  if(data == lturn) {Lturn();} // Left turn 
  if(data == 'r'){Reverse();} //CCW rotation > Reverse
  if(data == 's') {data = 0;} //STOP all actions  

//function for half speed forward motion
void Half (){
  Serial.println("half speed"); //print in serial
  Serial.println("");//prints blank line in serial
  myStepper1.setSpeed(60); myStepper1.step(-stepsPerRevolution/100); //left motor
  myStepper2.setSpeed(60); myStepper2.step(stepsPerRevolution/100); //right motor
}

//function for full speed forward motion
void Full ()
{
  Serial.println("full speed"); //print in serial
  Serial.println(""); //prints blank line in serial
  myStepper1.setSpeed(60); myStepper1.step(-stepsPerRevolution); //left motor
  myStepper2.setSpeed(60); myStepper2.step(stepsPerRevolution); //right motor
 }
 
//function for reverse
void Reverse()
{
  Serial.println("reverse"); //print in serial
  Serial.println(""); //prints blank line in serial
  myStepper1.step(stepsPerRevolution); // reverse motion for left motor
  myStepper2.step(-stepsPerRevolution); // reverse motion for left motor
 }

//function for Right turn
void Rturn()
{
  Serial.println("right turn"); //print in serial
  Serial.println(""); //prints blank line in serial
  myStepper1.step(-stepsPerRevolution); // right turn motion
 }

//function for Left turn
void Lturn()
{
  Serial.println("left turn"); //print in serial
  Serial.println(""); //prints blank line in serial
  myStepper2.step(-stepsPerRevolution); // right turn motion
 }
 
