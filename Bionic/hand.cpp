#include "hand.h"

Hand::Hand()
{

}

Hand::Hand(size_t _fingers, int _joints)
    :fingers(_fingers), joints(_joints)
{
    std::cout << "Create Hand" << std::endl;
}

Hand::~Hand()
{
    std::cout << "Destruct Hand" << std::endl;
}

void Hand::start()
{
    std::cout << "Start Hand" <<std::endl;

    std::cout << "Create Fingers" <<std::endl;
    fing.reserve(fingers);
    for(size_t n = 0; n < fingers; n++) {
        fing.emplace_back(std::make_shared<Finger>());
    }

    std::future<void> ftre = stopruning.get_future();
    handThr = std::thread(&Hand::run, this,std::move(ftre));
}

void Hand::stop()
{
    stopruning.set_value();
    handThr.join();
}

void Hand::run(std::future<void> ftre)
{
    std::cout << "Run thread!" <<std::endl;
    while(ftre.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
        close_hand();
        open_hand();
        move_finger();
    }
}

void Hand::move_finger()
{
    fing.at(0)->move();
}

void Hand::close_hand()
{
    for(size_t i = 0; i < fingers; i++) {
        fing.at(i)->move();
    }
}

void Hand::open_hand()
{
    for(size_t i = 0; i < fingers; i++) {
        fing.at(i)->move();
    }
}

