#ifndef ES_H
#define ES_H
#include <thread>


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