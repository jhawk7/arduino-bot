#include "Sonar.h"

Sonar* sonar;

void setup() {
  Serial.begin(9600);
  Serial.println("starting");
  sonar = new Sonar(14,15,10);
}

void loop() {
  String dir = sonar->chooseDirection();
  Serial.println(dir);
  delay(3000);
}