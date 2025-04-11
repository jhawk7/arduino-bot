#include <AFMotor.h>
AF_DCMotor motor3(3);
//AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:
  motor3.setSpeed(130);
  //motor4.setSpeed(200);
  motor3.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t i;
  motor3.run(FORWARD);
  for (i=0; i<255; i++) {
    motor3.setSpeed(i);
    delay(10);
  }

  motor3.run(RELEASE);
  delay(5);

  motor3.run(BACKWARD);
  for(i=0; i<255; i++) {
    motor3.setSpeed(i);
    delay(10);
  }

  for (i=255; i>0; i--) {
    motor3.setSpeed(i);
    delay(10);
  }

  motor3.run(RELEASE);
  delay(10);
}
