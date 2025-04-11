#include "Sonar.h"

Sonar sonar(14,15,10);

void setup() {
  Serial.begin(9600)
  Serial.println("starting");
}

void loop() {
  String dir = sonar.chooseDirection();
  Serial.println(dir);
  delay(3000);
}