#include "Sonar.h"
using namespace std;

Sonar sonar(14,15,10);

void setup() {
}

void loop() {
  String dir = sonar.chooseDirection();
  Serial.println(dir);
  delay(3000);
}