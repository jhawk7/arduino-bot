#include "Sonar.h"
#include "ServoMotor.h"

Sonar sonar(14, 15, 10);
ServoMotor servoMotor(200);

void setup() {
  servoMotor.moveForward();
}

void loop() {
  while (!sonar.isPathClear()) {
    recover();
  }
  servoMotor.moveForward();
}

void recover() {
  servoMotor.stop();
  delay(500);
  servoMotor.backUp();
  String dir = sonar.chooseDirection();

  if (dir == "left") {
    servoMotor.leftTurn();
  } else if (dir == "right") {
    servoMotor.rightTurn();
  } else {
    servoMotor.spin();
  }

  delay(500);
  return;
}








