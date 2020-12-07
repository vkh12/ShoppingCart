#include <Stepper.h>

const int stepsPerRevolution = 255;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
char data;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())

  {
    data = Serial.read();
  }
  
  if(data == '2'){Half();}//CW rotation > Forward
  if(data == '1'){Full();}//CCW rotation > Reverse
  if(data == '0')//STOP motion
    {
      data = 0;
      
    }
}    
void Half (){
  Serial.println("half speed"); //print in serial
  Serial.println("");//prints blank line in serial
  myStepper.setSpeed(60);//assign half speed
  myStepper.step(stepsPerRevolution/80);// forward motion
}

void Full ()//function for CCW rotation
{
  Serial.println("full speed");//print in serial
  Serial.println("");//prints blank line in serial
  myStepper.setSpeed(60);//assign full speed
  myStepper.step(stepsPerRevolution);// forward motion
 }
