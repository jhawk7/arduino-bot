#include "ServoMotor.h"

ServoMotor smotor(200);

void setup() {
}

void loop() {
  smotor.moveForward();
  delay(1000);
  smotor.backUp();
  delay(1000);
  smotor.leftTurn();
  delay(1000);
  smotor.rightTurn();
  delay(1000);
  smotor.spin();
  delay(1000);
  smotor.moveForward();
  delay(1000);
  smotor.stop();
}