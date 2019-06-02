#include "finger.h"

Finger::Finger(size_t _servos)
        : servos(_servos)
{
    std::cout << "Create a finger whit " << servos << " servos" << std::endl;
    servo.reserve(servos);
    for(size_t n = 0; n < servos; n++) {
        servo.emplace_back(std::make_shared<Servo>());
    }
}

Finger::Finger()
{

}

void Finger::move()
{
    servo.at(0)->move();
}

size_t Finger::getServos() const
{
    return servos;
}

void Finger::setServos(const size_t &value)
{
    servos = value;
}

