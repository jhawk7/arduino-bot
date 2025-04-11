#ifndef Sonar_h
#define Sonar_h
#include <Servo.h> // arduino lib

class Sonar {
  private:
  static const int center = 60;
  static const int left = 160;
  static const int right = -50;
  static const float minDistance = 20.0; //cm
  Servo* servoPtr;
  int trigger;
  int echo;
  
  float check();
  float checkLeft();
  float checkRight();

  public:
  Sonar(int triggerPin, int echoPin, int servoPin);
  ~Sonar();
  String chooseDirection();
  bool isPathClear();
};

#endif