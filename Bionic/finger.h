#ifndef FINGER_H
#define FINGER_H

#include <memory>
#include <vector>
#include <iostream>
#include "servo.h"

class Finger
{
public:
    Finger(size_t _servos);
    Finger();
    void move();

    size_t getServos() const;
    void setServos(const size_t &value);

private:
    size_t servos;
    std::vector<std::shared_ptr<Servo>> servo;
};

#endif // FINGER_H
