#include "ServoMotor.h"
#include <AFMotor.h> //arduino lin

AF_DCMotor motorL(2);
AF_DCMotor motorR(3);

ServoMotor::ServoMotor(uint8_t speed) {
  motorL.setSpeed(speed-22); // left motor is running faster
  motorR.setSpeed(speed);
}

void ServoMotor::moveForward() {
  Serial.println("moving forward..");
  motorL.run(FORWARD);
  motorR.run(FORWARD);
}

void ServoMotor::backUp() {
  Serial.println("backing up..");
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(BACKWARD);
  delay(1000);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::rightTurn() {
  Serial.println("turning right..");
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(250);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::leftTurn() {
  Serial.println("turning left..");
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(250);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::turnAround() {
  Serial.println("turning around..");
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(500);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::stop() {
  Serial.println("stopping..");
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(5);
}

void ServoMotor::spin() {
  Serial.println("spinning..");
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