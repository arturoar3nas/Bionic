#ifndef SERVO_H
#define SERVO_H

#include <memory>
#include <iostream>
#include "PCA9685.h"

class Servo
{
public:
    Servo();
    void move();

private:
    std::shared_ptr<PCA9685> driver;
};

#endif // SERVO_H
