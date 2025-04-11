#include "Sonar.h"
#include <Servo.h> //arduino library

Sonar::Sonar(int triggerPin, int echoPin, int servoPin) {
  servoPtr = new Servo();
  servoPtr->attach(servoPin);
  trigger = triggerPin;
  echo = echoPin;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  servoPtr->write(center);
}

Sonar::~Sonar() {
  delete servoPtr;
}

String Sonar::chooseDirection() {
  Serial.println("checking available paths..");
  float leftD = checkDirection(left);
  float rightD = checkDirection(right);

  if ((leftD >= rightD) && (leftD > minDistance)) {
    return "left";
  } else if ((rightD >= leftD) && (rightD > minDistance)) {
    return "right";
  } else {
    return "around";
  }
}

bool Sonar::isPathClear() {
  Serial.println("checking path..");
  float d = check();
  delay(5);
  return d > minDistance;
}

float Sonar::check() {
  digitalWrite(trigger, LOW); //initializse trigger to low
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); // trigger is high for 10us
  digitalWrite(trigger, LOW);

  float duration = pulseIn(echo, HIGH); //gets duration that echoPin was high - echo pin goes high when the receiver receives a sound wave
  float distance = (duration * .0343) / 2; // d = v*t; our velocity is the speed of sound (cm/us) and the time is the duration /2 in us - sound travels to object and back 
  delay(100);
  return distance;
}

float Sonar::checkDirection(int direction) {
  servoPtr->write(center);
  delay(15);
  servoPtr->write(direction);
  float d = check();
  delay(15);
  servoPtr->write(center);
  return d;
}