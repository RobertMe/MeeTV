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
    m_clientName = clientName;
    m_clientVersion = clientVersion;
    m_preferredHtspVersion = preferredHtspVersion;
    m_hostName = hostName;
    m_port = port;

    m_session->open();
    if(m_session->isOpen())
        _internalConnect();
    else
        connect(m_session, SIGNAL(stateChanged(QNetworkSession::State)), this, SLOT(_internalConnect()));
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

void MeeTvHtsp::_internalConnect()
{
    if(m_session->state() != QNetworkSession::Connected)
        return;

    disconnect(m_session, SIGNAL(stateChanged(QNetworkSession::State)), this, SLOT(_internalConnect()));
    QHtsp::connectToServer(m_clientName, m_clientVersion, m_preferredHtspVersion, m_hostName, m_port);
}

MeeTvHtsp* MeeTvHtsp::m_instance = 0;
QMutex MeeTvHtsp::m_mutex;
