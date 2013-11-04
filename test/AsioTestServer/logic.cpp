#include "logic.h"
#include "server.h"

Logic::Logic()
{
}

Logic& Logic::getInstance()
{
    static Logic inst;
    return inst;
}

void Logic::processCoords(int clientId, int coordX, int coordY)
{
    _mutex.lock();

    //calculate physics


    _mutex.unlock();
}

void Logic::start()
{
    do
    {
        _mutex.lock();

        _shouldStop = frameFunc();

        _mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(_framePeriod));
    }
    while(!_shouldStop);
}

bool Logic::frameFunc()
{
    //being called each 1/framePeriod time

    //send changes to all clients
    Server::getInstance().sendData();

    return true;
}

bool Logic::shouldStop() const
{
    return _shouldStop;
}
