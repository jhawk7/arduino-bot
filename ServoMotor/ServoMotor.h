#ifndef ServoMotor_h
#define ServoMotor_h

class ServoMotor {
  public:
  ServoMotor(uint8_t speed);
  void moveForward();
  void backUp();
  void stop();
  void rightTurn();
  void leftTurn();
  void spin();
};

#endif