#include "tethread.h"

TeThread::TeThread(int msec, QObject *parent) :
    QThread(parent), m_miliseconds(msec)
{

}

void TeThread::run()
{
    while(true)
    {
        msleep(m_miliseconds);
        emit timeOut();
    }
}
