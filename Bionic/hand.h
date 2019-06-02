#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include <memory>
#include <stdint.h>
#include <future>
#include "finger.h"

class Hand
{
public:
    Hand();
    Hand(size_t _fingers, int _joints);
    ~Hand();
    void start();
    void stop();


private:
    size_t fingers;
    int joints;

    std::vector<std::shared_ptr<Finger>> fing;

    std::thread handThr;
    std::promise<void> stopruning;

    void run(std::future<void> futureObj);
    void move_finger();
    void close_hand();
    void open_hand();
};

#endif // HAND_H
