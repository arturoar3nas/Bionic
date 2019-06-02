#include <iostream>
#include "hand.h"

int main()
{
    std::cout << "bionic arm version 1.0.0.1" << std::endl;

    size_t fingers = 1;
    int joints = 1;
    Hand hand(fingers, joints);
    hand.start();

    while(true)
    {
        //! check by status hand
        //! check by battery
        //! check by another things
    }

    return 0;
}
