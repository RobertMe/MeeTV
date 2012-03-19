#include "meetvhtsp.h"

MeeTvHtsp::MeeTvHtsp(QObject *parent) :
    QHtsp(parent)
{
    connect(this, SIGNAL(dvrEntryAdded(QHtspDvrEntry*)), this, SLOT(emitDvrEntryAdded(QHtspDvrEntry*)));
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

void MeeTvHtsp::emitDvrEntryAdded(QHtspDvrEntry *dvrEntry)
{
    emit dvrEntryAdded(new MeeTvDvrEntry(*dvrEntry));
}

MeeTvHtsp* MeeTvHtsp::m_instance = 0;
QMutex MeeTvHtsp::m_mutex;
