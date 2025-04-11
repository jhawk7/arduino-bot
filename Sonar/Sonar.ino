#include "Sonar.h"
#include <Servo.h> //arduino library

Sonar::Sonar(int triggerPin, int echoPin, int servoPin) {
  servoPtr = new Servo();
  servoPtr->attach(servoPin);
  trigger = triggerPin;
  echo = echoPin;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoPtr->write(center);
}

Sonar::~Sonar() {
  delete servoPtr;
}

String Sonar::chooseDirection() {
  Serial.println("checking left..");
  float leftD = checkLeft();
  delay(1000);
  Serial.println("checking right..");
  float rightD = checkRight();

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
  Serial.print("cm: ");
  Serial.println(distance);
  return distance;
}

float Sonar::checkRight() {
  for (int i = center; i > right; i--) {
    servoPtr->write(i);
    delay(5);
  }

  float d = check();
  delay(1000);
  for (int i = right; i < center; i++) {
    servoPtr->write(i);
    delay(5);
  }
  return d;
}

float Sonar::checkLeft() {
  for (int i = center; i < left; i++) {
    servoPtr->write(i);
    delay(5);
  }

  float d = check();
  delay(1000);
  for (int i = left; i > center; i--) {
    servoPtr->write(i);
    delay(5);
  }

  return d;
}