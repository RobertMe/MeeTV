#include "meetvhtsp.h"

#include <QNetworkConfigurationManager>

MeeTvHtsp::MeeTvHtsp(QObject *parent) :
    QHtsp(parent)
{
    connect(this, SIGNAL(dvrEntryAdded(QHtspDvrEntry*)), this, SLOT(emitDvrEntryAdded(QHtspDvrEntry*)));
    QNetworkConfigurationManager manager;
    QNetworkConfiguration configuration = manager.defaultConfiguration();
    m_session = new QNetworkSession(configuration, this);
}

void MeeTvHtsp::connectToServer(QString clientName, QString clientVersion, uint preferredHtspVersion, QString hostName, quint16 port)
{
    m_session->open();
    if(m_session->waitForOpened())
        QHtsp::connectToServer(clientName, clientVersion, preferredHtspVersion, hostName, port);
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
