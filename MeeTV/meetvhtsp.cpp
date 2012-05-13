#include "meetvhtsp.h"

#include "meetvchannel.h"

MeeTvHtsp::MeeTvHtsp(QObject *parent) :
    QHtsp(parent), m_session(0)
{
    connect(this, SIGNAL(dvrEntryAdded(QHtspDvrEntry*)), this, SLOT(emitDvrEntryAdded(QHtspDvrEntry*)));
    m_configurationManager  = new QNetworkConfigurationManager(this);
    m_asyncEnabled = false;
    m_authenticated = false;
    m_isIdle = false;
}

bool MeeTvHtsp::isIdle()
{
    return m_isIdle;
}

void MeeTvHtsp::authenticate(QString username, QString password)
{
    m_username = username;
    m_password = password;

    QHtsp::authenticate(m_username, m_password);
    m_authenticated = true;
}

void MeeTvHtsp::connectFromIdle()
{
    _sessionReconnect();
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

void MeeTvHtsp::disconnectIdle()
{
    m_isIdle = true;
    disconnectFromServer(!m_asyncEnabled);
    disconnect(m_session, SIGNAL(closed()), this, SLOT(_sessionLost()));
    m_session->close();
}

void MeeTvHtsp::enableAsync()
{
    QHtsp::enableAsync();
    m_asyncEnabled = true;
}

QString MeeTvHtsp::getStreamUrl(MeeTvChannel *channel)
{
    return QString("http://%1:%2@%3:%4/stream/channelid/%5")
            .arg(m_username, m_password, m_hostName, QString::number(9981), QString::number(channel->id()));
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

void MeeTvHtsp::_monitorSync(QString method, QHtspMessage &message)
{
    if(method == "channelAdd")
    {
        m_monitorChannels->append(message.getInt64("channelId"));
    }
    else if(method == "dvrEntryAdd")
    {
        m_monitorDvrEntries->append(message.getInt64("id"));
    }
    else if(method == "tagAdd")
    {
        m_monitorTags->append(message.getInt64("tagId"));
    }
    else if(method == "initialSyncCompleted")
    {
        _updateLists();
        disconnect(m_connection, SIGNAL(invoke(QString,QHtspMessage&)), this, SLOT(_monitorSync(QString, QHtspMessage&)));
    }
}

void MeeTvHtsp::_reconnect()
{
    m_isIdle = false;
    if(m_authenticated)
        QHtsp::authenticate(m_username, m_password);

    if(m_asyncEnabled)
    {
        m_monitorChannels = new QList<int>();
        m_monitorDvrEntries = new QList<int>();
        m_monitorTags = new QList<int>();
        connect(m_connection, SIGNAL(invoke(QString,QHtspMessage&)), this, SLOT(_monitorSync(QString, QHtspMessage&)));
        QHtsp::enableAsync();
    }

    disconnect(this, SIGNAL(connected()), this, SLOT(_reconnect()));
}

void MeeTvHtsp::_sessionConnect()
{
    if(!m_session)
    {
        QNetworkConfiguration configuration = m_configurationManager->defaultConfiguration();
        m_session = new QNetworkSession(configuration, this);

        connect(m_session, SIGNAL(closed()), this, SLOT(_sessionLost()));
    }

    m_session->open();
    if(m_session->isOpen())
        _internalConnect();
    else
        connect(m_session, SIGNAL(stateChanged(QNetworkSession::State)), this, SLOT(_internalConnect()));
}

void MeeTvHtsp::_sessionLost()
{
    disconnectFromServer(!m_asyncEnabled);
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

void MeeTvHtsp::_updateLists()
{
    int i;
    for(i = 0; i < channels()->count(); i++)
    {
        QHtspChannel *channel = channels()->at(i);
        if(!m_monitorChannels->contains(channel->id()))
        {
            channels()->remove(channel);
            delete channel;
        }
    }

    for(i = 0; i < dvrEntries()->count(); i++)
    {
        QHtspDvrEntry *dvrEntry = dvrEntries()->at(i);
        if(!m_monitorDvrEntries->contains(dvrEntry->id()))
        {
            dvrEntries()->remove(dvrEntry);
            delete dvrEntry;
        }
    }

    for(i = 0; i < tags()->count(); i++)
    {
        QHtspTag *tag = tags()->at(i);
        if(!m_monitorTags->contains(tag->id()))
        {
            tags()->remove(tag);
            delete tag;
        }
    }

    delete m_monitorChannels;
    delete m_monitorDvrEntries;
    delete m_monitorTags;
    m_monitorChannels = 0;
    m_monitorDvrEntries = 0;
    m_monitorTags = 0;
}

MeeTvHtsp* MeeTvHtsp::m_instance = 0;
QMutex MeeTvHtsp::m_mutex;
