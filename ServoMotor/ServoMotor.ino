#include "ServoMotor.h"
#include <AFMotor.h> //arduino lib

AF_DCMotor motorL(2);
AF_DCMotor motorR(3);

ServoMotor::ServoMotor(uint8_t speed) {
  motorL.setSpeed(speed);
  motorR.setSpeed(speed);
}

void ServoMotor::moveForward() {
  motorL.run(FORWARD);
  motorR.run(FORWARD);
}

void ServoMotor::backUp() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(BACKWARD);
  delay(100);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::rightTurn() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(100);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::leftTurn() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(100);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::stop() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::spin() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(3000);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}