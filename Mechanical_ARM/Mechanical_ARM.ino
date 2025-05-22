#include <Servo.h>
Servo gripper, armdown, armup, rotator;



void setup() {
  // put your setup code here, to run once:
  //servo motors
  gripper.attach(10);
  gripper.attach(10, 0, 120);

  armdown.attach(6);
  armdown.attach(6, 0, 120);

  armup.attach(5);
  armup.attach(5, 0, 120);

  rotator.attach(3);
  rotator.attach(3, 0, 360);
  startpose();

  //Leds
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
 
}

void loop() {
  
  delay(5000);
  firstPose();
  delay(5000);
  seconePose();
  delay(5000);
  startpose();
  dealay(1000);
   digitalWrite(0, LOW);
   digitalWrite(1, LOW); 
   digitalWrite(0, LOW); 
  

}
void startpose() {
  gripper.write(0);
  armdown.write(0);
  armup.write(0);
  rotator.write(0);
    digitalWrite(0, HIGH); 

}
void firstPose() {
  gripper.write(90);
  armdown.write(90);
  armup.write(90);
  rotator.write(90);
    digitalWrite(1, HIGH);  // turn the LED on (HIGH is the voltage level)

}
void seconePose() {
  gripper.write(120);
  armdown.write(120);
  armup.write(120);
  rotator.write(120);
    digitalWrite(2, HIGH);  // turn the LED on (HIGH is the voltage level)

}
