#include "Sonar.h"
#include <Servo.h> //arduino library

Sonar::Sonar(int triggerPin, int echoPin, int servoPin) {
  servo.attach(servoPin);
  trigger = triggerPin;
  echo = echoPin;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  servo.write(center);
}

String Sonar::chooseDirection() {
  float leftD = checkDirection(left);
  float rightD = checkDirection(right);

  if ((leftD >= rightD) && (leftD > minDistance)) {
    return "left";
  } else if ((rightD >= leftD) && (rightD > minDistance)) {
    return "right";
  } else {
    return "panic";
  }
}

bool Sonar::isPathClear() {
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
  Serial.println(distance);
  delay(100);
  return distance;
}

float Sonar::checkDirection(int direction) {
  servo.write(center);
  delay(15);
  servo.write(direction);
  float d = check();
  delay(15);
  servo.write(center);
  return d;
}