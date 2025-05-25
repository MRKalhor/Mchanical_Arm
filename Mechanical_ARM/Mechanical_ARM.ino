#include <Servo.h>

Servo gripper, armdown, armup, rotator;

int CG = 0, CAU = 0, CAD = 0, CR = 0;
int speed = 20;

void setup() {
  //serial
  Serial.begin(9600);

  //motor
  gripper.attach(10);
  armdown.attach(6);
  armup.attach(5);
  rotator.attach(3);

  //led
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  //pose
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

  lowwrite(gripper, CG, 0, 'G');
  lowwrite(armdown, CAD, 0, 'D');
  lowwrite(armup, CAU, 0, 'U');
  lowwrite(rotator, CR, 0, 'R');
}

void firstPose() {
  digitalWrite(8, HIGH);

  lowwrite(gripper, CG, 90, 'G');
  lowwrite(armup, CAU, 90, 'U');
  lowwrite(armdown, CAD, 90, 'D');
  lowwrite(rotator, CR, 90, 'R');

  lowwrite(gripper, CG, 0, 'G');
}

void secondPose() {
  digitalWrite(9, HIGH);

  lowwrite(armup, CAU, 90, 'U');
  lowwrite(armdown, CAD, 90, 'D');
  lowwrite(rotator, CR, 0, 'R');
  lowwrite(gripper, CG, 0, 'G');
  lowwrite(armup, CAU, 0, 'U');
  lowwrite(armdown, CAD, 0, 'D');
}

void lowwrite(Servo& motor, int& local, int target, char label) {
  if (target > local) {

    for (int i = local; i <= target; i++) {

      motor.write(i);
      Serial.print(label);
      Serial.print(":");
      Serial.println(i);
      delay(speed);
    }

  } else {

    for (int i = local; i >= target; i--) {

      motor.write(i);
      Serial.print(label);
      Serial.print(":");
      Serial.println(i);
      delay(speed);
    }
  }
  local = target;
}
