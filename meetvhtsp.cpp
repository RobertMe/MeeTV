#include "meetvhtsp.h"

MeeTvHtsp::MeeTvHtsp(QObject *parent) :
    QHtsp(parent)
{
}

MeeTvHtsp *MeeTvHtsp::instance()
{
    if(!m_instance)
    {
        m_mutex.lock();

        if(!m_instance)
            m_instance = new MeeTvHtsp();

        m_mutex.unlock();
    }

    return m_instance;
}

MeeTvHtsp* MeeTvHtsp::m_instance = 0;
QMutex MeeTvHtsp::m_mutex;
