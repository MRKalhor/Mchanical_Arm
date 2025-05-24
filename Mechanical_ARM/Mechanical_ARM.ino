#include <Servo.h>

Servo gripper, armdown, armup, rotator;

// current positions
int CG = 0, CAU = 0, CAD = 0, CR = 0;

void setup() {
  gripper.attach(10, 0, 120);
  armdown.attach(6, 0, 120);
  armup.attach(5, 0, 120);
  rotator.attach(3, 0, 360);

  // LEDs
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  startpose();
}

void loop() {
  delay(500);
  firstPose();
  delay(1000);
  secondPose();
  delay(1000);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void startpose() {
  digitalWrite(7, HIGH);

  lowwrite(gripper, CG, 0);
  lowwrite(armdown, CAD, 0);
  lowwrite(armup, CAU, 0);
  lowwrite(rotator, CR, 0);
}

void firstPose() {
  digitalWrite(8, HIGH);

  lowwrite(gripper, CG, 90);

  lowwrite(armup, CAU, 90);
  lowwrite(armdown, CAD, 90);

  lowwrite(rotator, CR, 90);

  lowwrite(armup, CAU, 90);  
  lowwrite(armdown, CAD, 90);

  lowwrite(gripper, CG, 0);
}

void secondPose() {
  digitalWrite(9, HIGH);

  lowwrite(armup, CAU, 90);
  lowwrite(armdown, CAD, 90);

  lowwrite(rotator, CR, 0);

  lowwrite(gripper, CG, 0);

  lowwrite(armup, CAU, 0);
  lowwrite(armdown, CAD, 0);
}

void lowwrite(Servo& motor, int& local, int rotate) {
  if (rotate > local) {
    for (int i = local; i <= rotate; i++) {
      motor.write(i);
      delay(10);
    }
  } else {
    for (int i = local; i >= rotate; i--) {
      motor.write(i);
      delay(10);
    }
  }
  local = rotate;
}
