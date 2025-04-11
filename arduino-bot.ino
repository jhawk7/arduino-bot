#include "Sonar.h"
#include "ServoMotor.h"

Sonar sonar(14, 15, 10);
ServoMotor servoMotor(130);
int stuck = 0;

void setup() {
  Serial.being(9600);
  servoMotor.moveForward();
}

void loop() {
  while (!sonar.isPathClear()) {
    stuck++;
    if (stuck == 2) {
      Serial.println("stuck; panicing!")
      panic();
      resetStuckCntr();
    }

    recover();
  }
  
  servoMotor.moveForward();
}

void recover() {
  servoMotor.stop();
  delay(500);
  servoMotor.backUp();
  Serial.println("obstruction detected; taking evasive manuevers..");
  String dir = sonar.chooseDirection();

  if (dir == "left") {
    resetStuckCntr();
    servoMotor.leftTurn();
  } else if (dir == "right") {
    resetStuckCntr();
    servoMotor.rightTurn();
  } else {
    servoMotor.turnAround();
  }

  delay(500);
  return;
}

void panic() {
  servoMotor.spin();
}

void resetStuckCntr() {
  stuck = 0;
}








