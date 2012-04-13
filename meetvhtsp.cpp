#include "meetvhtsp.h"

MeeTvHtsp::MeeTvHtsp(QObject *parent) :
    QHtsp(parent)
{
    connect(this, SIGNAL(dvrEntryAdded(QHtspDvrEntry*)), this, SLOT(emitDvrEntryAdded(QHtspDvrEntry*)));
    m_configurationManager  = new QNetworkConfigurationManager(this);
    m_authenticated = false;
}

void MeeTvHtsp::authenticate(QString username, QString password)
{
    m_username = username;
    m_password = password;

    QHtsp::authenticate(m_username, m_password);
    m_authenticated = true;
}

void MeeTvHtsp::connectToServer(QString clientName, QString clientVersion, uint preferredHtspVersion, QString hostName, quint16 port)
{
    m_clientName = clientName;
    m_clientVersion = clientVersion;
    m_preferredHtspVersion = preferredHtspVersion;
    m_hostName = hostName;
    m_port = port;

    _sessionConnect();
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

void MeeTvHtsp::_reconnect()
{
    if(m_authenticated)
        QHtsp::authenticate(m_username, m_password);

    disconnect(this, SIGNAL(connected()), this, SLOT(_reconnect()));
}

void MeeTvHtsp::_sessionConnect()
{
    QNetworkConfiguration configuration = m_configurationManager->defaultConfiguration();
    m_session = new QNetworkSession(configuration, this);

    connect(m_session, SIGNAL(closed()), this, SLOT(_sessionLost()));
    m_session->open();
    if(m_session->isOpen())
        _internalConnect();
    else
        connect(m_session, SIGNAL(stateChanged(QNetworkSession::State)), this, SLOT(_internalConnect()));
}

void MeeTvHtsp::_sessionLost()
{
    disconnectFromServer(false);
    m_session->deleteLater();
    if(m_configurationManager->isOnline())
    {
        _sessionReconnect();
    }
    else
    {
        m_session = 0;
    }
}

void MeeTvHtsp::_sessionReconnect()
{
    connect(this, SIGNAL(connected()), this, SLOT(_reconnect()));
    _sessionConnect();
}

MeeTvHtsp* MeeTvHtsp::m_instance = 0;
QMutex MeeTvHtsp::m_mutex;
