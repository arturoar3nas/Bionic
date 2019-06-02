#include "servo.h"

Servo::Servo()
{
    driver = std::make_shared<PCA9685>(0,0); //! bus and addres
    driver->setPWM(1, 2000);
}

void Servo::move()
{
    driver->setPWMFreq(500);
    int ret = driver->getPWM(1);
    std::cout << "pwm: " << std::to_string(ret) << std::endl;
}
