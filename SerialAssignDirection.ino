#include <Stepper.h>

const int stepsPerRevolution = 255;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
char data;

void setup() {
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())

  {
    data = Serial.read();
  }
  
  if(data == 'f'){Forward();}//CW rotation > Forward
  if(data == 'r'){Reverse();}//CCW rotation > Reverse
  if(data == 's')//STOP motion
    {
      data = 0;
      
    }
}  

 //function for CW rotation
void Forward ()
{
  Serial.println("forward - CW"); //print in serial
  Serial.println("");//prints blank line in serial
  myStepper.step(stepsPerRevolution);// forward motion
}

//function for CCW rotation
void Reverse()
{
  Serial.println("reverse - CCW");//print in serial
  Serial.println("");//prints blank line in serial
  myStepper.step(-stepsPerRevolution);// reverse motion
 }
