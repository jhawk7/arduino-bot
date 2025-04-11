#include "ServoMotor.h"

ServoMotor smotor(130);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println("moving forward..");
  smotor.moveForward();
  delay(5000);
  //Serial.println("backing up..");
  smotor.backUp();
  delay(5000);
  //
  smotor.turnAround();
  delay(5000);
  //Serial.println("turning left..");
  smotor.leftTurn();
  delay(5000);
  //Serial.println("turning right..");
  smotor.rightTurn();
  delay(5000);
  //Serial.println("spinning..");
  smotor.spin();
  delay(5000);
  //Serial.println("moving forward..");
  smotor.moveForward();
  delay(5000);
  //Serial.println("stopping..");
  smotor.stop();
  delay(5000);
}