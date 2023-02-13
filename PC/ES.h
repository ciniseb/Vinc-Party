#ifndef ES_H
#define ES_H
#include <thread>

#define BOUTON 1
#define ACCEL 2
#define JOYSTICK 3


class ES
{
private:
    std::thread es_thread(ES::exec);
public:
    ES();
    ~ES();
    void exec();
};


#endif