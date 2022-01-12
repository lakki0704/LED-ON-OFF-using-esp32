


#include <Stepper.h>

//const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 18, 12, 19, 13); //since its esp32 

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {

  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  
  myStepper.step(5); //5 steps clockwise (forward)
  delay(50);
  
  Serial.println("counterclockwise");
  myStepper.step(-10); //10 steps backward (anticlockwise)
  delay(50);
}
