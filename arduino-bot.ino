#include "sonar.h"
#include "ServoMotor.h"

Sonar* sonar;
ServoMotor* motor;
int stuck; 

void setup() {
  sonar = new Sonar(14,15,10);
  motor = new ServoMotor(130);
  stuck = 0;
  motor->moveForward();
}

void loop() {
  while (!sonar->isPathClear()) {
    stuck++;
    if (stuck == 2) {
      Serial.println("stuck; panicing!");
      panic();
      resetStuckCntr();
    }
    recover();
  }

  motor->moveForward();
}

void recover() {
  motor->stop();
  delay(500);
  motor->backUp();
  delay(500);
  Serial.println("obstruction detected; taking evasive manuevers..");
  String dir = sonar->chooseDirection();

  if (dir == "left") {
    resetStuckCntr();
    motor->leftTurn();
  } else if (dir == "right") {
    resetStuckCntr();
    motor->rightTurn();
  } else {
    motor->turnAround();
  }

  delay(500);
  return;
}

void panic() {
  motor->spin();
}

void resetStuckCntr() {
  stuck = 0;
}
